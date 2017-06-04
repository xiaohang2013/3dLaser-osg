#include "geometrymath.h"
#include "pcgexception.h"
#include <math.h>
#include <qmath.h>

#ifndef M_DEGREEPERRAD
#define M_DEGREEPERRAD (57.2957795130823208768)
#endif

geometryMath::geometryMath()
{
    init_QuadTree();
}

geometryMath::~geometryMath()
{
    init_QuadTree();
}


/**
 * Function: 生成多边形面片的点云 之方法一，基于面片法线方向与世界坐标轴的关系生成
 *
*/
osg::Vec3Array *geometryMath::buildPolygonToPointCloud1(const osg::Vec3Array *polygon, ordinaryParameter op, osg::BoundingBox bbox)
{
    unsigned int size=polygon->size();
    if(size<3)
        throw (PolygonVertexNumMismatch("生成点云时，图元中一个多边形的给定顶点数（<3）不正确。"));

    osg::ref_ptr<osg::Vec3Array> points=new osg::Vec3Array;

    float pDisInFace=op.pointDisInFace;//面点距
    float pDisSide=op.pointDisSide;//规则侧距 或 Z向间距

    if(pDisInFace<1e-7)
        throw (ValueErrorException("面点距设置错误，必须大于0"));
    if(pDisSide<1e-7)
        throw (ValueErrorException("侧间距设置错误，必须大于0"));


    bool isRandomA = op.pointSpreadType==RANDOMA;
    bool isRandomB = op.pointSpreadType==RANDOMB;
    bool isRectangleA = op.pointSpreadType==RECTANGLEA;//规则矩形点型
    bool isRectangleB = op.pointSpreadType==RECTANGLEB;//自由矩形点型
    bool isDiamondA = op.pointSpreadType==DIAMONDA;//规则菱形点型
    bool isDiamondB = op.pointSpreadType==DIAMONDB;//自由菱形点型
    // 调整间距，使得各种点型的点云间距基本一致
    if(isDiamondA || isDiamondB || isRandomA)
    {
        pDisInFace *= sqrt(2);
        pDisSide *= sqrt(2);
    }

    //确定面片与哪个坐标轴最接近平行，评判优先级 Z-X-Y;确定哑轴
    float ZThresholdInDegree = 35.f;
    float XYThresholdInDegree = 30.f;
    if(isDiamondA || isRectangleA)
    {
        ZThresholdInDegree = 35.f;
        XYThresholdInDegree = 45.f;
    }
    else if(isRandomA || isRandomB)
    {
        ZThresholdInDegree = 0.f;
        XYThresholdInDegree = 45.f;
    }
    Axis muteAxis = getMuteAxis(polygon, XYThresholdInDegree, ZThresholdInDegree);

    //*************************************************************
    //该段是为了处理侧点距（Z向浓度）大于点间距导致的点云不均匀（分片）现象
    //当前只对随机点云的生成起作用
    if((isRandomA || isRandomB) && pDisSide>pDisInFace)
    {
        osg::Vec3 norm = getNormalofPolygon(polygon);
        float angleWithZAxis = getAngleof2Vectors(norm, osg::Vec3(0.f,0.f,1.f));
        float ZDiff = abs(angleWithZAxis-90);
        pDisSide -= (ZDiff/90.f)*(pDisSide-pDisInFace);
    }
    //*************************************************************


    float pDisInMuteAxis = 0.0f;//哑轴方向切片距离
    if(isDiamondA || isDiamondB || isRandomA)
    {
        if(muteAxis == AXISZ) pDisInMuteAxis = pDisSide*0.5f;
        else pDisInMuteAxis = pDisInFace*0.5f;
    }
    else
    {
        if(muteAxis == AXISZ) pDisInMuteAxis = pDisSide;
        else pDisInMuteAxis = pDisInFace;
    }

    float minValue=getMinCoordValue(polygon,muteAxis);
    float maxValue=getMaxCoordValue(polygon,muteAxis);
    float small = pDisInMuteAxis/100.0;//微小偏移，暂取百分之一的间距
    int min=ceil(minValue/pDisInMuteAxis-small);//上圆整，加入微小偏移是为了防止舍入误差导致点云“小漏洞”
    int max=floor(maxValue/pDisInMuteAxis+small);//下圆整，加入微小偏移是为了防止舍入误差导致点云“小漏洞”
    int i = min;
    // 沿哑轴切三维多边形得线段，然后离散点
    //for(int i=min; i<=max; ++i)
    for(float muteCoord=min*pDisInMuteAxis; muteCoord<=maxValue; i++)
    {
        float pointDeviationInXY = 0.f;//哑轴导致的在X或Y向点偏离
        float pointDeviationInZ = 0.f;//哑轴导致的在Z向点偏离
        bool needDeviation = true;
        if(isRandomA || isRandomB) //随机AB:自由菱形基础上加入随机元素
        {
            pointDeviationInXY = pDisInFace * (abs(i)%2)*0.5f;
            pointDeviationInZ = pDisSide * (abs(i)%2)*0.5f;
            needDeviation = abs(i)%2==1;
        }
        else if(isDiamondA || isDiamondB) //分奇偶层:奇数层需要偏离,偶数层不需要
        {
            pointDeviationInXY = pDisInFace * (abs(i)%2)*0.5f;
            pointDeviationInZ = pDisSide * (abs(i)%2)*0.5f;
            needDeviation = abs(i)%2==1;
        }
        else needDeviation=false;

        osg::ref_ptr<osg::Vec3Array> line = getIntersectionofFaceWithSpecialPlane(polygon, muteAxis,/*i*pDisInMuteAxis*/muteCoord);
        muteCoord += pDisInMuteAxis;
        //**************************************
        osg::Vec3 verticalVector(0.f,0.f,0.f);
//        if(isRandomA || isRandomB)
        {
            if(line->size()==2)
            {
                osg::Vec3 linetemp = line->at(1)-line->at(0);
                osg::Vec3 norm = getNormalofPolygon(polygon,false);
                verticalVector = getNormalizedCrossProduct(linetemp, norm);
            }
        }
        //***************************************
        osg::ref_ptr<osg::Vec3Array> tempPoints = getDiscretePointsOnLine(line.get(), polygon, muteAxis, pDisInFace,
                                                                          pDisSide, op.pointSpreadType, verticalVector,
                                                                          needDeviation, pDisInMuteAxis, bbox, pointDeviationInXY,
                                                                          pointDeviationInZ);
        if(tempPoints && tempPoints->size()>0)
            points->insert(points->end(),tempPoints->begin(),tempPoints->end());
    }

    return points.release();
}

