#include <QMessageBox>
#include <Windows.h>
#include <qdebug>
#include <QFileDialog>

#include "macro.h"
#include "mainwindow.h"

using namespace std;




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCoreApplication::setOrganizationName(organization);
    QCoreApplication::setApplicationName(appName);

    ParamWindow::readParamFromRegistry(sharedPara.get());

    initOSG();
    initActions();
    updateRecentFileAndPathActions();
    initStatusBar();
    initTimer();
    initSignalsAndSlots();

//    initPara();
//    initMainWindow();
//    initCtrlBoard();
}

MainWindow::~MainWindow()
{
    // 结束计时
    endTimer();

    delete ui;
}

// Open points cloud file(.dxf)
bool MainWindow::on_FileOpen(QString fileName)
{
    QStringList fileNameList;
    if(fileName.isEmpty())
        fileNameList = QFileDialog::getOpenFileNames(this,tr("导入点云"), lastUsedDirectory.path(), MI.inputPointCloudFilters.join(";;"));
    else
        fileNameList.push_back(fileName);

    if (fileNameList.isEmpty())	return false;
    else
    {
        //Save path away so we can use it again
        QString path = fileNameList.first();
        path.truncate(path.lastIndexOf("/"));
        lastUsedDirectory.setPath(path);

        if(!lastUsedDirectory.path().isEmpty())
            saveRecentPathList(lastUsedDirectory.path());
    }

    QTime time;
    time.start();
    foreach(fileName,fileNameList)
    {
        QFileInfo fi(fileName);
        QString extension = fi.suffix();
        bool b;
        b = MI.allKnowPointCloudInputFormats.contains(extension.toLower(),Qt::CaseSensitive);
        if(!b)
        {
            QString errorMsgFormat(tr("无法打开文件:\n\"%1\"\n\n详细信息: 文件格式 ") + extension + tr(" 不支持."));
            QMessageBox::critical(this,tr("文件打开错误"),errorMsgFormat.arg(fileName));
            return false;
        }

        osg::ref_ptr<osg::Group> group = MI.openMesh(extension,fileName);
        //以上各节点name均已不为空
        if(group)
        {
            osg::ref_ptr<osg::Vec3Array> points=getVertexArray(group.get());
            if(points->size()>0)//添加点云并切换至点云显示模式
                addPointsToPointCloudGroup(pointCloudGroup.get(), points.get(),false);
        }
        else
        {
            QMessageBox::critical(this,tr("错误"), fileName + tr("  内容不被支持！"));
            return false;
        }

        saveRecentFileList(fileName);
    }

    updateStatusBar(QString::number(time.elapsed()/1000.f)+"s");
    return true;
}

void MainWindow::on_ClearAll()
{
    pointCloudGroup->removeChildren(0, pointCloudGroup->getNumChildren());
}

void MainWindow::on_OpenRecentFile()
{
    QAction *action = (QAction *)(sender());
    QString fileName = action->data().toString();
    QFileInfo fi(fileName);
    if(fi.isFile())
        on_FileOpen(fileName);
    else
        saveRecentFileList(fileName, true);
}

void MainWindow::on_OpenRecentPath()
{
    QAction *action = (QAction *)(sender());
    QString path = action->data().toString();
    QDir dir(path);
    QFileInfo fi(path);
    if(dir.exists() && fi.isDir())
    {
        lastUsedDirectory.setPath(path);
        on_FileOpen();
    }
    else
        saveRecentPathList(path, true);
}

void MainWindow::on_quitApplication()
{
    this->close();
}

void MainWindow::on_ParameterSetting()
{
    ParamWindow paraDialog(sharedPara.get());
    paraDialog.exec();
}

