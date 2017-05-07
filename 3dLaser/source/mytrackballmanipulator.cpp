#include "mytrackballmanipulator.h"

MyTrackballManipulator::MyTrackballManipulator(osg::Camera *camera, int flags)
    :inherited( flags ),
    _camera(camera)
{

}

bool MyTrackballManipulator::handleMouseWheel(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &us)
{
    if(isPerspectiveProjection())
        return inherited::handleMouseWheel(ea,us);
    else if(isOrthoProjection())
    {
        double left, right, bottom, top, znear, zfar;//正投影参数
        double f = 1.0;
        _camera->getProjectionMatrixAsOrtho( left, right, bottom, top, znear, zfar);
        osgGA::GUIEventAdapter::ScrollingMotion sm = ea.getScrollingMotion();
        switch( sm )
        {
            // mouse scroll up event
            case osgGA::GUIEventAdapter::SCROLL_UP:
            {
                // perform zoom
                f += _wheelZoomFactor;
                 _camera->setProjectionMatrixAsOrtho( left*f, right*f, bottom*f, top*f, znear, zfar);
                us.requestRedraw();
                us.requestContinuousUpdate( isAnimating() || _thrown );
//                return true;
                break;
            }

                // mouse scroll down event
            case osgGA::GUIEventAdapter::SCROLL_DOWN:
            {
                // perform zoom
                f -= _wheelZoomFactor;
                 _camera->setProjectionMatrixAsOrtho( left*f, right*f, bottom*f, top*f, znear, zfar);
                us.requestRedraw();
                us.requestContinuousUpdate( isAnimating() || _thrown );
//                return true;
                break;
            }

                // unhandled mouse scrolling motion
            default:
//                return false;
                break;
        }
    }
    return false;
}

/// 是透视投影吗
bool MyTrackballManipulator::isPerspectiveProjection()
{
    double a,b,c,d;
    return _camera->getProjectionMatrixAsPerspective(a,b,c,d);
}

/// 是正视投影吗
bool MyTrackballManipulator::isOrthoProjection()
{
    double a,b,c,d,e,f;
    return _camera->getProjectionMatrixAsOrtho( a,b,c,d,e,f);
}