/**
 * Function: 将多边形序列生成对应点云之方法一
 *
*/
osg::Vec3Array *geometryMath::buildTrianglesArrayToPointCloud1(const osg::Vec3Array *polygons, ordinaryParameter op, osg::BoundingBox bbox)
{
    osg::ref_ptr<osg::Vec3Array> points=new osg::Vec3Array;
    unsigned int count = (polygons->size()/3)*3;//3的倍数
    for(unsigned int i=0; i<count; i+=3)
    {
        osg::ref_ptr<osg::Vec3Array> triangle=new osg::Vec3Array;
        triangle->push_back(osg::Vec3(polygons->at(i)));
        triangle->push_back(osg::Vec3(polygons->at(i+1)));
        triangle->push_back(osg::Vec3(polygons->at(i+2)));

//        osg::Vec3 norm = getNormalofPolygon(triangle.get());
//        float angleWithZAxis = getAngleof2Vectors(norm, osg::Vec3(0.f,0.f,1.f));
//        if(angleWithZAxis>=89) continue;

        osg::ref_ptr<osg::Vec3Array> tempPoints = buildPolygonToPointCloud1(triangle.get(),op, bbox);
        if(tempPoints && tempPoints->size()>0)
            points->insert(points->end(),tempPoints->begin(),tempPoints->end());
    }
    return points.release();
}