void MainWindow::slot_TimerRefresh()
{
    tdRunningTime.incTick();
    if(isLaserOn) tdEngravingTime.incTick();

    QString str = QString("总运行时间: %1:%2:%3")
            .arg(QString::number(tdRunningTime.hour))
            .arg(tdRunningTime.minute,2,10,QChar('0'))
            .arg(tdRunningTime.second,2,10,QChar('0'));
    lb_totalRunTime->setText(str);

    str = QString("总雕刻时间: %1:%2:%3")
            .arg(QString::number(tdEngravingTime.hour))
            .arg(tdEngravingTime.minute,2,10,QChar('0'))
            .arg(tdEngravingTime.second,2,10,QChar('0'));
    lb_totalEngravingTime->setText(str);
}

void MainWindow::on_setAxesVisible(bool visible)
{
    curViewer->setAxesVisible(visible);
}

void MainWindow::initStatusBar()
{
    hSpacer1 = new QSpacerItem(90,25,QSizePolicy::Minimum,QSizePolicy::Expanding);
    ui->statusBar->layout()->addItem(hSpacer1);

    lb_totalRunTime = new QLabel(this);
    lb_totalRunTime->setAlignment(Qt::AlignLeft);
    lb_totalRunTime->setMaximumWidth(200);
    lb_totalRunTime->setMinimumWidth(200);

    lb_totalEngravingTime = new QLabel(this);
    lb_totalEngravingTime->setAlignment(Qt::AlignLeft);
    lb_totalEngravingTime->setMaximumWidth(200);
    lb_totalEngravingTime->setMinimumWidth(200);

    ui->statusBar->layout()->addWidget(lb_totalRunTime);
    ui->statusBar->layout()->addWidget(lb_totalEngravingTime);
}
void MainWindow::initTimer()
{
    connect(&runningTimer, SIGNAL(timeout()), this, SLOT(slot_TimerRefresh()));
    runningTimer.setInterval(TIMESPAN);
    runningTimer.start();

    // 初始化时间计数器
    QSettings settings;
    settings.beginGroup(g_SoftwareInfo);
    unsigned int runningSeconds = settings.value(sRunningTime, QVariant((unsigned int)0)).toUInt();
    unsigned int engravingSeconds = settings.value(sEngravingTime, QVariant((unsigned int)0)).toUInt();
    settings.endGroup();

    tdRunningTime.hour = runningSeconds/3600;
    tdRunningTime.minute = runningSeconds%3600/60;
    tdRunningTime.second = runningSeconds%60;
    tdEngravingTime.hour = engravingSeconds/3600;
    tdEngravingTime.minute = engravingSeconds%3600/60;
    tdEngravingTime.second = engravingSeconds%60;
}

void MainWindow::endTimer()
{
    runningTimer.stop();

    // 运行时间保存至注册表
    QSettings settings;
    settings.beginGroup(g_SoftwareInfo);
    settings.setValue(sRunningTime, QVariant((unsigned int)(tdRunningTime.hour*3600+tdRunningTime.minute*60+tdRunningTime.second)));
    settings.setValue(sEngravingTime, QVariant((unsigned int)(tdEngravingTime.hour*3600+tdEngravingTime.minute*60+tdEngravingTime.second)));
    settings.endGroup();
    settings.sync();
}

void MainWindow::initSignalsAndSlots()
{
    connect(ui->action_FileOpen, SIGNAL(triggered()), this, SLOT(on_FileOpen()));
    connect(ui->action_ClearAll, SIGNAL(triggered()), this, SLOT(on_ClearAll()));
    connect(ui->action_QuitApp, SIGNAL(triggered()), this, SLOT(on_quitApplication()));

    connect(ui->action_ParameterSettings, SIGNAL(triggered()), this, SLOT(on_ParameterSetting()));
}

void MainWindow::initActions()
{
    for(int i=0;i<MAX_NUMFILES;++i)
    {
        recentFileActs[i]=new QAction(this);
        recentFileActs[i]->setVisible(true);
        recentFileActs[i]->setEnabled(true);

        recentPathActs[i]=new QAction(this);
        recentPathActs[i]->setVisible(true);
        recentPathActs[i]->setEnabled(true);
        connect(recentFileActs[i],SIGNAL(triggered()),this,SLOT(on_OpenRecentFile()));
        connect(recentPathActs[i],SIGNAL(triggered()),this,SLOT(on_OpenRecentPath()));

        ui->menu_RecentFileList->addAction(recentFileActs[i]);
        ui->menu_RecentPathList->addAction(recentPathActs[i]);
    }
}

