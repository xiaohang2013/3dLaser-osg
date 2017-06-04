#include "quadtreenode.h"

//QuadTreeNode::QuadTreeNode(QObject *parent) : QObject(parent)
//{

//}

QuadTreeNode::QuadTreeNode(float _x, float _y, float _width, float _height,
        int _level, int _maxLevel,
        QuadType _quadType,
        QuadTreeNode *_parent):
    x(_x), y(_y), width(_width), height(_height),
    level(_level), maxLevel(_maxLevel),
    quadType(_quadType)
{
    parent = _parent;
    upLeftNode = nullptr;
    upRightNode = nullptr;
    bottomLeftNode = nullptr;
    bottomRightNode = nullptr;
}

QuadTreeNode::~QuadTreeNode()
{
    parent=nullptr;
    if(level==maxLevel)
        return;
    //如果不是叶子节点，就销毁子节点
    delete upLeftNode;
    delete upRightNode;
    delete bottomLeftNode;
    delete bottomRightNode;
    upLeftNode = nullptr;
    upRightNode = nullptr;
    bottomLeftNode = nullptr;
    bottomRightNode = nullptr;
}

bool QuadTreeNode::isContain(float px, float py, float w, float h, osg::Vec3 point) const
{
    if(point.x()>=px && point.x()<=px+w && point.y()>=py && point.y()<=py+h)
        return true;
    return false;
}

bool QuadTreeNode::isContain(float px, float py, float w, float h, QuadTreeNode *quadTreeNode) const
{
    if(quadTreeNode->x>=px && quadTreeNode->x+quadTreeNode->width<=px+w
       && quadTreeNode->y>=py && quadTreeNode->y+quadTreeNode->height<=py+h)
        return true;
    return false;

}

void QuadTreeNode::insertPoint(osg::Vec3 point)
{
    //如果是叶子节点，则插入点
    if(level==maxLevel)
    {
        points->push_back(point);
        return;
    }

    //非叶子节点，如果下层节点可以包含该点，则递归（构建子节点并）插入对象，（边构建边插入）
    /// 左上节点
    if(isContain(x, y+height*0.5f, width*0.5f, height*0.5f, point))
    {
        if(!upLeftNode)//避免重复创建覆盖掉原来的节点     如果没有子节点就创建子节点，parent节点是当前节点
            upLeftNode = new QuadTreeNode(x, y+height*0.5f, width*0.5f, height*0.5f, level+1, maxLevel, UP_LEFT, this);
        upLeftNode->insertPoint(point);
        return;
    }
    /// 右上节点
    else if(isContain(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, point))
    {
        if(!upRightNode)
            upRightNode = new QuadTreeNode(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, level+1, maxLevel, UP_RIGHT, this);
        upRightNode->insertPoint(point);
        return;
    }
    /// 左下节点
    else if(isContain(x, y, width*0.5f, height*0.5f, point))
    {
        if(!bottomLeftNode)
            bottomLeftNode = new QuadTreeNode(x, y, width*0.5f, height*0.5f, level+1, maxLevel, BOTTOM_LEFT, this);
        bottomLeftNode->insertPoint(point);
        return;
    }
    /// 右下节点
    else if(isContain(x+width*0.5f, y, width*0.5f, height*0.5f, point))
    {
        if(!bottomRightNode)
            bottomRightNode = new QuadTreeNode(x+width*0.5f, y, width*0.5f, height*0.5f, level+1, maxLevel, BOTTOM_RIGHT, this);
        bottomRightNode->insertPoint(point);
        return;
    }
}