/**
 * Function: 生成多边形面片的点云 之方法二，面加点，以面片某一条边线为基准生成
 *
*/
osg::Vec3Array *geometryMath::buildPolygonToPointCloud2(const osg::Vec3Array *rawPolygon, ordinaryParameter op)
{
    unsigned int size=rawPolygon->size();
    if(size<3)
        throw (PolygonVertexNumMismatch("生成点云时，图元中一个多边形的给定顶点数（<3）不正确。"));

    osg::ref_ptr<osg::Vec3Array> polygon = adaptPolygon(rawPolygon);
    osg::ref_ptr<osg::Vec3Array> points=new osg::Vec3Array;

    //float pDisInLine=op.pointDisInLine;
    float pDisInFace=op.pointDisInFace;
    //float pDisSide=op.pointDisSide;
    //float pDisInZDir=op.pointDisInZDir;

    init_Random(3333);
    float pDisX=pDisInFace;//多边形面内横向点间距
    float pDisY=pDisX;//多边形面内纵向点间距
    float ran=normalizedRand();
    float firstLayerYDeviation = ran * pDisY;//首层纵向偏离
    float layerXDeviation = 0.f;//每层横向偏离
    osg::Vec3 XDir=getXAxisofPolygon(polygon);
    osg::Vec3 YDir=getYAxisofPolygon(polygon);

    /********************************************
     * 建立该多边形的局部坐标系，并转换为二维多边形
     ********************************************/
    //建立局部坐标系，并求取局部至世界坐标系转换矩阵
    osg::Matrix M=getTransformMatrixofPolygon(polygon);
    //M逆矩阵，即 世界坐标系至局部坐标系的转换矩阵
    osg::Matrix Minv(osg::Matrix::inverse(M));
    osg::ref_ptr<osg::Vec2Array> polygon2D=new osg::Vec2Array;
    for(unsigned int i=0;i<polygon->size(); ++i)
    {
        osg::Vec2 p_2L = transform3DPointTo2D(polygon->at(i), &Minv);
        polygon2D->push_back(p_2L);
    }

    /********************************************
     * 按规则生成点
     ********************************************/
    osg::Vec3 pStart=polygon->at(0);
    osg::Vec3 pEnd=polygon->at(1);
    osg::Vec3 XIncVector = XDir * pDisX;//横向点间距生成X向固定矢量增量
    osg::Vec3 YIncVector = YDir * pDisY;//纵向点间距生成Y向固定矢量增量
    bool toTop=false;//到达顶部，结束
    pStart += YDir * firstLayerYDeviation + XDir * layerXDeviation;
    pEnd += YDir * firstLayerYDeviation + XDir * layerXDeviation;
    while(!toTop)
    {
        if((pEnd-pStart)*XDir<0)
            break;

        //寻找该行的多边形面片首个外点1（该点下一点是内点）
        while(!isPointIn2DPolygon(polygon2D.get(),transform3DPointTo2D(pStart, &Minv)))
        {
            if((pEnd-pStart)*XDir<0)
            {
                toTop=true;
                break;
            }
            else pStart += XIncVector;
        }
        if(toTop) break;
        while(isPointIn2DPolygon(polygon2D.get(),transform3DPointTo2D(pStart, &Minv)))
            pStart -= XIncVector;

        //寻找该行的多边形面片首个外点2（该点后续点均为外点了）
        while(!isPointIn2DPolygon(polygon2D.get(),transform3DPointTo2D(pEnd, &Minv)))
        {
            if((pEnd-pStart)*XDir<0)
            {
                toTop=true;
                break;
            }
            else pEnd -= XIncVector;
        }
        if(toTop) break;
        while(isPointIn2DPolygon(polygon2D.get(),transform3DPointTo2D(pEnd, &Minv)))
            pEnd += XIncVector;

        //校正首末点
        //if(!isPointIn2DPolygon(polygon2D.get(),transform3DPointTo2D(pStart + XIncVector*0.5f, &Minv)))
            pStart += XIncVector;
        //if(!isPointIn2DPolygon(polygon2D.get(),transform3DPointTo2D(pEnd - XIncVector*0.5f, &Minv)))
            pEnd -= XIncVector;

        //记录点
        float length=(pEnd-pStart).length();
        for(unsigned int i=0; length>=0; length-=pDisX,++i)
            points->push_back(pStart + XIncVector * i);

        if(isPointIn2DPolygon(polygon2D.get(),transform3DPointTo2D(pStart - XIncVector*0.5f, &Minv)))
            points->push_back(pStart - XIncVector*0.5f);
        if(isPointIn2DPolygon(polygon2D.get(),transform3DPointTo2D(pEnd + XIncVector*0.5f, &Minv)))
            points->push_back(pEnd + XIncVector*0.5f);
        //points->insert(points->end(),polygon->begin(),polygon->end());//多边形自身顶点

        //准备下一次循环
        switch(op.pointSpreadType)
        {
            case RANDOMA|RANDOMB:
                ran = normalizedRand();
                layerXDeviation = pDisX * ran;
                break;
            case RECTANGLEA:
                layerXDeviation = 0.f;
                break;
            case DIAMONDA:
                layerXDeviation = 0.5f;
                break;
            default:
                break;
        }

        pStart += YIncVector + XDir * layerXDeviation;
        pEnd += YIncVector + XDir * layerXDeviation;

    }

    return points.release();
}

/**
 * Function: 将多边形序列生成对应点云之方法二
 *
*/
osg::Vec3Array *geometryMath::buildTrianglesArrayToPointCloud2(const osg::Vec3Array *polygons, ordinaryParameter op)
{
    osg::ref_ptr<osg::Vec3Array> points=new osg::Vec3Array;
    unsigned int count = (polygons->size()/3)*3;//3的倍数
    for(unsigned int i=0; i<count; i+=3)
    {
        osg::ref_ptr<osg::Vec3Array> triangle=new osg::Vec3Array;
        triangle->push_back(osg::Vec3(polygons->at(i)));
        triangle->push_back(osg::Vec3(polygons->at(i+1)));
        triangle->push_back(osg::Vec3(polygons->at(i+2)));
        osg::ref_ptr<osg::Vec3Array> tempPoints=buildPolygonToPointCloud2(triangle.get(),op);
        if(tempPoints && tempPoints->size()>0)
            points->insert(points->end(),tempPoints->begin(),tempPoints->end());
    }
    return points.release();
}


/**
 * Function: 生成线段上点云（线加点）
 *      参数: p1,p2,线段两端点
 *      参数: unifyByCoord=true，根据端点xyz坐标大小统一化起始和末端点，防止公共线段重复生成导致点错移
*/
osg::Vec3Array *geometryMath::buildLineToPointCloud(osg::Vec3 &p1, osg::Vec3 &p2, float pDisInLine, bool unifyByCoord)
{
    if(pDisInLine<1e-7)
        throw (ValueErrorException("线点距设置错误，必须大于0"));

    osg::Vec3 pStart(p1);
    osg::Vec3 pEnd(p2);
    if(unifyByCoord)
    {
        if(!(p1<p2))
        {
            pStart=p2;
            pEnd=p1;
        }
    }

    osg::ref_ptr<osg::Vec3Array> points=new osg::Vec3Array;
    osg::Vec3 direction=pEnd-pStart;
    float len = direction.length();
    float defaultDeviationAtStart = 0.5f * pDisInLine;
    float deviation = defaultDeviationAtStart/len;
    float unitDeviation = pDisInLine/len;//单位偏离（0-1）
    for(unsigned int i=0; deviation<=1.0f; ++i)
    {
        points->push_back(osg::Vec3(pStart + direction*deviation));
        deviation+=unitDeviation;
    }
    return points.release();
}

