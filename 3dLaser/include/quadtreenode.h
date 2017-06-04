/*
 * Date: 2017.04.14
 * By: Liu
 * Function: 四叉树节点类，用头节点代表四叉树;
 *          以格子左下角为锚点，自左往右为x轴递增，自下而上为y轴递增;
 *          树枝节点和根节点不包含点，只有叶子节点包含点
 * */

#ifndef QUADTREENODE_H
#define QUADTREENODE_H

#include <QObject>
#include <list>
#include <osg/array>





class QuadTreeNode : public QObject
{
    Q_OBJECT
public:
    //四叉树类型枚举
    enum QuadType
    {
        ROOT,         //根
        UP_RIGHT,     //象限Ⅰ
        UP_LEFT,      //象限Ⅱ
        BOTTOM_LEFT,  //象限Ⅲ
        BOTTOM_RIGHT  //象限Ⅳ
    };

public:
    //explicit QuadTreeNode(QObject *parent = 0);
    QuadTreeNode(float _x, float _y,float _width, float _height, int _level, int _maxLevel, QuadType _quadType, QuadTreeNode *_parent);
    ~QuadTreeNode();


private:
    bool isContain(float px,float py,float w,float h,osg::Vec3 point) const; //判断某个区域是否包含某对象
    bool isContain(float px,float py,float w,float h,QuadTreeNode *quadTreeNode)const;  //重载，判断某个区域是否包含某个节点

public:
    void insertPoint(osg::Vec3 point);//插入对象
    bool insertPoint(osg::Vec3 point, float radius);//插入对象
    osg::ref_ptr<osg::Vec3Array> getPointsAt(float px,float py,float w,float h);//查询对象,获得一片区域里的对象链表
    void removePointsAt(float px,float py,float w,float h);//删除对象，删除一片区域里的对象和节点
//    void releaseQuadTree();//释放空间



private:
    osg::ref_ptr<osg::Vec3Array> points = new osg::Vec3Array;//节点点云数据队列
    //父、子节点，分四个象限
    QuadTreeNode *parent;
    QuadTreeNode *upRightNode;
    QuadTreeNode *upLeftNode;
    QuadTreeNode *bottomLeftNode;
    QuadTreeNode *bottomRightNode;
    //节点类型
    QuadType quadType;
    //坐标和长宽属性，左上角为锚点
    float x;
    float y;
    float width;
    float height;

    int level; //当前深度
    int maxLevel = false; //最大深度



};

#endif // QUADTREENODE_H
