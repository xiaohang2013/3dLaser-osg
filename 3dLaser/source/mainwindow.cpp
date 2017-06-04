#include "QMessageBox"
#include <Windows.h>
#include <qdebug>
#include <QFileDialog>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>

#include "mainwindow.h"
#include "parawindow.h"
#include "markwindow.h"
#include "mcurvwindow.h"
#include "view.h"
#include "file.h"
using namespace std;


struct T
{
    int count;
    int hour;
    int minut;
    int second;
};
bool run = false;
T TRun;
T TLaser;
ParaWindow *paraw;
MarkWindow *markw;
McurvWindow *mcurvw;
View *v;
File *f;

void getTime(T *t);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    paraw  = new ParaWindow();
    markw  = new MarkWindow();
    mcurvw = new McurvWindow();

    initStBar();
    initOSG();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (timerRun)
        delete timerRun;
}

void MainWindow::slot_FileOpen(QString fPath)
{
    QStringList fp;
    if (fPath.isEmpty())
    {
        fp = QFileDialog::getOpenFileNames(this, tr("打开文件"), "", "", 0, 0);
    }
    else
    {
        fp.push_back(fPath);
    }
    if (!fp.isEmpty())
    {
        QString fName;
        foreach(fName, fp)
        {
            string str = fName.toLocal8Bit().data();
            osg::ref_ptr<osg::Node> fNode = osgDB::readNodeFile(str);
            if(fNode)
            {
                osg::ref_ptr<osg::MatrixTransform> mTrans = new osg::MatrixTransform;
                mTrans->addChild(fNode);
                //mTrans->setMatrix(osg::Matrix::translate(osg::Vec3d(0,0,0)));
                curViewer->getRoot()->addChild(mTrans);
                fPathList.push_back(fName);
            }
            else
            {
                QMessageBox::warning(this, tr("打开文件"), "文件打开错误", QMessageBox::Yes, QMessageBox::No);
            }
        }
    }
    else
    {
        QMessageBox::warning(this, tr("打开文件"), "文件打开错误", QMessageBox::Yes, QMessageBox::No);
    }

}

void MainWindow::slot_FileSave()
{

}

void MainWindow::slot_FileRecent()
{

}

void MainWindow::slot_FileExit()
{

}

void MainWindow::slot_FileClearPathList()
{
    fPathList.clear();
}

void MainWindow::slot_LaserPara()
{
    paraw->show();
}

void MainWindow::slot_LaserRegImp()
{

}

void MainWindow::slot_LaserRegExp()
{

}

void MainWindow::slot_LaserBatchSet()
{
    mcurvw->show();
}

void MainWindow::slot_LaserTagGen()
{
    markw->show();
}

void MainWindow::slot_LaserCal()
{

}

void MainWindow::slot_LaserPosTest()
{

}

void MainWindow::slot_LaserPlatSetH()
{

}

void MainWindow::slot_ViewTool()
{

}

void MainWindow::slot_ViewStat()
{

}

void MainWindow::slot_ViewCtrl()
{

}

void MainWindow::slot_ViewForth()
{
    osg::ref_ptr<MyTrackballManipulator> manipulator =
            dynamic_cast<MyTrackballManipulator *>(curViewer->getCameraManipulator());
    osg::Vec3d eye,center,up;
    manipulator->getHomePosition(eye,center,up);
    eye = osg::Vec3d(0.0,0.0,350.0);
    up = osg::Vec3d(0.0,1.0,0.0);

    manipulator->setHomePosition(eye,center,up);
    curViewer->home();//原点
    if(manipulator->isOrthoProjection())
        initProjectionAsOrtho();//若是正视投影，则将视图移至初始位（相当于该投影下的home点）
}

void MainWindow::slot_ViewTop()
{
    osg::ref_ptr<MyTrackballManipulator> manipulator =
            dynamic_cast<MyTrackballManipulator *>(curViewer->getCameraManipulator());
    osg::Vec3d eye,center,up;
    manipulator->getHomePosition(eye,center,up);

    eye = osg::Vec3d(0.0,350.0,0.0);
    up = osg::Vec3d(0.0,0.0,-1.0);
    manipulator->setHomePosition(eye,center,up);
    curViewer->home();//原点
    if(manipulator->isOrthoProjection())
        initProjectionAsOrtho();//若是正视投影，则将视图移至初始位（相当于该投影下的home点）
}

