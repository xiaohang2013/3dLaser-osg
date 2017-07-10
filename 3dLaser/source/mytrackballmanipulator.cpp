#include "mytrackballmanipulator.h"


#define degPerRadius 22.5f/180.f*3.14159265358979323846;


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

// 设置视角方位
void MyTrackballManipulator::setViewDirection(ViewDirection direction)
{
    osg::Vec3d eye,center,up;
    getHomePosition(eye, center, up);

    if(direction == FRONTVIEW)
    {
        eye = osg::Vec3d(0.0,0.0,350.0);
        up = osg::Vec3d(0.0,1.0,0.0);
    }
    else if(direction == LEFTVIEW)
    {
        eye = osg::Vec3d(-350.0,0.0,0.0);
        up = osg::Vec3d(0.0,1.0,0.0);
    }
    else if(direction == RIGHTVIEW)
    {
        eye = osg::Vec3d(350.0,0.0,0.0);
        up = osg::Vec3d(0.0,1.0,0.0);
    }
    else if(direction == TOPVIEW)
    {
        eye = osg::Vec3d(0.0,350.0,0.0);
        up = osg::Vec3d(0.0,0.0,-1.0);
    }
    else return;

    setHomePosition(eye,center,up);
}

// 左右视角变化
/// @param direct: 正，左； 负，右； direct绝对值控制每次视角变动大小
void MyTrackballManipulator::rotateLeftRight(int direct)
{
    float yaw = direct*degPerRadius;

    // rotations
    osg::Quat rotateYaw;
    osg::Vec3d up(_rotation * osg::Vec3d( 0.,1.,0. ));

    rotateYaw.makeRotate(yaw, up);
    _rotation *= rotateYaw;
}

// 上下视角变化
/// @param direct: 正，上； 负，下； direct绝对值控制每次视角变动大小
void MyTrackballManipulator::rotateUpDown(int direct)
{
    float pitch = direct*degPerRadius;

    osg::Quat rotatePitch;
    osg::Vec3d cameraRight( _rotation * osg::Vec3d( 1.,0.,0. ) );

    // rotations
    rotatePitch.makeRotate( pitch, cameraRight );
    _rotation *= rotatePitch;
}



