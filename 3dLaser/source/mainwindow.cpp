#include "QMessageBox"
#include <Windows.h>
#include <qdebug>
#include <QFileDialog>
#include "macro.h"
#include "mainwindow.h"
using namespace std;
#define TIMESPAN 20   //ms
#define INMAX 22
#define OUTMAX 9

int inPut[INMAX];
int outPut[OUTMAX];
osg::ref_ptr<osg::Vec3Array> g_Points;
const std::string domain_oriLayerMatrix = "oriLayerMatrix";//域名-层矩阵初始值域名
const std::string domain_lastUsedLayerMatrix = "lastUsedLayerMatrix";//域名-最近更新的层矩阵域名
const std::string domain_ordinaryLayerPrm = "ordinaryLayerPrm";//域名-普通层参数域名

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    parameterWindow  = new ParaWindow();
    markWindow  = new MarkWindow();
    mCurvWindow = new McurvWindow();
    ctrlCard = new CtrlCard();

    crystal = parameterWindow->getCrystalRef();
    motor = parameterWindow->getMotorRef();
    laser = parameterWindow->getLaserRef();
    scaner = parameterWindow->getScanerRef();
    plat = parameterWindow->getPlatRef();

    isLaserOn = false;
    initPara();
    initMainWindow();
    initCtrlBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (timerRun)
        delete timerRun;
    if (ctrlCard)
        delete ctrlCard;
}
#if 0
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
                fileList.push_back(fName);
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
#else
// Open 3D mesh model or 2D image
void MainWindow::slot_FileOpen()
{
    QStringList fl;
    if(fileList.isEmpty())
        fl = QFileDialog::getOpenFileNames(this,tr("打开文件"), "", MI.inputPointCloudFilters.join(";;"), 0, 0);
    else
        fl.push_back(fileList.first());

    if (fl.isEmpty())	return;
    else
    {
        //Save path away so we can use it again
        QString path = fl.first();
        path.truncate(path.lastIndexOf("/"));
        pathList.push_back(path);
    }
    openFile(fl.first());
}

void MainWindow::openFile(QString fileName)
{
    QFileInfo fi(fileName);
    QString extension = fi.suffix();
    bool b;
    b = MI.allKnowPointCloudInputFormats.contains(extension.toLower(),Qt::CaseSensitive);
    if(!b)
    {
        QString errorMsgFormat(tr("无法打开文件:\n\"%1\"\n\n详细信息: 文件格式 ") + extension + tr(" 不支持."));
        QMessageBox::critical(this,tr("文件打开错误"),errorMsgFormat.arg(fileName));
        return;
    }

    osg::ref_ptr<osg::Group> group = MI.openMesh(extension,fileName);
    getPoints(fileName);
    //以上各节点name均已不为空
    if(group)
    {
        group->setName(qPrintable(fi.fileName()));
        modelGroup->addChild(group);

        for(unsigned int i=0;i < group->getNumChildren(); i++)
        {
            osg::ref_ptr<osg::Node> node=group->getChild(i);//mt

            //保存用户自定义数据
            osg::ref_ptr<osg::MatrixTransform> mt = dynamic_cast<osg::MatrixTransform *>(node.get());
            mt->setUserValue(domain_oriLayerMatrix, mt->getMatrix());
            mt->setUserValue(domain_lastUsedLayerMatrix, mt->getMatrix());
        }

        g_Points = getVertexArray(group);
        int num=g_Points->size();
        crystal->pointCloud.pointNum = num;
        osg::Vec3 v3(g_Points->at(0));
        QMessageBox::information(this,"提示","num = " + QString("%1  %2  %3  %4").arg(num).arg(v3.x()).arg(v3.y()).arg(v3.z()));
        //显示模式：点云图
        updateOSGDisplay(POINTCLOUD);
        updateParam();
    }
    else
    {
        QMessageBox::critical(this,"Error", fileName + "  内容不被支持！");
        return;
    }
}
#endif

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
    fileList.clear();
}

void MainWindow::slot_LaserPara()
{
    parameterWindow->updatePara();
    parameterWindow->show();
}

void MainWindow::slot_LaserRegImp()
{

}

void MainWindow::slot_LaserRegExp()
{

}

void MainWindow::slot_LaserBatchSet()
{
    mCurvWindow->show();
}