void MainWindow::slot_ViewRight()
{
    osg::ref_ptr<MyTrackballManipulator> manipulator =
            dynamic_cast<MyTrackballManipulator *>(curViewer->getCameraManipulator());
    osg::Vec3d eye,center,up;
    manipulator->getHomePosition(eye,center,up);
    eye = osg::Vec3d(350.0,0.0,0.0);
    up = osg::Vec3d(0.0,1.0,0.0);

    manipulator->setHomePosition(eye,center,up);
    curViewer->home();//原点
    if(manipulator->isOrthoProjection())
        initProjectionAsOrtho();//若是正视投影，则将视图移至初始位（相当于该投影下的home点）
}

void MainWindow::slot_ViewUpdate()
{

}

void MainWindow::slot_ViewOriModel()
{

}

void MainWindow::slot_ViewModModel()
{

}

void MainWindow::slot_ViewApartModel()
{

}
void MainWindow::slot_SortY2X(){}
void MainWindow::slot_SortX2Y(){}
void MainWindow::slot_SortOri(){}
void MainWindow::slot_SortShort(){}
void MainWindow::slot_BlockX2Y(){}
void MainWindow::slot_BlockY2X(){}
void MainWindow::slot_BlockShort(){}
void MainWindow::slot_BlockPara(){}
void MainWindow::slot_OperLaserOri(){}
void MainWindow::slot_OperPlatHome(){}
void MainWindow::slot_OperSetCurPos2LaserOri(){}
void MainWindow::slot_OperSaveCurPos2LaserOri(){}
void MainWindow::slot_DebugAtchModel(){}
void MainWindow::slot_DebugHotTest(){}
void MainWindow::slot_DebugSplitModel(){}
void MainWindow::slot_DebugStopFun(){}
void MainWindow::slot_StdModCube(){}
void MainWindow::slot_StdModLine(){}
void MainWindow::slot_StdModPlat(){}
void MainWindow::slot_StdModSphere(){}
void MainWindow::slot_HelpAboutMe(){}
void MainWindow::slot_LanCHN(){}
void MainWindow::slot_UpdateStBar()
{

    QString runText;
    QString laserText;
    TRun.count++;
    getTime(&TRun);
    runText = QString("总运行时间: %1:%2:%3")
            .arg(QString::number(TRun.hour))
            .arg(QString::number(TRun.minut))
            .arg(QString::number(TRun.second));
    lb_StRunTime->setText(runText);
    if (run)
        TLaser.count++;
    getTime(&TLaser);
    laserText = QString("总雕刻时间: %1:%2:%3")
            .arg(QString::number(TLaser.hour))
            .arg(QString::number(TLaser.minut))
            .arg(QString::number(TLaser.second));
    lb_StLaserTime->setText(laserText);
}

void getTime(T *t)
{
    if (NULL == t)
        qDebug()<<"null ptr";
    int count = t->count;
    t->second = count%60;
    count = count/60;
    t->minut = count%60;
    count = count/60;
    t->hour = count%60;
}

//################Private Function#############

void MainWindow::initStBar()
{
    lb_StRunTime = new QLabel(this);
    lb_StRunTime->setAlignment(Qt::AlignLeft);
    lb_StRunTime->setMaximumWidth(200);
    lb_StRunTime->setMinimumWidth(200);

    lb_StLaserTime = new QLabel(this);
    lb_StLaserTime->setAlignment(Qt::AlignLeft);
    lb_StLaserTime->setMaximumWidth(200);
    lb_StLaserTime->setMinimumWidth(200);

    statusBar()->addPermanentWidget(lb_StRunTime);
    statusBar()->addPermanentWidget(lb_StLaserTime);
    initTimer();

}
void MainWindow::initTimer()
{
    timerRun = new QTimer();
    if (!timerRun)
    {
        qDebug()<<"Fail init timer!";
        delete timerRun;
        return;
    }
    connect(timerRun, SIGNAL(timeout()), this, SLOT(slot_UpdateStBar()));
    //间隔1s
    timerRun->setInterval(1000);
    timerRun->start();
}

void MainWindow::initOSG()
{
    curViewer = new osgContainer();
    ui->ly_viewWt->addWidget(curViewer);
}
void MainWindow::initProjectionAsOrtho()
{
    osg::ref_ptr<osg::Camera> camera = curViewer->getCamera();
    osg::ref_ptr<osg::Viewport> viewport=camera->getViewport();
    double left = -viewport->width()*0.1;//正投影参数
    double right = -left;
    double bottom = -viewport->height()*0.1;
    double top = -bottom;
    double znear = -5000.;
    double zfar = 5000.;

    camera->setProjectionMatrixAsOrtho( left, right, bottom, top, znear, zfar);
}