osg::Vec3Array *geometryMath::buildLinesArrayToPointCloud(osg::Vec3Array *lines, float pDisInLine, bool unifyByCoord)
{
    if(pDisInLine<1e-7)
        throw (ValueErrorException("线点距设置错误，必须大于0"));

    osg::ref_ptr<osg::Vec3Array> points=new osg::Vec3Array;
    unsigned int count = (lines->size()/2)*2;//2的倍数
    for(unsigned int i=0; i<count; i+=2)
    {
        osg::ref_ptr<osg::Vec3Array> tempPoints=buildLineToPointCloud(lines->at(i),lines->at(i+1),pDisInLine,unifyByCoord);
        if(tempPoints && tempPoints->size()>0)
            points->insert(points->end(),tempPoints->begin(),tempPoints->end());
    }
    return points.release();
}


/**
 * Function: 混合同余法生成0~1之间随机数
 * 参数：Xi：输入种子，范围0~1
*/
//float geometryMath::random(float Xi)
//{
//    // X_(n+1) = mod(A*X_n+C,M);
//    // Y_n = X_n/M;
//    int A=2045;
//    double C=1.0f;
//    int M=1048576;//2的20次方
//    int seed= int(Xi*M);
//    float Xtemp = fmod(A*seed+C,(double)M);
//    float Xo = Xtemp/M;
//    return Xo;
//}

/**
 * Function: 按规则调整多边形
 *      规则:使得多边形顶点数组的前两点构成的边是多边形的最长边
*/
osg::Vec3Array *geometryMath::adaptPolygon(const osg::Vec3Array *polygon)
{
    osg::ref_ptr<osg::Vec3Array> plg=new osg::Vec3Array;
    unsigned int size=polygon->size();
    unsigned int index1=size-1;
    unsigned int index2=0;
    osg::Vec3 v1=polygon->at(index1);
    osg::Vec3 v2=polygon->at(index2);
    float maxLen=(v2-v1).length();
    for(unsigned int i=0; i<size; ++i)
    {
        v1 = polygon->at(i);
        v2 = i==size-1? polygon->at(0):polygon->at(i+1);
        float len=(v2-v1).length();
        if(len>maxLen)
        {
            maxLen=len;
            index1 = i;
            index2 = i==size-1? 0:i+1;
        }
    }
    plg->push_back(polygon->at(index1));
    plg->push_back(polygon->at(index2));
    for(unsigned int i=0; i<size; ++i)
    {
        if(i!=index1 && i!=index2)
            plg->push_back(polygon->at(i));
    }
    return plg.release();
}

/**
 * Function: 计算多边形局部坐标系的X轴
 * 规则：由多边形第一点指向第二点
*/
osg::Vec3 geometryMath::getXAxisofPolygon(const osg::Vec3Array *polygon)
{
    osg::Vec3 Xaxis(polygon->at(1)-polygon->at(0));
    Xaxis.normalize();
    return Xaxis;
}

/**
 * Function: 计算多边形局部坐标系的Y轴
 * 规则：ZAxis ^ XAxis
*/
osg::Vec3 geometryMath::getYAxisofPolygon(const osg::Vec3Array *polygon)
{
    osg::Vec3 Zaxis=getNormalofPolygon(polygon);
    osg::Vec3 Xaxis=getXAxisofPolygon(polygon);
    osg::Vec3 Yaxis=Zaxis^Xaxis;
    Yaxis.normalize();
    return Yaxis;
}

/**
 * Function: 生成多边形面片的法线，方向1-2-3-...右手定则
 * 参数：polygon：多边形顶点数组
 * reverse:是否反转法线
*/
osg::Vec3 geometryMath::getNormalofPolygon(const osg::Vec3Array *polygon, bool reverse)
{
    osg::Vec3 ab(polygon->at(1)-polygon->at(0));
    osg::Vec3 bc(polygon->at(2)-polygon->at(1));
    osg::Vec3 norm = getNormalizedCrossProduct(ab,bc,reverse);
    return norm;
}

/**
 * Function: 获取单位化的两向量叉积
 * 参数：polygon：多边形顶点数组
 * reverse:是否反转法线
*/
osg::Vec3 geometryMath::getNormalizedCrossProduct(const osg::Vec3 v1, const osg::Vec3 v2, bool reverse)
{
    osg::Vec3 v(v1^v2);
    v.normalize();
    if(reverse) v = -v;
    return v;
}

/**
 * Function: 建立多边形面片的局部坐标系，获取局部坐标系到父坐标系的转换矩阵
 * 注：该局部坐标系建立规则：以第1个顶点为坐标原点，矢量1-2为X轴，面片法线为Z轴
 * 参数：polygon：多边形顶点数组
*/
osg::Matrix geometryMath::getTransformMatrixofPolygon(const osg::Vec3Array *polygon)
{
    osg::Matrix m;

    //单位化的坐标轴
    osg::Vec3 Zaxis=getNormalofPolygon(polygon);
    osg::Vec3 Xaxis=getXAxisofPolygon(polygon);
    osg::Vec3 Yaxis=getYAxisofPolygon(polygon);
    osg::Vec3 home=polygon->at(0);//原点
    m.set(Xaxis.x(),Xaxis.y(),Xaxis.z(),0.,
          Yaxis.x(),Yaxis.y(),Yaxis.z(),0.,
          Zaxis.x(),Zaxis.y(),Zaxis.z(),0.,
          home.x(), home.y(), home.z(), 1.);
    return m;

}

