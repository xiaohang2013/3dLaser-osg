#ifndef OSGCONTAINER_H
#define OSGCONTAINER_H

#include <QOpenGLWidget>
#include <osgViewer/Viewer>
#include <osg/LightModel>
#include "mytrackballmanipulator.h"

class QInputEvent;

class osgContainer : public QOpenGLWidget, public osgViewer::Viewer
{
    Q_OBJECT

public:
    osgContainer(QWidget *parent = 0);
    ~osgContainer();

    bool event(QEvent* event);

    void setKeyboardModifiers(QInputEvent* event);//组合键
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void resizeEvent(QResizeEvent *event);
    void moveEvent(QMoveEvent* event);
    void timerEvent(QTimerEvent *);

    osgViewer::Viewer* getOSGViewer() { return this; }
    osg::Switch* getRoot(){ return root; }

    void setAxesVisible(bool visible = true);


protected:
    virtual void paintGL();

private:
    void init3D();
    osg::ref_ptr<osg::Camera> createCamera(int x, int y, int w, int h);
    osg::ref_ptr<osg::Node> createCoordinateAxes();
    osg::ref_ptr<osg::Drawable> createAixsLabel(const std::string& text, const osg::Vec3& pos);
    //osg::ref_ptr<osg::Group> createLight(osg::ref_ptr<osg::Node> node=0);

private:
    osg::ref_ptr<osg::Switch> root;// root
    osg::ref_ptr<osg::Node> xyzAxesNode;// axes node
    //osg::ref_ptr<osg::Group> lightsrcGroup;// lighting node


    osg::ref_ptr<osgViewer::GraphicsWindow> window;
};

//class OsgContainer : public QOpenGLWidget
//{
//public:
//    OsgContainer(QWidget *parent = 0);
//    ~OsgContainer();

//    void initializeGL();
//    void paintGL();
//    void resizeGL(int w, int h);
//};

#endif // OSGCONTAINER_H
