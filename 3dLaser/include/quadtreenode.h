/*
 * Date: 2017.04.14
 * By: Liu
 * Function: 四叉树节点类，用头节点代表四叉树;
 *          以格子左下角为锚点，自左往右为x轴递增，自下而上为y轴递增;
 *          树枝节点和根节点不包含点，只有叶子节点包含点
 * */

#ifndef QUADTREENODE_H
#define QUADTREENODE_H

#include <list>
#include <osg/array>
#include <osg/Referenced>





class QuadTreeNode:public osg::Referenced
{
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

    inline QuadTreeNode *getAncestor(){ return ancestor;}

private:
    bool isContain(float px, float py, float w, float h, const osg::Vec3 &point) const; //判断某个区域是否包含某对象
    bool isContain(float px,float py,float w,float h,QuadTreeNode *quadTreeNode)const;  //重载，判断某个区域是否包含某个节点



public:
    //插入对象
    void insertPoint(const osg::Vec3 &point);
    // 点point是否可以被插入
    bool canBeInserted(const osg::Vec3 &point, const float &radius);
    // 根据hookPoint所在叶子节点上判断点point是否满足被插入的点距条件（不实际插入）
    bool canBeInserted(const osg::Vec3 &hookPoint, const osg::Vec3 &point, const float &radius);
    //插入对象，插入成功返回true；否则返回false
//    bool insertPoint(const osg::Vec3 &point, const float &radius);
    //插入对象，插入成功返回true；否则返回false
    bool insertPoint(const osg::Vec3 &point, const float &radius, bool withSurroundingCheck=false);
    osg::ref_ptr<osg::Vec3Array> getPointsAt(float px,float py,float w,float h);//查询对象,获得一片区域里的对象链表
    void removePointsAt(float px,float py,float w,float h);//删除对象，删除一片区域里的对象和节点
//    void releaseQuadTree();//释放空间



private:
    osg::ref_ptr<osg::Vec3Array> points = new osg::Vec3Array;//节点点云数据队列
    //父、子节点，分四个象限
    QuadTreeNode *parent;   //  记录父亲的指针（只记录，不是new出来的），不要用ref指针，否则不好释放
    QuadTreeNode *ancestor; //  祖先指针
    osg::ref_ptr<QuadTreeNode> upRightNode;
    osg::ref_ptr<QuadTreeNode> upLeftNode;
    osg::ref_ptr<QuadTreeNode> bottomLeftNode;
    osg::ref_ptr<QuadTreeNode> bottomRightNode;
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
