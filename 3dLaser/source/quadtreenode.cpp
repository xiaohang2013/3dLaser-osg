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

    if(parent)
    {
        if(parent->getAncestor())
            ancestor = parent->getAncestor();
        else ancestor = parent;
    }
    else ancestor = nullptr;
}

QuadTreeNode::~QuadTreeNode()
{
//    parent = NULL;
//    if(level==maxLevel)
//        return;
    //如果不是叶子节点，就销毁子节点
//    upLeftNode->unref();
//    upRightNode->unref();
//    bottomLeftNode->unref();
//    bottomRightNode->unref();
//    upLeftNode = nullptr;
//    upRightNode = nullptr;
//    bottomLeftNode = nullptr;
//    bottomRightNode = nullptr;
}

bool QuadTreeNode::isContain(float px, float py, float w, float h, const osg::Vec3 &point) const
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

// 点point是否可以被插入（不实际插入）,且不考虑周边节点是否满足点距离条件
bool QuadTreeNode::canBeInserted(const osg::Vec3 &point, const float &radius)
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
        return caninsert;
    }

    //非叶子节点，如果下层节点可以包含该点，则递归（构建子节点并）插入对象，（边构建边插入）
    /// 左上节点
    if(isContain(x, y+height*0.5f, width*0.5f, height*0.5f, point))
    {
        if(!upLeftNode)//为空，即说明一定还没有点在里面
            return true;
        else
            return upLeftNode->canBeInserted(point, radius);
    }
    /// 右上节点
    else if(isContain(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, point))
    {
        if(!upRightNode)
            return true;
        else
            return upRightNode->canBeInserted(point,radius);
    }
    /// 左下节点
    else if(isContain(x, y, width*0.5f, height*0.5f, point))
    {
        if(!bottomLeftNode)
            return true;
        else
            return bottomLeftNode->canBeInserted(point,radius);
    }
    /// 右下节点
    else if(isContain(x+width*0.5f, y, width*0.5f, height*0.5f, point))
    {
        if(!bottomRightNode)
            return true;
        else
            return bottomRightNode->canBeInserted(point,radius);
    }
    return false;
}

// 根据hookPoint所在的叶子节点上判断实际点point是否满足被插入的点距条件（不实际插入）
// 即 判断外围节点的点距条件
/// @param hookPoint 钩子点
/// @param point 实际待判断点
/// @param radius 点距条件
bool QuadTreeNode::canBeInserted(const osg::Vec3 &hookPoint, const osg::Vec3 &point, const float &radius)
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
        return caninsert;
    }

    //非叶子节点，如果下层节点可以包含该点，则递归查询
    /// 左上节点
    if(isContain(x, y+height*0.5f, width*0.5f, height*0.5f, hookPoint))
    {
        if(!upLeftNode)//为空，即说明一定还没有点在里面
            return true;
        else
            return upLeftNode->canBeInserted(hookPoint, point, radius);
    }
    /// 右上节点
    else if(isContain(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, hookPoint))
    {
        if(!upRightNode)
            return true;
        else
            return upRightNode->canBeInserted(hookPoint, point, radius);
    }
    /// 左下节点
    else if(isContain(x, y, width*0.5f, height*0.5f, hookPoint))
    {
        if(!bottomLeftNode)
            return true;
        else
            return bottomLeftNode->canBeInserted(hookPoint, point, radius);
    }
    /// 右下节点
    else if(isContain(x+width*0.5f, y, width*0.5f, height*0.5f, hookPoint))
    {
        if(!bottomRightNode)
            return true;
        else
            return bottomRightNode->canBeInserted(hookPoint, point, radius);
    }
    return false;
}

void QuadTreeNode::insertPoint(const osg::Vec3 &point)
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

//bool QuadTreeNode::insertPoint(const osg::Vec3 &point, const float &radius)
//{
//    //如果是叶子节点，则插入点
//    if(level==maxLevel)
//    {
//        bool caninsert = true;
//        osg::Vec3 p;
//        for(unsigned int i=0; i<points->size(); ++i)
//        {
//            p = points->at(i)-point;
//            if(p.length2()<radius*radius)
//            {
//                caninsert = false;
//                return false;
//            }
//        }
//        if(caninsert)
//            points->push_back(point);
//        return caninsert;
//    }