/**
 * Function: 根据三维空间中平面的局部坐标系至世界坐标系的转换矩阵的
 * 逆矩阵，将该平面上的世界坐标系下的三维点，转换至局部坐标系的二维点
 * 参数：point:世界坐标系下的待转换三维点
 *      matrix:三维空间平面的局部坐标系至世界坐标系的转换矩阵的 逆矩阵
*/
osg::Vec2 geometryMath::transform3DPointTo2D(const osg::Vec3 point, const osg::Matrix *matrix)
{
    osg::Vec4 p_4W(point,1.0);
    osg::Vec4 p_4L = p_4W * *(matrix);//坐标， 世界 转到 局部
    osg::Vec2 p_2L(p_4L.x(),p_4L.y());
    return p_2L;
}

/**
 * Function: 三维空间中，测试点是否在多边形内
 * 参数：polygon：给定三维空间中的多边形面片
 *      testPoint：三维待测试点
*/
bool geometryMath::isPointIn3DPolygon(const osg::Vec3Array *polygon, const osg::Vec3 testPoint)
{
    //建立局部坐标系，并求取局部至世界坐标系转换矩阵
    osg::Matrix M=getTransformMatrixofPolygon(polygon);
    //M逆矩阵，即 世界坐标系至局部坐标系的转换矩阵
    osg::Matrix Minv(osg::Matrix::inverse(M));

    //坐标， 世界 转到 局部
    osg::Vec2 tp_2L = transform3DPointTo2D(testPoint, &Minv);
    osg::ref_ptr<osg::Vec2Array> polygon2D=new osg::Vec2Array;
    for(unsigned int i=0;i<polygon->size(); ++i)
    {
        osg::Vec2 p_2L = transform3DPointTo2D(polygon->at(i), &Minv);
        polygon2D->push_back(p_2L);
    }
    return isPointIn2DPolygon(polygon2D.get(),tp_2L);
}

/**
 * Function:二维平面内，判断点是否在多边形内
 *      参数：polygon：给定二维多边形
 *           testPoint：待测试点
*/
bool geometryMath::isPointIn2DPolygon(const osg::Vec2Array *polygon, const osg::Vec2 testPoint)
{
    uint i,j=polygon->size()-1;
    bool oddNodes=false;
    osg::Vec2 tp=testPoint;
    for(i=0;i<polygon->size();i++)
    {
        osg::Vec2 pi=polygon->at(i);
        osg::Vec2 pj=polygon->at(j);
        if((pi.y()<tp.y()&&pj.y()>=tp.y()
            || pi.y()>=tp.y()&&pj.y()<tp.y())
                && (pi.x()<=tp.x() || pj.x()<=tp.x()))
        {
            oddNodes^=(pi.x()+(tp.y()-pi.y())/(pj.y()-pi.y())*(pj.x()-pi.x())<tp.x());
        }
        j=i;
    }
    return oddNodes;
}

float geometryMath::getAngleof2Vectors(const osg::Vec3 v1, const osg::Vec3 v2)
{
    float c=(v1*v2)/(v1.length()*v2.length());
    if(c>1.0f) c=1.0f;
    else if(c<-1.0f) c=-1.0f;
    return acos(c) * M_DEGREEPERRAD;
}

/**
 * Function: 获取多边形或顶点数组在axis坐标轴方向上的最大坐标值
 *
*/
float geometryMath::getMaxCoordValue(const osg::Vec3Array *vertices, geometryMath::Axis axis)
{
    osg::Vec3 v(vertices->at(0));
    float max=v._v[axis];
    for(unsigned int i=0; i<vertices->size(); ++i)
    {
        v=vertices->at(i);
        if(v._v[axis]>max) max = v._v[axis];
    }
    return max;
}

/**
 * Function: 获取多边形或顶点数组在axis坐标轴方向上的最小坐标值
 *
*/
float geometryMath::getMinCoordValue(const osg::Vec3Array *vertices, geometryMath::Axis axis)
{
    osg::Vec3 v(vertices->at(0));
    float min=v._v[axis];
    for(unsigned int i=0; i<vertices->size(); ++i)
    {
        v=vertices->at(i);
        if(v._v[axis]<min) min = v._v[axis];
    }
    return min;
}

