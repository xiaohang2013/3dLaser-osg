#ifndef GEOMETRYMATH_H
#define GEOMETRYMATH_H

#include "pcgmath.h"
#include "parameter.h"
#include "quadtreenode.h"

#include <osg/ref_ptr>
#include <osg/Array>
#include <osg/Matrix>
#include <osg/BoundingBox>

class geometryMath: public pcgMath
{
    Q_OBJECT

public:
    /** Axis XYZ enum map*/
    enum Axis
    {
        /** Axis X.*/
        AXISX = 0,
        /** Axis Y.*/
        AXISY = 1,
        /** Axis Z.*/
        AXISZ = 2
    };

public:
    geometryMath();
    ~geometryMath();

    osg::Vec3Array *buildPolygonToPointCloud1(const osg::Vec3Array* polygon, ordinaryParameter op, osg::BoundingBox bbox);
    osg::Vec3Array *buildTrianglesArrayToPointCloud1(const osg::Vec3Array* polygons, ordinaryParameter op, osg::BoundingBox bbox);
    osg::Vec3Array *buildPolygonToPointCloud2(const osg::Vec3Array* rawPolygon, ordinaryParameter op);
    osg::Vec3Array *buildTrianglesArrayToPointCloud2(const osg::Vec3Array* polygons, ordinaryParameter op);

    osg::Vec3Array *buildLineToPointCloud(osg::Vec3 &p1, osg::Vec3 &p2, float pDisInLine, bool unifyByCoord=true);
    osg::Vec3Array *buildLinesArrayToPointCloud(osg::Vec3Array *lines, float pDisInLine, bool unifyByCoord=true);

private:
//    float random(float Xi);//混合同余法(Mixed congruential method)生成0~1随机数
    osg::Vec3Array *adaptPolygon(const osg::Vec3Array *polygon);
    osg::Vec3 getXAxisofPolygon(const osg::Vec3Array *polygon);
    osg::Vec3 getYAxisofPolygon(const osg::Vec3Array *polygon);
    osg::Vec3 getNormalofPolygon(const osg::Vec3Array *polygon, bool reverse = false);
    osg::Vec3 getNormalizedCrossProduct(const osg::Vec3 v1, const osg::Vec3 v2, bool reverse=false);//单位化的两向量叉积
    osg::Matrix getTransformMatrixofPolygon(const osg::Vec3Array *polygon);
    osg::Vec2 transform3DPointTo2D(const osg::Vec3 point, const osg::Matrix *matrix);
    bool isPointIn3DPolygon(const osg::Vec3Array *polygon,const osg::Vec3 testPoint);
    bool isPointIn2DPolygon(const osg::Vec2Array *polygon,const osg::Vec2 testPoint);

private:
    float getAngleof2Vectors(const osg::Vec3 v1, const osg::Vec3 v2);
    float getMaxCoordValue(const osg::Vec3Array *vertices, Axis axis);
    float getMinCoordValue(const osg::Vec3Array *vertices, Axis axis);
    osg::Vec3Array *getIntersectionofFaceWithSpecialPlane(const osg::Vec3Array *polygon, Axis axis, float coordValue);
    osg::Vec3Array *getDiscretePointsOnLine(const osg::Vec3Array *line, const osg::Vec3Array *polygon,
                                            Axis muteAxis, float pDisInFace, float pDisSide, PointSpreadType pointType,
                                            osg::Vec3 verticalVector, bool needDeviation, float pDisInMuteAxis, osg::BoundingBox bbox,
                                            float pDeviationInXY=0.f, float pDeviationInZ=0.f);
    osg::Vec3 getInnerPointOnLine(const osg::Vec3 p1, const osg::Vec3 p2, float ratio);

    Axis getMuteAxis(const osg::Vec3Array *polygon, float XYThresholdInDegree, float ZThresholdInDegree);

private:
    bool checkPointDistance(const osg::Vec3 point, osg::BoundingBox bbox, float zResolution,float radius);


public:
    void init_QuadTree();// 初始化四叉树及释放内存


private:
    typedef std::map<int, QuadTreeNode *> QuadTreeDictionary;
    QuadTreeDictionary quadTreesDict;

};

#endif // GEOMETRYMATH_H
