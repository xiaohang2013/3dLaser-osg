#ifndef QWIDGETINOSG_H
#define QWIDGETINOSG_H

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QPushButton>


#include <osg/Texture2D>
#include <osg/Geometry>
#include <osg/MatrixTransform>
//#include <osgDB/ReadFile>
//#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgQt/QWidgetImage>

/*
*   该类暂时无用；其设计的初衷是：想在OSG场景中添加qt的控件
*
*/

class qwidgetInOSG : public QObject
{
    Q_OBJECT
public:
    qwidgetInOSG();
    ~qwidgetInOSG(){}

//widgets
private:
    QPushButton *pb_Move;
    QPushButton *pb_Rotate;
    QPushButton *pb_Zoom;

private slots:
    void on_pbMoveClicked();


//functions
public:
    osg::Camera *createMoveWidgetNode();
    void createRotateWidget();
    void createZoomWidget();
//    QWidget* createMirrorWidget();

    void initWidgets();




};

#endif // QWIDGETINOSG_H
