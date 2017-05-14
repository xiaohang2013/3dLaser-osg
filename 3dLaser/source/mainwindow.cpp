#include "QMessageBox"
#include <Windows.h>
#include <QFileDialog>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parawindow.h"
#include "markwindow.h"
#include "mcurvwindow.h"
#include "view.h"
#include "file.h"
using namespace std;


ParaWindow *paraw;
MarkWindow *markw;
McurvWindow *mcurvw;
View *v;
File *f;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    paraw  = new ParaWindow();
    markw  = new MarkWindow();
    mcurvw = new McurvWindow();

    v = new View();
    f = new File();

    init_OSG();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_FileOpen()
{
    QStringList fPathList;

    fPathList = QFileDialog::getOpenFileNames(this, tr("打开文件"), "", "", 0, 0);
    if (!fPathList.isEmpty())
    {
        QString fName;
        foreach(fName, fPathList)
        {
            string str = fName.toLocal8Bit().data();
            osg::ref_ptr<osg::Node> fNode = osgDB::readNodeFile(str);
            if(fNode)
            {
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

}

void MainWindow::slot_ViewTop()
{

}

void MainWindow::slot_ViewRight()
{

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

void MainWindow::init_OSG()
{
    curViewer = new osgContainer();
    this->setCentralWidget(curViewer);
}


//################Private Function#############
