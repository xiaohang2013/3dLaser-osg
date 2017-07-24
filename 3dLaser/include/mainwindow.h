#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <QString>
#include <QMainWindow>
#include <QTimer>

#include <osg/MatrixTransform>
#include <osg/Vec3>
#include <osgManipulator/TabBoxDragger>
#include <osgManipulator/Selection>
#include <osgGA/GUIEventAdapter>
#include <osgManipulator/TrackballDragger>
#include <osgManipulator/TranslateAxisDragger>
#include <osgManipulator/ScaleAxisDragger>
#include <osgManipulator/CommandManager>

#include "osgContainer.h"
#include "ui_mainwindow.h"
#include "meshinterface.h"
#include "parameter.h"
#include "visitor.h"
#include "parawindow.h"
#include "markwindow.h"
#include "mcurvwindow.h"
#include "lasercalwindow.h"
#include "ctrlcard.h"

#if _MSC_VER >= 1600
   #pragma execution_character_set("utf-8")
#endif


#define TIMESPAN 1000
#define MAX_NUMFILES 10


namespace Ui {
class MainWindow;
}

class TimerData
{
public:
    unsigned int hour = 0;
    unsigned int minute = 0;
    unsigned int second = 0;

public:
    // 加一秒钟
    inline void incTick()
    {
        if(second+1<60) //秒+1
            second++;
        else            //分钟+1
        {
            if(minute<60)//分钟+1
            { minute++; second = 0; }
            else        //小时+1
            { hour++; minute = 0; second = 0; }
        }
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    const QString organization = "CrystalEngraving";    //组织名
    const QString appName = "3DCurving";                //应用名

    // 注册表组-软件信息
    const QString g_SoftwareInfo = "si";
    // 运行时间和雕刻时间，注：短名隐晦其含义
    const QString sRunningTime = "rt";
    const QString sEngravingTime = "et";
    // 最近打开的文件、路径
    const QString sRecentFileList = "recentFileList";
    const QString sRecentPathList = "recentPathList";



private slots:

    /**   文件菜单    **/
    bool on_FileOpen(QString fileName = QString());
    void on_ClearAll();
    void on_OpenRecentFile();
    void on_OpenRecentPath();
//    void slot_FileSave();
    void on_quitApplication();

    /**   机器参数    **/
    void on_ParameterSetting();
//    void slot_LaserPara();
//    void slot_LaserRegImp();
//    void slot_LaserRegExp();
//    void slot_LaserBatchSet();
//    void slot_LaserTagGen();
//    void slot_LaserCal();
//    void slot_LaserPosTest();
//    void slot_LaserPlatSetH();

//    /**   视图菜单    **/
//    void slot_ViewTool();
//    void slot_ViewStat();
//    void slot_ViewCtrl();
//    void slot_ViewForth();
//    void slot_ViewTop();
//    void slot_ViewRight();
//    void slot_ViewUpdate();
//    void slot_ViewOriModel();
//    void slot_ViewModModel();
//    void slot_ViewApartModel();

//    /**   排序菜单    **/
//    void slot_SortY2X();
//    void slot_SortX2Y();
//    void slot_SortOri();
//    void slot_SortShort();

//    /**   分块菜单    **/
//    void slot_BlockX2Y();
//    void slot_BlockY2X();
//    void slot_BlockShort();
//    void slot_BlockPara();

//    /**   操作菜单    **/
//    void slot_OperLaserOri();
//    void slot_OperPlatHome();
//    void slot_OperSetCurPos2LaserOri();
//    void slot_OperSaveCurPos2LaserOri();

//    /**   调试菜单    **/
//    void slot_DebugAtchModel();
//    void slot_DebugHotTest();
//    void slot_DebugSplitModel();
//    void slot_DebugStopFun();
//    void slot_StdModCube();
//    void slot_StdModLine();
//    void slot_StdModPlat();
//    void slot_StdModSphere();

//    /**   帮助菜单    **/
//    void slot_HelpAboutMe();

//    /**   语言菜单    **/
//    void slot_LanCHN();

//    /**   侧边栏    **/
//    void slot_MotorStop();
//    void slot_CrvView();
//    void slot_CrvApp();
//    void slot_PlatOrigin();
//    void slot_PlatReset();
//    void slot_PlatCtrl();
//    void slot_MovMode();
//    void slot_LaserCtrl();

    // 计时器
    void slot_TimerRefresh();
    void on_setAxesVisible(bool visible);

    // 私有方法
private:

    void initStatusBar();
    void initTimer();       //初始化运行时间计时器
    void endTimer();        //结束运行时间计时器
    void initSignalsAndSlots();
    void initActions();

    void initOSG();
    void initProjectionAsOrtho();
    void updateRefShape(osg::Geode *geode);
    void updateLighting(bool brightening);

    // 处理最近打开文件及路径列表
    void saveRecentFileList(const QString &fileName, bool isRemove=false);
    void saveRecentPathList(const QString &path, bool isRemove=false);
    void updateRecentFileAndPathActions();


    osg::Geode *createCrystalFrame(osg::Vec3 size, float zRot);


    osg::Vec3Array *getVertexArray(osg::Node *node);//获取顶点/点云
    void addPointsToPointCloudGroup(osg::Group *pcGroup, osg::Vec3Array *points, bool removeOld=true);
    void updateStatusBar(QString statusMsg=QString());



    // UI窗体/控件
private:

    // actions
    QAction *recentFileActs[MAX_NUMFILES];
    QAction *recentPathActs[MAX_NUMFILES];

    // statusbar content
    QSpacerItem* hSpacer1;
    QLabel *lb_totalRunTime;
    QLabel *lb_totalEngravingTime;
    QTimer runningTimer;    //计时器

    // 对话框
    MarkCodeWindow markCodeDialog;
    BatchEngravingDialog batchEngravingDialog;

private:

    Ui::MainWindow *ui;

    osg::ref_ptr<osgContainer> curViewer;
    osg::ref_ptr<osg::Switch> curRoot;
    osg::ref_ptr<osg::Geode> refShape;
    osg::ref_ptr<osg::Group> pointCloudGroup;


    meshInterface MI;   // 读取文件接口
    QDir lastUsedDirectory;


    bool isLaserOn = false;
    TimerData tdRunningTime;
    TimerData tdEngravingTime;

    osg::ref_ptr<sharedParameter> sharedPara = new sharedParameter;
    CtrlCard ctrlCard;

};

#endif // MAINWINDOW_H