/**
 * Function: 获取特殊平面与多边形的交元素，主要用于求交线，该特殊平面是 与坐标系某个面平行的平面
 *
*/
osg::Vec3Array *geometryMath::getIntersectionofFaceWithSpecialPlane(const osg::Vec3Array *polygon, geometryMath::Axis axis, float coordValue)
{
    osg::ref_ptr<osg::Vec3Array> result=new osg::Vec3Array;

    float max = getMaxCoordValue(polygon, axis);
    float min = getMinCoordValue(polygon, axis);
    if(coordValue<min || coordValue>max) return result.release();//不相交

    std::vector<unsigned int> index;
    for(unsigned int i=0; i<polygon->size(); ++i)
    {
        osg::Vec3 v(polygon->at(i));
        if(abs(v._v[axis]-coordValue)<1e-7)//值相等
        {
            result->push_back(v);
            index.push_back(i);
        }
    }

    unsigned int count = result->size();
    unsigned int size = polygon->size();
    // =2：多边形一条边在该特殊平面上；  >2:面面重合；
    if(count>=2)
        return result.release();
    // 两面仅交于一点 或 多边形的一个顶点恰好位于两面的交线上
    else if(count==1)
    {
        for(unsigned int i=0; i<size; ++i)
        {
            int j=(i+1)%size;
            if(i!=index.at(0) && j!=index.at(0))
            {
                osg::Vec3 v1(polygon->at(i));
                osg::Vec3 v2(polygon->at(j));
                //这条判断也可不加，只是下面发生除0运算，得到1.#INF无穷大值
                //然而，不会报错。紧接着下面的判断(>1)就会生效
                if(abs(v2._v[axis]-v1._v[axis])<1e-7)//仅交于一点
                    return result.release();
                float ratio = abs(coordValue-v1._v[axis])/abs(v2._v[axis]-v1._v[axis]);
                //仅交于一点
                if(ratio>1) continue;

                result->push_back(getInnerPointOnLine(v1,v2,ratio));
            }
        }
        return result.release();
    }
    // 两面有一交线，且多边形面片没有顶点落在该交线上
    else
    {
        for(unsigned int i=0; i<size; ++i)
        {
            int j=(i+1)%size;
            osg::Vec3 v1(polygon->at(i));
            osg::Vec3 v2(polygon->at(j));
            if((coordValue-v1._v[axis])*(coordValue-v2._v[axis])<0)
            {
                float ratio = abs(coordValue-v1._v[axis])/abs(v2._v[axis]-v1._v[axis]);
                if(ratio>1) continue;//预防性判断，该条件不会发生。。
                result->push_back(getInnerPointOnLine(v1,v2,ratio));
            }
        }
        return result.release();
    }


}

