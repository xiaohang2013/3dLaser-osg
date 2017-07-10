#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <QString>
#include <QMainWindow>
#include <QTimer>
#include <osg/ref_ptr>
#include <osg/MatrixTransform>
#include <osg/Vec3>
#include <osgManipulator/TabBoxDragger>
#include <osgManipulator/Selection>
#include <osgGA/GUIEventAdapter>
#include <osgManipulator/TrackballDragger>
#include <osgManipulator/TranslateAxisDragger>
#include <osgManipulator/ScaleAxisDragger>
#include <osgManipulator/CommandManager>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgGA/StateSetManipulator>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osg/Material>
#include <osg/MatrixTransform>
#include <osg/ComputeBoundsVisitor>
#include <osg/BoundingBox>
#include <osg/BoundingSphere>
#include <osg/BlendFunc>
#include <osg/ValueObject>

#include <osg/CullFace>

#include "osgContainer.h"
#include "ui_mainwindow.h"
#include "meshinterface.h"
#include "parameter.h"
#include "visitor.h"
#include "parawindow.h"
#include "markwindow.h"
#include "mcurvwindow.h"
#include "ctrlcard.h"

#if _MSC_VER >= 1600
   #pragma execution_character_set("utf-8")
#endif

namespace Ui {
class MainWindow;
}

/** 显示模式 */
enum DisplayMode
{
    STEREOGRAM,//模型图（3D object 或 2D image）
    WIREFRAME,//线框图
    POINTCLOUD//点云图
};

struct TimerData
{
    int count;
    int hour;
    int minut;
    int second;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    /**   文件菜单    **/
    void slot_FileOpen();
    void slot_FileSave();
    void slot_FileRecent();
    void slot_FileExit();
    void slot_FileClearPathList();

    /**   机器参数    **/
    void slot_LaserPara();
    void slot_LaserRegImp();
    void slot_LaserRegExp();
    void slot_LaserBatchSet();
    void slot_LaserTagGen();
    void slot_LaserCal();
    void slot_LaserPosTest();
    void slot_LaserPlatSetH();

    /**   视图菜单    **/
    void slot_ViewTool();
    void slot_ViewStat();
    void slot_ViewCtrl();
    void slot_ViewForth();
    void slot_ViewTop();
    void slot_ViewRight();
    void slot_ViewUpdate();
    void slot_ViewOriModel();
    void slot_ViewModModel();
    void slot_ViewApartModel();

    /**   排序菜单    **/
    void slot_SortY2X();
    void slot_SortX2Y();
    void slot_SortOri();
    void slot_SortShort();

    /**   分块菜单    **/
    void slot_BlockX2Y();
    void slot_BlockY2X();
    void slot_BlockShort();
    void slot_BlockPara();

    /**   操作菜单    **/
    void slot_OperLaserOri();
    void slot_OperPlatHome();
    void slot_OperSetCurPos2LaserOri();
    void slot_OperSaveCurPos2LaserOri();

    /**   调试菜单    **/
    void slot_DebugAtchModel();
    void slot_DebugHotTest();
    void slot_DebugSplitModel();
    void slot_DebugStopFun();
    void slot_StdModCube();
    void slot_StdModLine();
    void slot_StdModPlat();
    void slot_StdModSphere();

    /**   帮助菜单    **/
    void slot_HelpAboutMe();

    /**   语言菜单    **/
    void slot_LanCHN();

    /**   侧边栏    **/
    void slot_MotorStop();
    void slot_CrvView();
    void slot_CrvApp();
    void slot_PlatOrigin();
    void slot_PlatReset();
    void slot_PlatCtrl();
    void slot_MovMode();
    void slot_LaserCtrl();


    // UI窗体/控件
private:

    QLabel *lb_StRunTime;
    QLabel *lb_StLaserTime;
    QLabel *lb_StInfo;
    QTimer *timerRun;

    ParaWindow *parameterWindow;
    MarkWindow *markWindow;
    McurvWindow *mCurvWindow;

private:

    Ui::MainWindow *ui;

    //mainWindow
    meshInterface MI;   // 读取文件接口

    QStringList fileList;   //最近打开的文件
    QStringList pathList;   //最近文件目录
    bool isLaserOn;
    TimerData tdRunningTime;
    TimerData tdLaserOnTime;



    osg::ref_ptr<Crystal> crystal;
    osg::ref_ptr<Plat> plat;
    osg::ref_ptr<Scaner> scaner;
    osg::ref_ptr<Laser> laser;
    osg::ref_ptr<Motor> motor;
    osg::ref_ptr<CtrlCard> ctrlCard;

    //osgViewer
    osg::ref_ptr<osgContainer> curViewer;
    osg::ref_ptr<osg::Switch> curRoot;
    osg::ref_ptr<osg::Geode> refShape;
    osg::ref_ptr<osg::Group> modelGroup;
    osg::ref_ptr<osg::Group> pictureGroup;
    osg::ref_ptr<osg::Group> pointCloudGroup;
    osg::ref_ptr<osg::Group> ordinaryPointsGroup;
    osg::ref_ptr<osg::Group> texturePointsGroup;
    osg::ref_ptr<osg::Group> picturePointsGroup;
    osg::ref_ptr<osg::Group> additionalPointsGroup;
    osg::ref_ptr<osg::Group> previewGroup;//预览组
    osg::ref_ptr<osg::Group> draggerGroup;//dragger组
    osg::Vec3 curCrystalSize = osg::Vec3(60.f,60.f,60.f);
    float curCrystalHeight = 10.f;
    float curCrystalDiameter = 70.f;
    float curCrystalZRot = 0.f;
//function
    void initMainWindow();
    void initTimer();
    void updateParam();
    void initStBar();
    void initOSG();
    void initProjectionAsOrtho();
    int initCtrlBoard();
    void initPara();
    QString makeUniqueName(const QString &oldName, const QStringList &existingNameList);
    QStringList getOrdinaryLayerNameList();
    void setUserPrmForNode(osg::Node *node, Parameter *prm);
    void updateOSGDisplay(DisplayMode mode);
    void setPointCloudVisible(bool visible);
    void updateLighting(bool brightening);//增强环境光照
    void getTime(TimerData *t);
    void spyPutIn();
    osg::Vec3Array *MainWindow::getVertexArray(osg::Node *node);
    void openFile(QString fileName);
    void setAxesVisible(bool visible);
    void updateRefShape(osg::Geode *geode);
    void getPoints(const QString fileName);
    void slot_TimerRefresh();
    void readIO();
    void refreshIO();
};

#endif // MAINWINDOW_H