void MainWindow::initOSG()
{
    curViewer = new osgContainer();
    refShape=new osg::Geode;
    pointCloudGroup=new osg::Group;
    this->setCentralWidget(curViewer.get());

    curRoot = curViewer->getRoot();
    curRoot->addChild(refShape.get());
    curRoot->addChild(pointCloudGroup.get());

    initProjectionAsOrtho();
    on_setAxesVisible(true);
    updateRefShape(createCrystalFrame(sharedPara->crystalSize, 0.f));
    updateLighting(true);
}

void MainWindow::initProjectionAsOrtho()
{
    osg::ref_ptr<osg::Camera> camera = curViewer->getCamera();
    osg::ref_ptr<osg::Viewport> viewport=camera->getViewport();
    double left = -viewport->width()*0.1;   //正投影参数
    double right = -left;
    double bottom = -viewport->height()*0.1;
    double top = -bottom;
    double znear = -5000.;
    double zfar = 5000.;

    camera->setProjectionMatrixAsOrtho( left, right, bottom, top, znear, zfar);
}

void MainWindow::updateRefShape(osg::Geode *geode)
{
    curRoot->removeChild(refShape);
    refShape = geode;
    curRoot->addChild(refShape);
}

/// 更新OSG环境光照
void MainWindow::updateLighting(bool brightening)
{
    if(!curViewer) return;
    curViewer->updateLighting(brightening);
}

/// 保存最近打开的文件列表
/// @param fileName:将要添加/移除的文件
/// @param isRemove:是否是移除当前fileName项，是：则移除； 否：则为添加该项
void MainWindow::saveRecentFileList(const QString &fileName, bool isRemove)
{
    QSettings settings;
    settings.beginGroup(g_SoftwareInfo);
    QStringList files = settings.value(sRecentFileList).toStringList();
    files.removeAll(fileName);
    if(!isRemove)   //不是移除该项，则即为添加该项
        files.prepend(fileName);
    while(files.size()>MAX_NUMFILES)
        files.removeLast();

    settings.setValue(sRecentFileList, QVariant(files));
    settings.endGroup();

    updateRecentFileAndPathActions();
}

/// 保存最近打开的文件夹
/// @param path:将要添加/移除的文件夹
/// @param isRemove:是否是移除当前path项，是：则移除； 否：则为添加该项
void MainWindow::saveRecentPathList(const QString &path, bool isRemove)
{
    QSettings settings;
    settings.beginGroup(g_SoftwareInfo);
    QStringList paths = settings.value(sRecentPathList).toStringList();
    paths.removeAll(path);
    if(!isRemove)   //不是移除该项，则即为添加该项
        paths.prepend(path);
    while(paths.size()>MAX_NUMFILES)
        paths.removeLast();

    settings.setValue(sRecentPathList, QVariant(paths));
    settings.endGroup();

    updateRecentFileAndPathActions();
}

// 更新最近打开文件及路径列表
void MainWindow::updateRecentFileAndPathActions()
{
    QSettings settings;
    settings.beginGroup(g_SoftwareInfo);
    QStringList files = settings.value(sRecentFileList).toStringList();
    QStringList paths = settings.value(sRecentPathList).toStringList();
    settings.endGroup();

    int numRecentFiles = qMin(files.size(), (int)MAX_NUMFILES);

    for (int i = 0; i < numRecentFiles; ++i)
    {
        QString text = QString("&%1 %2").arg(i + 1).arg(QFileInfo(files[i]).fileName());
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MAX_NUMFILES; ++j)
        recentFileActs[j]->setVisible(false);


    int numRecentPaths = qMin(paths.size(), (int)MAX_NUMFILES);

    for(int i=0; i<numRecentPaths; ++i)
    {
        QString text = QString("&%1 %2").arg(i + 1).arg(paths[i]);
        recentPathActs[i]->setText(text);
        recentPathActs[i]->setData(paths[i]);
        recentPathActs[i]->setVisible(true);
    }
    for (int j = numRecentPaths; j < MAX_NUMFILES; ++j)
        recentPathActs[j]->setVisible(false);
}