/**
 * Function: 获取交线上的离散点
 *      规则：严格按照世界坐标系下沿某个坐标轴的点距进行离散
 *  参数line：交线，正常应为两个点；若仅有1个点，则为单个交点； 若3个点及以上，则为交面
 *  polygon: 交线所在的多边形
 *  muteAixs：哑轴，即 line中的该轴坐标值均相同，该线即为哑轴垂面与原多边形平面的交线
 *  pDisInFace: 面点距，用于确定线上离散点的点距离
 *  pDisSide: 规则侧距或Z向点距
 *  pointType: 点型
 *  verticalVector: 多边形面内纵向矢量，该矢量垂直于面法线及当前线段，从而作为生成随机点时的离散方向
 *  needDeviation: 是否需要线内统一偏离
 *  pDeviationInXY: XY方向的偏离值
 *  pDeviationInZ: Z方向的偏离值
*/
osg::Vec3Array *geometryMath::getDiscretePointsOnLine(const osg::Vec3Array *line, const osg::Vec3Array *polygon,
                                                      geometryMath::Axis muteAxis, float pDisInFace, float pDisSide,
                                                      PointSpreadType pointType, osg::Vec3 verticalVector, bool needDeviation, float pDisInMuteAxis, osg::BoundingBox bbox,
                                                      float pDeviationInXY, float pDeviationInZ)
{
    if(pDisInFace<1e-7)
        throw (ValueErrorException("面点距设置错误，必须大于0"));

    unsigned int size = line->size();
    osg::ref_ptr<osg::Vec3Array> points=new osg::Vec3Array;
    //空
    if(size<=0) return points.release();
    //仅一个点
    else if(size==1)
    {
        points->push_back(line->at(0));
        return points.release();
    }
    //正常的交线
    else if(size==2)
    {
        osg::Vec3 v1(line->at(0));
        osg::Vec3 v2(line->at(1));
        //未退化的两个坐标轴方向的投影长度
        float projLen[2] = {0.f,0.f};
        Axis axis[2];
        int j=0;
        for(int i=0; i<3; ++i)
        {
            if(i!=muteAxis)
            {
                projLen[j]=abs(v2._v[i]-v1._v[i]);
                axis[j]=(Axis)i;
                ++j;
            }
        }

        bool isRandomA = pointType==RANDOMA;
        bool isRandomB = pointType==RANDOMB;
        bool isRectangleA = pointType==RECTANGLEA;//规则方形
        bool isRectangleB = pointType==RECTANGLEB;//自由方形
        bool isDiamondA = pointType==DIAMONDA;//规则菱形
        bool isDiamondB = pointType==DIAMONDB;//自由菱形

        osg::Vec3 hVector = v2-v1;  hVector.normalize();
        float V_ZAxisAngle = getAngleof2Vectors(verticalVector, osg::Vec3(0.f,0.f,1.f));
        float H_ZAxisAngle = getAngleof2Vectors(hVector, osg::Vec3(0.f,0.f,1.f));
        bool isVAlongZ = V_ZAxisAngle<30.f || V_ZAxisAngle>150.f;
        bool isHAlongZ = H_ZAxisAngle<30.f || H_ZAxisAngle>150.f;

        // 取未退化的两坐标轴方向有较大投影的坐标轴方向为增量坐标轴
        // 除哑轴和增量轴之外的轴即为自由轴
        Axis increAxis = projLen[0]>=projLen[1]?axis[0]:axis[1];
        Axis freeAxis = axis[0]!=increAxis? axis[0]:axis[1];//自由轴
        float pDeviationInIncreeAxis = increAxis==AXISZ? pDeviationInZ:pDeviationInXY;
        float pDisInIncreAxis = increAxis==AXISZ? pDisSide : pDisInFace;
        if(isDiamondA || isRectangleA) pDisInIncreAxis = pDisInFace;/*注意：
        该语句可以使得按照规则菱形和规则矩形的点型生成点云时，投射面上的点更丰富逼真，对整个模型上的点采样更密集；
        缺点是：如此密集的采集点投射后会密集而规则地分布在投射面上，很多的点将叠加在一起，导致点云量很大；
        因此，最后需要对叠加在一起的点云进行处理，降低点云数量*/

        //该段是为了处理侧点距（Z向浓度）大于点间距导致的点云不均匀（分片）现象
        //当前只对随机点云的生成起作用
        if((isRandomA || isRandomB) && pDisSide>pDisInFace)
        {
            float hZDiff = abs(H_ZAxisAngle-90);
            pDisInIncreAxis = pDisInFace + (hZDiff/90.f)*(pDisSide-pDisInFace);
        }

        float minValue = getMinCoordValue(line,increAxis);
        float maxValue = getMaxCoordValue(line,increAxis);
        float small = pDisInIncreAxis/100.0;
        int min = ceil((minValue-pDeviationInIncreeAxis)/pDisInIncreAxis-small);//上圆整，加入微小偏移是为了防止舍入误差导致点云“小漏洞”
        int max = floor((maxValue-pDeviationInIncreeAxis)/pDisInIncreAxis+small);//下圆整，加入微小偏移是为了防止舍入误差导致点云“小漏洞”
        // 沿增量轴对线段离散点，并对所得点的自由轴坐标做处理
        for(int i=min; i<=max; ++i)
        {
            float coordValueInIncreAxis = i*pDisInIncreAxis + pDeviationInIncreeAxis;
            float ratio = abs(coordValueInIncreAxis-v1._v[increAxis])/abs(v2._v[increAxis]-v1._v[increAxis]);
            if(ratio>1) continue;//预防性判断，该条件不会发生。。
            osg::Vec3 v = getInnerPointOnLine(v1,v2,ratio);

            float pDisInfreeAxisRegular = 0.f;
            pDisInfreeAxisRegular = freeAxis==AXISZ? pDisSide : pDisInFace;
            float pDisInIncreAxisRegular = increAxis==AXISZ? pDisSide : pDisInFace;//pDisInIncreAxis For Regular Point Type规则点型
            if(isDiamondA)//规则菱形
            {
                float pDeviationInfreeAxis = 0.f;
                if(needDeviation) pDeviationInfreeAxis = freeAxis==AXISZ? pDeviationInZ : pDeviationInXY;
                int pIndexInfreeAxis = round((v._v[freeAxis]-pDeviationInfreeAxis)/pDisInfreeAxisRegular);
                int pIndexInincreAxis = round((v._v[increAxis]-pDeviationInIncreeAxis)/pDisInIncreAxisRegular);
                int pIndexInmuteAxis = round(v._v[muteAxis]/pDisInMuteAxis);
                v._v[freeAxis] = pIndexInfreeAxis*pDisInfreeAxisRegular+pDeviationInfreeAxis;
                v._v[increAxis] = pIndexInincreAxis*pDisInIncreAxisRegular+pDeviationInIncreeAxis;
                v._v[muteAxis] = pIndexInmuteAxis*pDisInMuteAxis;
            }
            else if(isRectangleA)//规则方形
            {
                int pIndexInfreeAxis = round(v._v[freeAxis]/pDisInfreeAxisRegular);
                int pIndexInincreAxis = round(v._v[increAxis]/pDisInIncreAxisRegular);
                int pIndexInmuteAxis = round(v._v[muteAxis]/pDisInMuteAxis);
                v._v[freeAxis] = pIndexInfreeAxis*pDisInfreeAxisRegular;
                v._v[increAxis] = pIndexInincreAxis*pDisInIncreAxisRegular;
                v._v[muteAxis] = pIndexInmuteAxis*pDisInMuteAxis;
            }

            // !!!!!!!!!!!!!! 点云过滤后再插入 !!!!!!!!!!!!!!!!!!!!!!
            float zResolution = 0.1f;//点云过滤的Z向分层距离（分辨率）
            float radius = 0.5f*pDisInFace;//点云过滤的半径
            if(isRandomA || isRandomB)//随机AB
            {
                float factor = 1.f;//随机偏移的影响因子
                factor = isRandomA? 0.4f : isRandomB?0.8f:0.f;
                // 垂线方向随机
                float ran = 0.f;
                if(!isVAlongZ)
                    ran = (normalizedRand() - 0.5f)*pDisInFace*factor;//*factor,缩小该分量的随机偏移影响
                else
                    ran = (normalizedRand() - 0.5f)*pDisSide*factor;
                osg::Vec3 vtemp = v + verticalVector*ran;

                // 沿线方向随机
                if(!isHAlongZ)
                    ran = (normalizedRand() - 0.5f)*pDisInFace*factor;
                else
                    ran = (normalizedRand() - 0.5f)*pDisSide*factor;
                vtemp = vtemp+hVector*ran;

                //点云过滤后再插入
                if(isPointIn3DPolygon(polygon, vtemp) && checkPointDistance(vtemp, bbox, zResolution, radius))
                    points->push_back(vtemp);
                else if(checkPointDistance(v, bbox, zResolution, radius))
                    points->push_back(v);
            }
            else if(checkPointDistance(v, bbox, zResolution, radius))
                points->push_back(v);
        }

        return points.release();
    }
    //交面，正常情况下不应出现该情况
    else
    {
        for(unsigned int i=0; i<size; ++i)
        {
            unsigned int j=(i+1)%size;
            osg::ref_ptr<osg::Vec3Array> tempLine=new osg::Vec3Array;
            tempLine->push_back(line->at(i));
            tempLine->push_back(line->at(j));
            osg::ref_ptr<osg::Vec3Array> tempPoints=getDiscretePointsOnLine(tempLine.get(), polygon, muteAxis,
                                                                            pDisInFace, pDisSide, pointType, verticalVector, needDeviation,
                                                                            pDisInMuteAxis, bbox, pDeviationInXY, pDeviationInZ);
            points->insert(points->end(),tempPoints->begin(),tempPoints->end());
        }
        return points.release();
    }
}

