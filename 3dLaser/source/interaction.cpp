#include "interaction.h"




bool PickAndOtherEventToSignalHandler::handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa)
{
    osg::ref_ptr<osgViewer::View> view = dynamic_cast<osgViewer::View*>(&aa);
    if (!view) return false;

    switch(ea.getEventType())
    {
    //鼠标按下
    case(osgGA::GUIEventAdapter::PUSH):
    {
        //更新鼠标位置
        _mx = ea.getX();
        _my = ea.getY();
        break;
    }
    case(osgGA::GUIEventAdapter::DOUBLECLICK):
    {
        if (_mx==ea.getX() && _my==ea.getY())
        {
            //执行对象选取
            pick(view.get(), ea.getX(), ea.getY());
        }
        break;
    }
    case(osgGA::GUIEventAdapter::DRAG):
    {
        emit signalSendOutDragging();
    }
    default:
        break;
    }
    return false;
}

void PickAndOtherEventToSignalHandler::pick(osg::ref_ptr<osgViewer::View> view, float x, float y)
{
    osg::ref_ptr<osg::Node> node = new osg::Node();//geode
    osg::ref_ptr<osg::Node> parent = new osg::Node();//MatrixTransform
    //创建一个线段交集检测函数
    osgUtil::LineSegmentIntersector::Intersections intersections;
    if (view->computeIntersections(x, y, intersections))
    {
        osgUtil::LineSegmentIntersector::Intersection intersection = *intersections.begin();
        osg::NodePath& nodePath = intersection.nodePath;
        //得到选择的物体
        node = (nodePath.size()>=1)?nodePath[nodePath.size()-1]:0;
        parent = (nodePath.size()>=2)?(nodePath[nodePath.size()-2]):0;
    }
    else
    {
        node = 0;
        parent = 0;
    }

    emit signalSendOutPickedNode(node.get(),parent.get());

    //用一种高亮显示来显示物体已经被选中
//    if (parent.get() && node.get())
//    {
//        osg::ref_ptr<osgFX::Scribe> parentAsScribe = dynamic_cast<osgFX::Scribe*>(parent.get());
//        if (!parentAsScribe)
//        {
//            //如果对象选择到，高亮显示
//            osg::ref_ptr<osgFX::Scribe> scribe = new osgFX::Scribe();
//            scribe->addChild(node.get());
//            parent->asTransform()->asMatrixTransform()->replaceChild(node.get(),scribe.get());
//        }
//        else
//        {
//            //如果没有没有选择到，则移除高亮显示的对象
//            osg::Node::ParentList parentList = parentAsScribe->getParents();
//            for(osg::Node::ParentList::iterator itr=parentList.begin();
//                itr!=parentList.end();
//                ++itr)
//            {
//                (*itr)->replaceChild(parentAsScribe.get(),node.get());
//            }
//        }
//    }

}