bool QuadTreeNode::insertPoint(osg::Vec3 point, float radius)
{
    //如果是叶子节点，则插入点
    if(level==maxLevel)
    {
        bool caninsert = true;
        osg::Vec3 p;
        for(unsigned int i=0; i<points->size(); ++i)
        {
            p = points->at(i)-point;
            if(p.length2()<radius*radius)
            {
                caninsert = false;
                return false;
            }
        }
        if(caninsert)
            points->push_back(point);
        return true;
    }

    //非叶子节点，如果下层节点可以包含该点，则递归（构建子节点并）插入对象，（边构建边插入）
    /// 左上节点
    if(isContain(x, y+height*0.5f, width*0.5f, height*0.5f, point))
    {
        if(!upLeftNode)//避免重复创建覆盖掉原来的节点     如果没有子节点就创建子节点，parent节点是当前节点
            upLeftNode = new QuadTreeNode(x, y+height*0.5f, width*0.5f, height*0.5f, level+1, maxLevel, UP_LEFT, this);
        return upLeftNode->insertPoint(point,radius);
    }
    /// 右上节点
    else if(isContain(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, point))
    {
        if(!upRightNode)
            upRightNode = new QuadTreeNode(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, level+1, maxLevel, UP_RIGHT, this);
        return upRightNode->insertPoint(point,radius);
    }
    /// 左下节点
    else if(isContain(x, y, width*0.5f, height*0.5f, point))
    {
        if(!bottomLeftNode)
            bottomLeftNode = new QuadTreeNode(x, y, width*0.5f, height*0.5f, level+1, maxLevel, BOTTOM_LEFT, this);
        return bottomLeftNode->insertPoint(point,radius);
    }
    /// 右下节点
    else if(isContain(x+width*0.5f, y, width*0.5f, height*0.5f, point))
    {
        if(!bottomRightNode)
            bottomRightNode = new QuadTreeNode(x+width*0.5f, y, width*0.5f, height*0.5f, level+1, maxLevel, BOTTOM_RIGHT, this);
        return bottomRightNode->insertPoint(point,radius);
    }
    return false;
}

osg::ref_ptr<osg::Vec3Array> QuadTreeNode::getPointsAt(float px, float py, float w, float h)
{
    osg::ref_ptr<osg::Vec3Array> resPoints = new osg::Vec3Array;//存放结果
    //如果当前节点被完全包含且为叶子节点，则把当前节点的点云存放至结果点云的末尾
    if(level==maxLevel && isContain(px,py,w,h,this))
    {
        resPoints->insert(resPoints->end(), points->begin(), points->end());
        return resPoints.release();
    }

    osg::ref_ptr<osg::Vec3Array> tempPoints;
    //如果有下层节点，则递归至最后一层节点
    if(upLeftNode)
    {
        tempPoints = upLeftNode->getPointsAt(px,py,w,h);
        resPoints->insert(resPoints->end(), tempPoints->begin(), tempPoints->end());
    }
    if(upRightNode)
    {
        tempPoints = upRightNode->getPointsAt(px,py,w,h);
        resPoints->insert(resPoints->end(), tempPoints->begin(), tempPoints->end());
    }
    if(bottomLeftNode)
    {
        tempPoints = bottomLeftNode->getPointsAt(px,py,w,h);
        resPoints->insert(resPoints->end(), tempPoints->begin(), tempPoints->end());
    }
    if(bottomRightNode)
    {
        tempPoints = bottomRightNode->getPointsAt(px,py,w,h);
        resPoints->insert(resPoints->end(), tempPoints->begin(), tempPoints->end());
    }
    return resPoints.release();
}

void QuadTreeNode::removePointsAt(float px, float py, float w, float h)
{
    //如果本层节点被包含且为叶子节点则删除本层节点的对象
    if(level==maxLevel && isContain(px,py,w,h,this))
    {
        //清除点云
        points->clear();
        return;
    }

    if(upLeftNode)
    {
        upLeftNode->removePointsAt(px,py,w,h);
        delete upLeftNode;
        upLeftNode=nullptr;
    }
    if(upRightNode)
    {
        upRightNode->removePointsAt(px,py,w,h);
        delete upRightNode;
        upRightNode=nullptr;
    }
    if(bottomLeftNode)
    {
        bottomLeftNode->removePointsAt(px,py,w,h);
        delete bottomLeftNode;
        bottomLeftNode=nullptr;
    }
    if(bottomRightNode)
    {
        bottomRightNode->removePointsAt(px,py,w,h);
        delete bottomRightNode;
        bottomRightNode=nullptr;
    }

}

//void QuadTreeNode::releaseQuadTree()
//{
//    if(upLeftNode) upLeftNode->releaseQuadTree();
//    if(upRightNode) upRightNode->releaseQuadTree();
//    if(bottomLeftNode) bottomLeftNode->releaseQuadTree();
//    if(bottomRightNode) bottomRightNode->releaseQuadTree();

//    parent=nullptr;
//    //points->unref();
//    if(level==maxLevel)
//        return;
//    delete upLeftNode;
//    delete upRightNode;
//    delete bottomLeftNode;
//    delete bottomRightNode;
//    upLeftNode = nullptr;
//    upRightNode = nullptr;
//    bottomLeftNode = nullptr;
//    bottomRightNode = nullptr;
//}

