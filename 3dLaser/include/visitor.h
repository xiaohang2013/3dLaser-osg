/*
 * Date: 2016.10.23
 * By: Liu
 * Function: Derived class from NodeVisitor. Used to go through osg's nodes.
 * */

#ifndef VISITOR
#define VISITOR

#include <osg/NodeVisitor>
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/ref_ptr>
#include <osg/Switch>
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osg/TriangleFunctor>
#include <osgText/Text3D>
#include "linefunctor.h"


#include <QString>



/**
 * Function: 查找给定名称的节点
*/
class findNamedNodeList : public osg::NodeVisitor
{
public:
    findNamedNodeList(const std::string& name="", TraversalMode tm = osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
        :osg::NodeVisitor( tm),// 默认遍历所有子节点
        _name(name){}

    /*  NodeVisitor的原理：
     *  如果重载的apply()中的形参类型为osg::Node的子类型，则进入子类型的apply（对号入座）而不进入osg::Node的apply;
     *  反之，如果没有osg::Node的子类型apply，则进入osg::Node的apply执行。
     */



    // 这个方法将调用场景功能图形中的每个节点，
    // 检查其名称是否符合输入的要求。
    // 如果符合的话，将保存节点的地址
    virtual void apply(osg::Node &node)
    {
        if(node.getName()==_name)
            _nodeList.push_back(&node);

        // 继续遍历场景图形剩余的部分(父类inline函数，直接推进本访问器继续访问)
        traverse(node);
    }

    virtual void apply(osg::Geode &geode)
    {
        if(geode.getName()==_name)
            _geodeList.push_back(&geode);
        apply((osg::Node&)geode);

        //traverse(geode);
    }

    virtual void apply(osg::Group &group)
    {
        if(group.getName()==_name)
            _groupList.push_back(&group);
        apply((osg::Node&)group);

        //traverse(group);
    }

    virtual void apply(osg::Switch &sw)
    {
        if(sw.getName()==_name)
            _switchList.push_back(&sw);
        apply((osg::Node&)sw);

        //traverse(sw);
    }

    virtual void apply(osg::MatrixTransform &mt)
    {
        if(mt.getName()==_name)
            _matrixTransformList.push_back(&mt);
        apply((osg::Node&)mt);

        //traverse(transform);
    }



    void setName(std::string& name){ _name = name;}

//    osg::Node *getNamedNode(){return _node.release();}
//    osg::Geode *getNamedGeode(){return _geode.release();}
//    osg::Switch *getNamedSwitch(){return _switch.release();}
//    osg::MatrixTransform *getNamedMatrixTransform(){return _matrixTransform.release();}

    osg::NodeList getAllNamedNodeList(){return _nodeList;}
    osg::NodeList getNamedGeodeList(){return _geodeList;}
    osg::NodeList getNamedGroupList(){return _groupList;}
    osg::NodeList getNamedSwitchList(){return _switchList;}
    osg::NodeList getNamedMatrixTransformList(){return _matrixTransformList;}

protected:
    std::string _name;

//    osg::ref_ptr<osg::Node> _node;
//    osg::ref_ptr<osg::Geode> _geode;
//    osg::ref_ptr<osg::Group> _group;
//    osg::ref_ptr<osg::Switch> _switch;
//    osg::ref_ptr<osg::MatrixTransform> _matrixTransform;

    osg::NodeList _nodeList;
    osg::NodeList _geodeList;
    osg::NodeList _groupList;
    osg::NodeList _switchList;
    osg::NodeList _matrixTransformList;


};



/**
 * Function: 提取某节点下的全部顶点
*/
class vertexExtractor : public osg::NodeVisitor
{
public:
    vertexExtractor(TraversalMode tm = osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
        :osg::NodeVisitor( tm)//默认遍历全部children
    {
        _vertexArray=new osg::Vec3Array;
    }

    virtual void apply(osg::Geode &geode);

    osg::Vec3Array *getAllVertexArrayInWorldCoord(){ return _vertexArray.release();}
protected:
    osg::ref_ptr<osg::Vec3Array> _vertexArray;

};



/**
 * Function: 设置给定模型的颜色
*/
class setModelColorVisitor : public osg::NodeVisitor
{
public:
    setModelColorVisitor(const osg::Vec4& color = osg::Vec4(1.f,0.f,0.f,1.f),TraversalMode tm = osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
        :osg::NodeVisitor( tm),//默认遍历全部children
        _color(color)
    {
    }

    virtual void apply(osg::Geode &geode)
    {
        osg::ref_ptr<osg::Vec4Array> colorArray=new osg::Vec4Array;
        colorArray->push_back(_color);
        //得到每个Drawable
        for(unsigned int i=0; i<geode.getNumDrawables();++i)
        {
            osg::ref_ptr<osg::Geometry> geom=geode.getDrawable(i)->asGeometry();
            osg::ref_ptr<osgText::Text3D> text=dynamic_cast<osgText::Text3D *> (geode.getDrawable(i));
            if(geom)
                geom->setColorArray(colorArray.get(),osg::Array::BIND_OVERALL);
            else if(text)
                text->setColor(_color);
            else continue;
        }
    }

    void setColor(osg::Vec4& color){ _color=color;}

protected:
    osg::Vec4 _color;

};



/**
 * Function: 该访问器用于返回某个节点的世界坐标矩阵
 * 从起始节点开始向根节点遍历，并将遍历的节点记录到nodePath中
 * 第一次到达根节点之后，记录起始点到根节点的节点路径
 * 获取所有世界坐标矩阵之后，即获得节点的世界坐标
*/
class LocalToWorldMatrix : public osg::NodeVisitor
{
public:
    LocalToWorldMatrix(TraversalMode tm = osg::NodeVisitor::TRAVERSE_PARENTS);