void MainWindow::slot_LaserTagGen()
{
    markWindow->show();
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
void MainWindow::slot_OperSaveCurPos2LaserOri()
{
    plat->HomPos = plat->CurPos;
}
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

//主窗口刷新timer，TIMESPAN间隔刷新一次
void MainWindow::mwTimerRefresh()
{
    static int count = 0;
    QString runText;
    QString laserText;
    //刷新IO
    refreshIO();
    //检查是否触发限位，触发则停止电机
    checkIfStopMotor();

    //刷新时间
    count++;
    if (count >= (1000/TIMESPAN))
    {
        tdRunningTime.count++;
        getTime(&tdRunningTime);
        runText = QString("总运行时间: %1:%2:%3")
                .arg(QString::number(tdRunningTime.hour))
                .arg(QString::number(tdRunningTime.minut))
                .arg(QString::number(tdRunningTime.second));
        lb_StRunTime->setText(runText);
        if (isLaserOn)
            tdLaserOnTime.count++;
        getTime(&tdLaserOnTime);
        laserText = QString("总雕刻时间: %1:%2:%3")
                .arg(QString::number(tdLaserOnTime.hour))
                .arg(QString::number(tdLaserOnTime.minut))
                .arg(QString::number(tdLaserOnTime.second));
        lb_StLaserTime->setText(laserText);

        //刷新主窗口显示
        if (parameterWindow->getIsUpdate())
            updateParam();
        count = 0;
    }
}
void MainWindow::refreshIO()
{
    int i = 0;
    int rtn = 1;
    //输入
    for (i = 0; i< INMAX; i++)
    {
        inPut[i] = ctrlCard->readInput(i);
        if(-1 == inPut[i])
            qDebug()<<"IN"<<i<<"输入失败";
    }
    //输出
    for (i = 0; i< OUTMAX; i++)
    {
        rtn = ctrlCard->writeOutput(i, outPut[i]);
        if(1 == rtn)
            qDebug()<<"OUT"<<i<<"输出失败";
    }
}
void MainWindow::checkIfStopMotor()
{
    if (INPUT_L == inPut[X_LIMIT_N] || INPUT_L == inPut[X_LIMIT_P])
        ctrlCard->stopRun(motor->motorX.num, SUDDEN_STOP);
    if (INPUT_L == inPut[Y_LIMIT_N] || INPUT_L == inPut[Y_LIMIT_P])
        ctrlCard->stopRun(motor->motorY.num, SUDDEN_STOP);
    if (INPUT_L == inPut[Z_LIMIT_N] || INPUT_L == inPut[Z_LIMIT_P])
        ctrlCard->stopRun(motor->motorZ.num, SUDDEN_STOP);
}

void MainWindow::slot_MotorStop()
{
    for (int i = 0; i < MAXAXIS; i++)
    {
        ctrlCard->stopRun(i+1, SUDDEN_STOP);
    }
}

void MainWindow::slot_CrvView()
{

}

void MainWindow::slot_CrvApp()
{
    crystal->size.x = ui->le_CrvSizeX->text().toFloat();
    crystal->size.y = ui->le_CrvSizeY->text().toFloat();
    crystal->size.z = ui->le_CrvSizeZ->text().toFloat();
    crystal->mov.x = ui->le_MovX->text().toFloat();
    crystal->mov.y = ui->le_MovY->text().toFloat();
    crystal->mov.z = ui->le_MovZ->text().toFloat();
}


void MainWindow::slot_CrvStart()
{

}

void MainWindow::slot_CrvPause()
{

}

void MainWindow::slot_CrvStop()
{

}

void MainWindow::slot_PlatOrigin()
{

}

void MainWindow::slot_PlatReset()
{
    int rtn = ADTDRV_OK;
    int dir = 0;
    S_Motor m[MAXAXIS] = {motor->motorX, motor->motorY, motor->motorZ};
    for (int i=0; i < MAXAXIS; i++)
    {
        if (0 == dir && m[i].limitP)
            dir = 1;
        else if (0 == dir && m[i].limitN)
            dir = -1;
        rtn += ctrlCard->setSpeed(m[i].num, dir*m[i].v0, dir*m[i].v, m[i].a);
        if (ADTDRV_FAIL == rtn)
        {
            ctrlCard->stopRun(m[i].num, SUDDEN_STOP);
            lb_StInfo->setText("初始化速度错误");
            return;
        }
    }
}

void MainWindow::slot_PlatCtrl()
{

}

void MainWindow::slot_MovMode()
{

}

void MainWindow::slot_LaserCtrl()
{
    int rtn = ADTDRV_FAIL;
    QPushButton *pt = qobject_cast <QPushButton*>(sender());
    if ("开激光" == pt->text())
    {
        rtn = ctrlCard->setLaser(0, LASER_ON, laser->frequency, laser->ratio/100.0);
        if (ADTDRV_OK == rtn)
            ui->btn_CrvClsLas->setText("关激光");
        else
            lb_StInfo->setText("打开激光错误");
    }
    else if ("关激光" == pt->text())
    {
        rtn = ctrlCard->setLaser(0, LASER_OFF, laser->frequency, laser->ratio/100.0);
        if (ADTDRV_OK == rtn)
            ui->btn_CrvClsLas->setText("开激光");
        else
            lb_StInfo->setText("关闭激光错误");
    }
}

void MainWindow::getTime(TimerData *t)
{
    if (!t)
        qDebug()<<"null ptr";
    int count = t->count;
    t->second = count%60;
    count = count/60;
    t->minut = count%60;
    count = count/60;
    t->hour = count%60;
}

//################Private Function#############

void MainWindow::initMainWindow()
{
    updateParam();
    initStBar();
    initOSG();
}
void MainWindow::initPara()
{
    QFileInfo fi(INI_PATH);
    if (fi.isFile())
    {
        parameterWindow->readIniFile();
    }
    else
    {
        parameterWindow->initParam();
    }
    parameterWindow->updatePara();
}

void MainWindow::updateParam()
{
    //parameters crystal
    ui->lb_PointNumVal->setText(QString::number(crystal->pointCloud.pointNum, 10));
    ui->lb_PointMinValX->setText(QString::number(crystal->pointCloud.pointMin.x, 'f', 2));
    ui->lb_PointMinValY->setText(QString::number(crystal->pointCloud.pointMin.y, 'f', 2));
    ui->lb_PointMinValZ->setText(QString::number(crystal->pointCloud.pointMin.z, 'f', 2));
    ui->lb_PointMaxValX->setText(QString::number(crystal->pointCloud.pointMax.x, 'f', 2));
    ui->lb_PointMaxValY->setText(QString::number(crystal->pointCloud.pointMax.y, 'f', 2));
    ui->lb_PointMaxValZ->setText(QString::number(crystal->pointCloud.pointMax.z, 'f', 2));
    ui->lb_PointLenValX->setText(QString::number(crystal->pointCloud.pointMax.x-
                                                 crystal->pointCloud.pointMin.x, 'f', 2));
    ui->lb_PointLenValY->setText(QString::number(crystal->pointCloud.pointMax.y-
                                                 crystal->pointCloud.pointMin.y, 'f', 2));
    ui->lb_PointLenValZ->setText(QString::number(crystal->pointCloud.pointMax.z-
                                                 crystal->pointCloud.pointMin.z, 'f', 2));
    ui->lb_PointObjValX->setText(QString::number(crystal->size.x, 'f', 2));
    ui->lb_PointObjValY->setText(QString::number(crystal->size.y, 'f', 2));
    ui->lb_PointObjValZ->setText(QString::number(crystal->size.z, 'f', 2));

    //parameters plat
    ui->lb_PlatRelValX->setText(QString::number(plat->relPos.x, 'f', 2));
    ui->lb_PlatRelValY->setText(QString::number(plat->relPos.y, 'f', 2));
    ui->lb_PlatRelValZ->setText(QString::number(plat->relPos.z, 'f', 2));
    ui->lb_PlatValX->setText(QString::number(plat->size.x, 'f', 2));
    ui->lb_PlatValY->setText(QString::number(plat->size.y, 'f', 2));
    ui->lb_PlatValZ->setText(QString::number(plat->size.z, 'f', 2));

    ui->le_CrvSizeX->setText(QString::number(crystal->size.x, 'f', 2));
    ui->le_CrvSizeY->setText(QString::number(crystal->size.y, 'f', 2));
    ui->le_CrvSizeZ->setText(QString::number(crystal->size.z, 'f', 2));
    ui->le_MovX->setText(QString::number(crystal->mov.x, 'f', 2));
    ui->le_MovY->setText(QString::number(crystal->mov.y, 'f', 2));
    ui->le_MovZ->setText(QString::number(crystal->mov.z, 'f', 2));
}

void MainWindow::initStBar()
{
    lb_StInfo = new QLabel(this);
    lb_StInfo->setAlignment(Qt::AlignLeft);
    lb_StInfo->setMaximumWidth(200);
    lb_StInfo->setMinimumWidth(200);

    lb_StRunTime = new QLabel(this);
    lb_StRunTime->setAlignment(Qt::AlignLeft);
    lb_StRunTime->setMaximumWidth(200);
    lb_StRunTime->setMinimumWidth(200);

    lb_StLaserTime = new QLabel(this);
    lb_StLaserTime->setAlignment(Qt::AlignLeft);
    lb_StLaserTime->setMaximumWidth(200);
    lb_StLaserTime->setMinimumWidth(200);

    statusBar()->addPermanentWidget(lb_StInfo);
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
    connect(timerRun, SIGNAL(timeout()), this, SLOT(mwTimerRefresh()));
    //timer period
    timerRun->setInterval(TIMESPAN);
    timerRun->start();
}

void MainWindow::initOSG()
{
    curViewer = new osgContainer();
    refShape=new osg::Geode;
    modelGroup=new osg::Group;
    pointCloudGroup=new osg::Group;
    ui->ly_viewWt->addWidget(curViewer);

    curRoot = curViewer->getRoot();
    curRoot->addChild(refShape.get());
    curRoot->addChild(modelGroup.get());
    curRoot->addChild(pointCloudGroup.get());

    pointCloudGroup->addChild(ordinaryPointsGroup.get());
    pointCloudGroup->addChild(texturePointsGroup.get());
    pointCloudGroup->addChild(picturePointsGroup.get());
    pointCloudGroup->addChild(additionalPointsGroup.get());


    initProjectionAsOrtho();
    setAxesVisible(true);
    updateLighting(false);

//    updateRefShape(createCrystalFrame(curCrystalType, curCrystalSize, curCrystalZRot, curCrystalHeight, curCrystalDiameter));

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

int MainWindow::initCtrlBoard()
{
    int rtn = CTRL_ERROR;
    int msgRtn = 0;
    //*************初始化8940A1卡**************
    rtn = ctrlCard->initBoard();
    if (rtn <= 0)
    {
        msgRtn = QMessageBox::warning(this, "错误", "控制卡初始化失败!", QMessageBox::Ok);
        if (QMessageBox::Ok == msgRtn)
        {
            lb_StInfo->setText("控制卡初始化失败!");
        }
        switch (rtn)
        {
        case CTRL_NO_CARD_ERROR:
            msgRtn = QMessageBox::warning(this, "错误", "没有安装ADT8937卡!", QMessageBox::Ok);
            if (QMessageBox::Ok == msgRtn)
            {
                lb_StInfo->setText("没有安装ADT8937卡!");
            }
            break;
        case CTRL_NO_DRIVE_ERROR:
            msgRtn = QMessageBox::warning(this, "错误", "没有安装端口驱动程序!", QMessageBox::Ok);
            if (QMessageBox::Ok == msgRtn)
            {
                lb_StInfo->setText("没有安装端口驱动程序!");
            }
            break;
        case CTRL_PCI_ERROR:

            msgRtn = QMessageBox::warning(this, "错误", "PCI桥故障!", QMessageBox::Ok);
            if (QMessageBox::Ok == msgRtn)
            {
                lb_StInfo->setText("PCI桥故障!");
            }
            break;
         default:
            break;
        }
    }
    else
    {
        lb_StInfo->setText("运动控制卡可以使用!");
    }
    //*************获取版本号**************
    int ver = ctrlCard->getHardWareVer();
    QString str = "硬件版本:"+ QString::number(ver, 10);
    lb_StInfo->setText(str);
    //*************初始化限位**************
    S_Motor m[MAXAXIS] = {motor->motorX, motor->motorY, motor->motorZ};
    for (int i = 0; i< MAXAXIS; i++)
    {
        rtn += ctrlCard->setLimit(0, m[i].num, m[i].limitP, m[i].limitN, m[i].limitL);
    }
    if (ADTDRV_FAIL == rtn)
    {
        QMessageBox::warning(this, "错误", "初始化限位错误", QMessageBox::Ok);
    }
    //*************初始化速度**************
    for (int i = 0; i< MAXAXIS; i++)
    {
        rtn += ctrlCard->setSpeed(m[i].num, m[i].v0, m[i].v, m[i].a);
    }
    if (ADTDRV_FAIL == rtn)
    {
        QMessageBox::warning(this, "错误", "轴速度设置失败", QMessageBox::Ok);
        return rtn;
    }
    //*************初始化激光延时**************
    ctrlCard->setLaserOutDelay(0, laser->lightOutDelay);

    return rtn;
}

//为node设置用户自定义数据
//这里主要是用来为模型或图片层设置 点云参数
void MainWindow::setUserPrmForNode(osg::Node *node, Parameter *prm)
{
    node->setUserData(prm);
}
//更新显示模式（实体/线框/点云）
void MainWindow::updateOSGDisplay(DisplayMode mode)
{
    osg::ref_ptr<osg::StateSet> stateset=modelGroup->getOrCreateStateSet();
    osg::ref_ptr<osg::PolygonMode> pm=new osg::PolygonMode;
    switch(mode)
    {
        case POINTCLOUD:
            setPointCloudVisible(true);
            updateLighting(true);
            break;
        default:
            break;
    }
}

void MainWindow::setPointCloudVisible(bool visible)
{
    curRoot->setChildValue(pointCloudGroup, visible);
}
/// 更新OSG环境光照
void MainWindow::updateLighting(bool brightening)
{
    if(!curViewer) return;
    if(brightening)//环境光增强
    {
        curViewer->getLight()->setDiffuse(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
        curViewer->getLight()->setAmbient(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
    }
    else//不增强
    {
        curViewer->getLight()->setDiffuse(osg::Vec4(0.7f, 0.7f, 0.7f, 1.0f));
        curViewer->getLight()->setAmbient(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
    }
}
osg::Vec3Array *MainWindow::getVertexArray(osg::Node *node)
{
    vertexExtractor ve;
    node->accept(ve);
    return ve.getAllVertexArrayInWorldCoord();
}
/// 设置坐标轴可见性
void MainWindow::setAxesVisible(bool visible)
{
    curViewer->setAxesVisible(visible);
}
// 更新Ref shape
void MainWindow::updateRefShape(osg::Geode *geode)
{
    curRoot->removeChild(refShape);
    refShape = geode;
    curRoot->addChild(refShape);
}

void MainWindow::getPoints(const QString fileName)
{
    QFile in(fileName);
    QString line;
    bool isMin = false;
    bool isMax = false;
    if (!in.open(QIODevice::ReadOnly)) return;
        QTextStream f(&in);
        line = f.readLine();
        while(!line.isNull())
        {
            if ("$EXTMIN" == line)
            {
                while ("9" != line && "ENDSEC" != line && !line.isNull())
                {
                    line = f.readLine();
                    if ("10" == line)
                    {
                        line = f.readLine();
                        if (!line.isNull())
                            crystal->pointCloud.pointMin.x = line.toFloat();
                    }
                    if ("20" == line)
                    {
                        line = f.readLine();
                        if (!line.isNull())
                            crystal->pointCloud.pointMin.y = line.toFloat();
                    }
                    if ("30" == line)
                    {
                        line = f.readLine();
                        if (!line.isNull())
                            crystal->pointCloud.pointMin.z = line.toFloat();
                    }
                }
                isMin = true;
            }
            if ("$EXTMAX" == line)
            {
                while ("9" != line && "ENDSEC" != line && !line.isNull())
                {
                    line = f.readLine();
                    if ("10" == line)
                    {
                        line = f.readLine();
                        if (!line.isNull())
                            crystal->pointCloud.pointMax.x = line.toFloat();
                    }
                    if ("20" == line)
                    {
                        line = f.readLine();
                        if (!line.isNull())
                            crystal->pointCloud.pointMax.y = line.toFloat();
                    }
                    if ("30" == line)
                    {
                        line = f.readLine();
                        if (!line.isNull())
                            crystal->pointCloud.pointMax.z = line.toFloat();
                    }
                }
                isMax = true;
            }
            if (isMin && isMax)
                return;
            line = f.readLine();
        }
}
