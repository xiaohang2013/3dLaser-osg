#ifndef MYTRACKBALLMANIPULATOR_H
#define MYTRACKBALLMANIPULATOR_H

#include <osgGA/TrackballManipulator>

/** 视图方向 */
enum ViewDirection
{
    DEFAULTVIEW,    //缺省（未设定）
    FRONTVIEW,  //前视图
    LEFTVIEW,   //左视图
    RIGHTVIEW,  //右视图
    TOPVIEW //顶视图
};


class MyTrackballManipulator : public osgGA::TrackballManipulator
{
    typedef osgGA::TrackballManipulator inherited;

public:
    MyTrackballManipulator(osg::Camera *camera, int flags = DEFAULT_SETTINGS );
    ~MyTrackballManipulator(){}


protected:
    virtual bool handleMouseWheel( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us );

// public functions
public:
    bool isPerspectiveProjection();
    bool isOrthoProjection();

    // 设置视角方位
    void setViewDirection(ViewDirection direction);
    // 界面按键控制manipulator，从而控制界面视角变化
    // 左右视角转动
    void rotateLeftRight(int direct);
    // 上下视角转动
    void rotateUpDown(int direct);

private:
    osg::ref_ptr<osg::Camera> _camera;


};

#endif // MYTRACKBALLMANIPULATOR_H
