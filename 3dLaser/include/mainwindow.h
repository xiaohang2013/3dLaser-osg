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
#include "basicsettingsdialog.h"
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
struct T
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
    void slot_FileOpen();
    void slot_FileSave();
    void slot_FileRecent();
    void slot_FileExit();
    void slot_FileClearPathList();
    void slot_LaserPara();
    void slot_LaserRegImp();
    void slot_LaserRegExp();
    void slot_LaserBatchSet();
    void slot_LaserTagGen();
    void slot_LaserCal();
    void slot_LaserPosTest();
    void slot_LaserPlatSetH();
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
    void slot_SortY2X();
    void slot_SortX2Y();
    void slot_SortOri();
    void slot_SortShort();
    void slot_BlockX2Y();
    void slot_BlockY2X();
    void slot_BlockShort();
    void slot_BlockPara();
    void slot_OperLaserOri();
    void slot_OperPlatHome();
    void slot_OperSetCurPos2LaserOri();
    void slot_OperSaveCurPos2LaserOri();
    void slot_DebugAtchModel();
    void slot_DebugHotTest();
    void slot_DebugSplitModel();
    void slot_DebugStopFun();
    void slot_StdModCube();
    void slot_StdModLine();
    void slot_StdModPlat();
    void slot_StdModSphere();
    void slot_HelpAboutMe();
    void slot_LanCHN();
    void slot_MovTo();
    void slot_MotorStop();
    void slot_CrvView();
    void slot_CrvApp();
    void slot_BlockParaApply();
    void slot_VoiceAlarm();
    void slot_PlatOrigin();
    void slot_PlatReset();
    void slot_PlatCtrl();
    void slot_MovMode();
    void slot_LaserCtrl();


private:
    Ui::MainWindow *ui;
    //mainWindow
    meshInterface MI;
    QLabel *lb_StRunTime;
    QLabel *lb_StLaserTime;
    QLabel *lb_StInfo;
    QTimer *timerRun;
    QStringList fileList;
    QStringList pathList;
    bool run;
    T TRun;
    T TLaser;
    ParaWindow *paraw;
    MarkWindow *markw;
    McurvWindow *mcurvw;
    Parameter *para;
    Crystal *crystal;
    Plat *plat;
    Scaner *scaner;
    Laser *laser;
    Motor *motor;
    CtrlCard *ctrlCard;

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
    BasicSettingsDialog::CrystalType curCrystalType = BasicSettingsDialog::BOX;
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
    void getTime(T *t);
    void spyPutIn();
    osg::Vec3Array *MainWindow::getVertexArray(osg::Node *node);
    void openFile(QString fileName);
    void setAxesVisible(bool visible);
    void updateRefShape(osg::Geode *geode);
    osg::Geode *createCrystalFrame(BasicSettingsDialog::CrystalType type, osg::Vec3 size, float zRot, float height, float diameter);
    void getPoints(const QString fileName);
    void slot_TimerRefresh();
    void readIO();
    void refreshIO();
};

#endif // MAINWINDOW_H