    virtual void apply(osg::Node &node);
    //返回世界坐标矩阵
    osg::Matrix getLocalToWorldMatrix() {return _wcMatrix;}


protected:
    bool _done;
    osg::Matrix _wcMatrix;

};


/**
 * Function: 遍历某节点N下的全部geode节点,并计算该geode节点到根节点的局部至世界坐标转换矩阵
 * 并根据该转换矩阵，生成对应osg::MatrixTransform矩阵，将geode节点添加至其下
 * 最终将各个osg::MatrixTransform添加至group中
*/
class unificateNodeStructure : public osg::NodeVisitor
{
public:
    unificateNodeStructure(TraversalMode tm = osg::NodeVisitor::TRAVERSE_ALL_CHILDREN);

    virtual void apply(osg::Geode &geode);

    //结构化后的group（以某一个读入或自生成的文件为单位）
    osg::Group *getStructurizedGroup(){ return _group.release();}
protected:
    osg::ref_ptr<osg::Group> _group;


    const QString defultGroupName = "defultgroup";
    const QString defultGeodeName = "defultgeode";
};



/** 模板类
 * Function: 为class polygonVisitor提供模板类
 * 以便提供operator(). 获取到的是顶点在世界坐标系下（或局部坐标系，取决于其中的转换矩阵）的坐标
*/
class TriangleVertex
{
public:
    TriangleVertex(){}

    void operator()(const osg::Vec3& v1,const osg::Vec3& v2,const osg::Vec3& v3,bool) const
    {
        osg::ref_ptr<osg::Vec3Array> v3a = new osg::Vec3Array;
        v3a->push_back(v1);
        v3a->push_back(v2);
        v3a->push_back(v3);

        bool isI = _wcMatrix.isIdentity();//单位阵
        for(unsigned int i=0; i<v3a->size();++i)
        {
            osg::Vec3 vt3(v3a->at(i));
            osg::Vec4 vt4(vt3,1.0);
            //转换矩阵非单位阵
            if(!isI)
            {
                vt4=vt4*_wcMatrix;
                vt3=osg::Vec3(vt4.x(),vt4.y(),vt4.z());
            }

            triangleVertextArray->push_back(vt3);
        }
    }

    osg::ref_ptr<osg::Vec3Array> triangleVertextArray=new osg::Vec3Array;

public:
    void setLocalToWorldMatrix(osg::Matrix &matrix) { _wcMatrix = matrix;}

private:
    osg::Matrix _wcMatrix=osg::Matrix::identity();//局部至世界坐标转换矩阵,初始化为单位阵
};

/**
 * Function: 提取多边形
 * 暂时仅实现提取所有drawable中所有三角形及线框（线段）序列
 * 三角形Array：每三点定义一个三角形
 * 线段Array：每两点定义一个线段
*/
class polygonVisitor : public osg::NodeVisitor
{
public:
    polygonVisitor(TraversalMode tm = osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
        :osg::NodeVisitor( tm)//默认遍历全部children
    { _linesArray = new osg::Vec3Array;}

    virtual void apply(osg::Geode &geode)
    {
        LocalToWorldMatrix nLTWM;
        geode.accept(nLTWM);
        osg::Matrix m = nLTWM.getLocalToWorldMatrix();
        _tf.setLocalToWorldMatrix(m);

        for(unsigned int i=0;i<geode.getNumDrawables();++i)
        {
            //三角形
            geode.getDrawable(i)->accept(_tf);

            //线段
            geode.getDrawable(i)->accept(_lf);
            osg::ref_ptr<osg::Vec3Array> linesTemp=new osg::Vec3Array;
            linesTemp=_lf.getLinesArray();
            if(m.isIdentity())//单位阵
            {
                if(linesTemp && linesTemp->size()>0)
                    _linesArray->insert(_linesArray->end(),linesTemp->begin(),linesTemp->end());
            }
            else//非单位阵
            {
                for(unsigned int i=0; i<linesTemp->size(); ++i)
                {
                    osg::Vec4 vt4(linesTemp->at(i),1.0f);
                    vt4=vt4*m;
                    _linesArray->push_back(osg::Vec3(vt4.x(),vt4.y(),vt4.z()));
                }
            }
        }
    }

    osg::Vec3Array* getTriangles(){return _tf.triangleVertextArray.release();}
    osg::Vec3Array* getLines(){return _linesArray.release();}

protected:
    osg::TriangleFunctor<TriangleVertex> _tf;
    osg::LineFunctor _lf;
    osg::ref_ptr<osg::Vec3Array> _linesArray;


};





#endif // VISITOR

