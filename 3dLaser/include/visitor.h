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
#include <osg/Switch>
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
//#include <osg/TriangleFunctor>
#include <osgText/Text3D>
#include "parameter.h"


#include <QString>

/**
 * Function: 查找给定名称的节点
*/
class findNodeList : public osg::NodeVisitor
{
public:
    findNodeList(const std::string& name="", TraversalMode tm = osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
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
            _namedNodeList.push_back(&node);

        // 继续遍历场景图形剩余的部分(父类inline函数，直接推进本访问器继续访问)
        traverse(node);
    }

    virtual void apply(osg::Geode &geode)
    {
        _allGeodeList.push_back(&geode);
        if(geode.getName()==_name)
            _namedGeodeList.push_back(&geode);

        // 存储Drawables
        unsigned int numDraw = geode.getNumDrawables();
        if(numDraw>0)
            _allDrawableList.insert(_allDrawableList.end(), geode.getDrawableList().begin(), geode.getDrawableList().end());

        apply((osg::Node&)geode);

        //traverse(geode);
    }

    virtual void apply(osg::Group &group)
    {
        if(group.getName()==_name)
            _namedGroupList.push_back(&group);
        apply((osg::Node&)group);

        //traverse(group);
    }

    virtual void apply(osg::Switch &sw)
    {
        if(sw.getName()==_name)
            _namedSwitchList.push_back(&sw);
        apply((osg::Node&)sw);

        //traverse(sw);
    }

    virtual void apply(osg::MatrixTransform &mt)
    {
        _allMatrixTransformList.push_back(&mt);
        if(mt.getName()==_name)
            _namedMatrixTransformList.push_back(&mt);
        apply((osg::Node&)mt);

        //traverse(transform);
    }



    void setName(std::string& name){ _name = name;}

//    osg::Node *getNamedNode(){return _node.release();}
//    osg::Geode *getNamedGeode(){return _geode.release();}
//    osg::Switch *getNamedSwitch(){return _switch.release();}
//    osg::MatrixTransform *getNamedMatrixTransform(){return _matrixTransform.release();}

    osg::NodeList getAllNamedNodeList(){return _namedNodeList;}
    osg::NodeList getNamedGeodeList(){return _namedGeodeList;}
    osg::NodeList getNamedGroupList(){return _namedGroupList;}
    osg::NodeList getNamedSwitchList(){return _namedSwitchList;}
    osg::NodeList getNamedMatrixTransformList(){return _namedMatrixTransformList;}

    osg::NodeList getAllMatrixTransformList(){return _allMatrixTransformList;}
    osg::NodeList getAllGeodeList(){return _allGeodeList;}
    osg::Geode::DrawableList getAllDrawableList(){return _allDrawableList;}


protected:
    std::string _name;

//    osg::ref_ptr<osg::Node> _node;
//    osg::ref_ptr<osg::Geode> _geode;
//    osg::ref_ptr<osg::Group> _group;
//    osg::ref_ptr<osg::Switch> _switch;
//    osg::ref_ptr<osg::MatrixTransform> _matrixTransform;

    osg::NodeList _namedNodeList;
    osg::NodeList _namedGeodeList;
    osg::NodeList _namedGroupList;
    osg::NodeList _namedSwitchList;
    osg::NodeList _namedMatrixTransformList;

    osg::NodeList _allMatrixTransformList;
    osg::NodeList _allGeodeList;
    osg::Geode::DrawableList _allDrawableList;


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


    const QString defaultGroupName = "defultgroup";
    const QString defaultGeodeName = "defultgeode";
};




#endif // VISITOR

