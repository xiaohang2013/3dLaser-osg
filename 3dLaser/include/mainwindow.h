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

#include "osgContainer.h"
#include "ui_mainwindow.h"

#if _MSC_VER >= 1600
   #pragma execution_character_set("utf-8")
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStringList fPathList;


private slots:
    void slot_FileOpen(QString fPath);
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
    void slot_UpdateStBar();

private:
    Ui::MainWindow *ui;
    //mainWindow
    QLabel *lb_StRunTime;
    QLabel *lb_StLaserTime;
    QTimer *timerRun;
    //osgViewer
    osg::ref_ptr<osgContainer> curViewer;
    osg::ref_ptr<osg::Switch> curRoot;
    osg::ref_ptr<osg::Group> pointCloudGroup;
//function
    void initTimer();
    void initStBar();
    void initOSG();
    void initProjectionAsOrtho();

};

#endif // MAINWINDOW_H