osg::Geode *MainWindow::createCrystalFrame(osg::Vec3 size, float zRot)
{
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
    osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
    osg::ref_ptr<osg::Vec4Array> colors=new osg::Vec4Array;
    colors->push_back(osg::Vec4(1.f,1.f,0.f,1.f));
    geom->setColorArray(colors);
    geom->setColorBinding(osg::Geometry::BIND_OVERALL);
    geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
    geode->addDrawable(geom);

    //    if(type==BasicSettingsDialog::BOX)
    {
        v->push_back(osg::Vec3(-0.5f*size.x(), -0.5f*size.y(), -0.5f*size.z()));
        v->push_back(osg::Vec3(0.5f*size.x(), -0.5f*size.y(), -0.5f*size.z()));
        v->push_back(osg::Vec3(0.5f*size.x(), 0.5f*size.y(), -0.5f*size.z()));
        v->push_back(osg::Vec3(-0.5f*size.x(), 0.5f*size.y(), -0.5f*size.z()));

        v->push_back(osg::Vec3(-0.5f*size.x(), -0.5f*size.y(), 0.5f*size.z()));
        v->push_back(osg::Vec3(0.5f*size.x(), -0.5f*size.y(), 0.5f*size.z()));
        v->push_back(osg::Vec3(0.5f*size.x(), 0.5f*size.y(), 0.5f*size.z()));
        v->push_back(osg::Vec3(-0.5f*size.x(), 0.5f*size.y(), 0.5f*size.z()));

        if(zRot != 0)
        {
            osg::Matrix m = osg::Matrix::rotate(osg::DegreesToRadians(zRot), osg::Vec3(0.f,0.f,1.f));
            for(unsigned int i=0; i<v->size(); ++i)
            {
                osg::Vec4 vt4(v->at(i),1.0f);
                vt4=vt4*m;
                v->at(i) = osg::Vec3(vt4.x(),vt4.y(),vt4.z());
            }
        }

        geom->setVertexArray(v.get());
        osg::ref_ptr<osg::DrawElementsUInt> lines = new osg::DrawElementsUInt(osg::PrimitiveSet::LINES, 0);
        for(int i=0; i<8; ++i)
        {
            int j= i+1;
            if(i==3) j=0;
            else if(i==7) j=4;
            lines->push_back(i);
            lines->push_back(j);
        }
        for(int i=0; i<4; ++i)
        {
            lines->push_back(i);
            lines->push_back(i+4);
        }
        geom->addPrimitiveSet(lines);
    }
    return geode.release();
}

osg::Vec3Array *MainWindow::getVertexArray(osg::Node *node)
{
    vertexExtractor ve;
    node->accept(ve);
    return ve.getAllVertexArrayInWorldCoord();
}

void MainWindow::addPointsToPointCloudGroup(osg::Group *pcGroup, osg::Vec3Array *points, bool removeOld)
{
    if(!points || points->size()<=0) return;
    osg::ref_ptr<osg::Geode> geode=new osg::Geode;
    osg::ref_ptr<osg::Geometry> geom=new osg::Geometry;
    geom->setVertexArray(points);
    osg::ref_ptr<osg::Vec4Array> ca = new osg::Vec4Array();
    osg::Vec4 white = osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f);
    ca->resize(points->size(), white);
    geom->setColorArray(ca.get());
    geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

    geom->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, points->size()));
    geode->addDrawable(geom);
    osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform;
    mt->addChild(geode.get());

    if(removeOld)
        pcGroup->removeChildren(0, pcGroup->getNumChildren());
    pcGroup->addChild(mt.get());
}

void MainWindow::updateStatusBar(QString statusMsg)
{
    if(!statusMsg.isEmpty())
        ui->statusBar->showMessage(statusMsg, 2000);
}