//    //非叶子节点，如果下层节点可以包含该点，则递归（构建子节点并）插入对象，（边构建边插入）
//    /// 左上节点
//    if(isContain(x, y+height*0.5f, width*0.5f, height*0.5f, point))
//    {
//        if(!upLeftNode)//避免重复创建覆盖掉原来的节点     如果没有子节点就创建子节点，parent节点是当前节点
//            upLeftNode = new QuadTreeNode(x, y+height*0.5f, width*0.5f, height*0.5f, level+1, maxLevel, UP_LEFT, this);
//        return upLeftNode->insertPoint(point,radius);
//    }
//    /// 右上节点
//    else if(isContain(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, point))
//    {
//        if(!upRightNode)
//            upRightNode = new QuadTreeNode(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, level+1, maxLevel, UP_RIGHT, this);
//        return upRightNode->insertPoint(point,radius);
//    }
//    /// 左下节点
//    else if(isContain(x, y, width*0.5f, height*0.5f, point))
//    {
//        if(!bottomLeftNode)
//            bottomLeftNode = new QuadTreeNode(x, y, width*0.5f, height*0.5f, level+1, maxLevel, BOTTOM_LEFT, this);
//        return bottomLeftNode->insertPoint(point,radius);
//    }
//    /// 右下节点
//    else if(isContain(x+width*0.5f, y, width*0.5f, height*0.5f, point))
//    {
//        if(!bottomRightNode)
//            bottomRightNode = new QuadTreeNode(x+width*0.5f, y, width*0.5f, height*0.5f, level+1, maxLevel, BOTTOM_RIGHT, this);
//        return bottomRightNode->insertPoint(point,radius);
//    }
//    return false;
//}

//插入对象，插入成功返回true；否则返回false
/// @param point 待插入点
/// @param radius 点距条件
/// @param withSurroundingCheck 是否检查外围节点
bool QuadTreeNode::insertPoint(const osg::Vec3 &point, const float &radius, bool withSurroundingCheck)
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

        if(withSurroundingCheck && ancestor)
        {
            // 在左延展区
            if(isContain(x, y, radius, height, point))
                caninsert &= ancestor->canBeInserted(point+osg::Vec3(-width, 0.f, 0.f), point, radius);
            // 在右延展区
            if(isContain(x+width-radius, y, radius, height, point))
                caninsert &= ancestor->canBeInserted(point+osg::Vec3(width, 0.f, 0.f), point, radius);
            // 在上延展区
            if(isContain(x, y+height-radius, width, radius, point))
                caninsert &= ancestor->canBeInserted(point+osg::Vec3(0.f, height, 0.f), point, radius);
            // 在下延展区
            if(isContain(x, y, width, radius, point))
                caninsert &= ancestor->canBeInserted(point+osg::Vec3(0.f, -height, 0.f), point, radius);

        }
        if(caninsert)
            points->push_back(point);
        return caninsert;
    }

    //非叶子节点，如果下层节点可以包含该点，则递归（构建子节点并）插入对象，（边构建边插入）
    /// 左上节点
    if(isContain(x, y+height*0.5f, width*0.5f, height*0.5f, point))
    {
        if(!upLeftNode)//避免重复创建覆盖掉原来的节点     如果没有子节点就创建子节点，parent节点是当前节点
            upLeftNode = new QuadTreeNode(x, y+height*0.5f, width*0.5f, height*0.5f, level+1, maxLevel, UP_LEFT, this);
        return upLeftNode->insertPoint(point,radius,withSurroundingCheck);
    }
    /// 右上节点
    else if(isContain(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, point))
    {
        if(!upRightNode)
            upRightNode = new QuadTreeNode(x+width*0.5f, y+height*0.5f, width*0.5f, height*0.5f, level+1, maxLevel, UP_RIGHT, this);
        return upRightNode->insertPoint(point,radius,withSurroundingCheck);
    }
    /// 左下节点
    else if(isContain(x, y, width*0.5f, height*0.5f, point))
    {
        if(!bottomLeftNode)
            bottomLeftNode = new QuadTreeNode(x, y, width*0.5f, height*0.5f, level+1, maxLevel, BOTTOM_LEFT, this);
        return bottomLeftNode->insertPoint(point,radius,withSurroundingCheck);
    }
    /// 右下节点
    else if(isContain(x+width*0.5f, y, width*0.5f, height*0.5f, point))
    {
        if(!bottomRightNode)
            bottomRightNode = new QuadTreeNode(x+width*0.5f, y, width*0.5f, height*0.5f, level+1, maxLevel, BOTTOM_RIGHT, this);
        return bottomRightNode->insertPoint(point,radius,withSurroundingCheck);
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
//        delete upLeftNode;
//        upLeftNode=nullptr;
    }
    if(upRightNode)
    {
        upRightNode->removePointsAt(px,py,w,h);
//        delete upRightNode;
//        upRightNode=nullptr;
    }
    if(bottomLeftNode)
    {
        bottomLeftNode->removePointsAt(px,py,w,h);
//        delete bottomLeftNode;
//        bottomLeftNode=nullptr;
    }
    if(bottomRightNode)
    {
        bottomRightNode->removePointsAt(px,py,w,h);
//        delete bottomRightNode;
//        bottomRightNode=nullptr;
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