/**
 * Function: 根据比例获取线段p1-p2上的内点，比例值为0时获取到的是p1,比例值为1时获取到的是p2
 *
*/
osg::Vec3 geometryMath::getInnerPointOnLine(const osg::Vec3 p1, const osg::Vec3 p2, float ratio)
{
    return p1+(p2-p1)*ratio;
}

/**
 * Function: 计算哑轴
 *
*/
geometryMath::Axis geometryMath::getMuteAxis(const osg::Vec3Array* polygon, float XYThresholdInDegree, float ZThresholdInDegree)
{
    osg::Vec3 norm = getNormalofPolygon(polygon);
    float angleWithZAxis = getAngleof2Vectors(norm, osg::Vec3(0.f,0.f,1.f));
    float angleWithXAxis = getAngleof2Vectors(norm, osg::Vec3(1.f,0.f,0.f));
    float angleWithYAxis = getAngleof2Vectors(norm, osg::Vec3(0.f,1.f,0.f));
    float ZDiff = abs(angleWithZAxis-90);
    float XDiff = abs(angleWithXAxis-90);
    float YDiff = abs(angleWithYAxis-90);
    Axis muteAxis = AXISZ;
//    if(ZDiff<=ZThresholdInDegree || (ZDiff<=XDiff && ZDiff<=YDiff)) muteAxis = AXISZ;
//    else if(XDiff<=XYThresholdInDegree || (XDiff<=YDiff && XDiff<=ZDiff)) muteAxis = AXISX;
//    else muteAxis = AXISY;

    if(XDiff<=XYThresholdInDegree || (XDiff<=YDiff && XDiff<=ZDiff)) muteAxis = AXISX;
    else if(YDiff<=XYThresholdInDegree || (YDiff<=XDiff && YDiff<=ZDiff)) muteAxis = AXISY;
    else muteAxis = AXISZ;

    return muteAxis;
}

bool geometryMath::checkPointDistance(const osg::Vec3 point, osg::BoundingBox bbox, float zResolution, float radius)
{
    if(radius<=0.f || zResolution<=0.f) return false;
    float xyResolution = 45*radius;
    float width = bbox.xMax()-bbox.xMin();
    float height = bbox.yMax()-bbox.yMin();
    float len = width>=height?width:height;
    float startX = bbox.center().x()-0.5f*len;
    float startY = bbox.center().y()-0.5f*len;
    int maxLevel = floor(log(len/xyResolution)/log(2));
    if(maxLevel<1) maxLevel = 1;
    QuadTreeNode *quadTree;

//    float zResolution = 0.08f;
    int zIndex = ceil((point.z()-0.5f*zResolution)/zResolution);
    if(quadTreesDict.find(zIndex)==quadTreesDict.end())//尚不存在节点
    {
        quadTree = new QuadTreeNode(startX, startY, len, len, 1, maxLevel,QuadTreeNode::ROOT,nullptr);
        quadTreesDict[zIndex] = quadTree;
    }
    else
        quadTree = quadTreesDict[zIndex];
    bool isOK = quadTree->insertPoint(point, radius);

    return isOK;
}

/// 初始化四叉树及释放内存
void geometryMath::init_QuadTree()
{
    QuadTreeDictionary::iterator it;
    for(it = quadTreesDict.begin(); it != quadTreesDict.end(); ++it)
    {
        delete it->second;
        it->second = nullptr;
    }
    quadTreesDict.clear();
}





