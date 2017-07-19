#include "parawindow.h"
#include "ui_parawindow.h"
#include "macro.h"
#include <QSettings>

ParamWindow::ParamWindow(sharedParameter *sharedPrm, QWidget *parent) :
    _sharedPrm(sharedPrm),
    QDialog(parent),
    ui(new Ui::ParaWindow)
{
    ui->setupUi(this);

    this->resize(634, 503);
    setWindowFlags(Qt::Popup | Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint;
    QSizePolicy policy = this->sizePolicy();
    policy.setHorizontalPolicy(QSizePolicy::Fixed);
    policy.setVerticalPolicy(QSizePolicy::Fixed);
    this->setSizePolicy(policy);

    initActionsAndSlots();
    on_sortingMethod();
    setSharedParamToUI(_sharedPrm);
}

ParamWindow::~ParamWindow()
{
    delete ui;
}

void ParamWindow::initParam()
{
    /****************    排序方法界面参数     ****************/
    //**   水晶   **
    _sharedPrm->crystalSize.set(60.f,60.f,60.f);
    //**   排序方法   **
    _sharedPrm->sortingMethod = Sorting_ShortestPath;    //排序方法
    _sharedPrm->blockWidth = 1.f;       //块宽度
    _sharedPrm->boundaryDisable = 0.1f; //模糊比例
    //**   点云模型   **
    _sharedPrm->minLayerDis = 0.088f;   //最小分层间距
    _sharedPrm->distortionCorr = Correct_YX;    //扭曲校正
    //**   分块参数   **
    _sharedPrm->borderType = Border_Inclined;   //边界类型
    _sharedPrm->blockSize.set(25.f,25.f,0.1f);  //分块大小
    _sharedPrm->borderWidth = 30.f;             //边界参数，宽度
    _sharedPrm->borderAngle = 5.f;              //边界参数，倾斜角度

    /****************    激光振镜界面参数     ****************/
    //**   激光测试   **
    _sharedPrm->testRatio = 0.3f;       //比率（占空比）
    _sharedPrm->testFrequency = 3000;   //HZ,测试频率
    _sharedPrm->focalLength = 120.f;     //mm,激光焦距
    _sharedPrm->simmerTime = 0;         //s，激光预热时间
    _sharedPrm->laserDelay = 205;    //us，激光出光延时
    //**   设置   **
    _sharedPrm->scannerDelay = 500;      //us,振镜延时
    _sharedPrm->scannerSpeed = 4130;     //bit/ms,振镜速度
    _sharedPrm->microStepDelay = 10;    //us,微步延时
    _sharedPrm->isScannerXYExchange = false;    //是否 振镜XY互换
    _sharedPrm->isMicroStepOver = true;        //是否 微步跳转
    //**   振镜标定参数   **
    _sharedPrm->scannerRatio[AXISX] = -172.34f;
    _sharedPrm->scannerAdjust[AXISX] = 0.f;
    _sharedPrm->scannerPlatformAdjust[AXISX] = 0.f;
    _sharedPrm->scannerRatio[AXISY] = 171.66f;
    _sharedPrm->scannerAdjust[AXISY] = 0.f;
    _sharedPrm->scannerPlatformAdjust[AXISY] = 0.f;

    /****************    平台电机界面参数     ****************/
    // 三电机的参数
    _sharedPrm->motorRatio[AXISX] = 640.f;  //电机减速比，pulse/mm
    _sharedPrm->motorRatio[AXISY] = 640.f;
    _sharedPrm->motorRatio[AXISZ] = 427.f;
    // 微调
    _sharedPrm->margin[AXISX] = 0.f;        //电机精调，pulse
    _sharedPrm->margin[AXISY] = 0.f;
    _sharedPrm->margin[AXISZ] = 0.f;
    // 初始偏移
    _sharedPrm->initOffset[AXISX] = 295.f;  //初始偏移，mm
    _sharedPrm->initOffset[AXISY] = 20.f;
    _sharedPrm->initOffset[AXISZ] = 200.f;
    // 起始速度
    _sharedPrm->startSpeed[AXISX] = 6000;   //起始速度，p/s
    _sharedPrm->startSpeed[AXISY] = 6000;
    _sharedPrm->startSpeed[AXISZ] = 6000;
    // 匀速
    _sharedPrm->runSpeed[AXISX] = 16000;    //匀速，p/s
    _sharedPrm->runSpeed[AXISY] = 19200;
    _sharedPrm->runSpeed[AXISZ] = 15000;
    // 加速度
    _sharedPrm->acc[AXISX] = 50000;         //加速度，p/s^2
    _sharedPrm->acc[AXISY] = 50000;
    _sharedPrm->acc[AXISZ] = 50000;
    // 平台调整
    _sharedPrm->reversePlatformX = true;         //平台X方向反转
    _sharedPrm->reversePlatformY = true;         //平台Y方向反转
    _sharedPrm->reversePlatformZ = false;        //平台Z方向反转
    _sharedPrm->reverseScannerXY = false;   //振镜XY方向反转
    _sharedPrm->reverseScannerZ = false;    //振镜Z方向反转
    _sharedPrm->isSphereMachine = false;    //雕球机
}

void ParamWindow::readParamFromRegistry(sharedParameter *sharedPrm)
{
    if(!sharedPrm) return;

    float x,y,z;
    QSettings settings;

    ///------ begin group
    settings.beginGroup(g_CrystalPrm);
    /****************    排序方法界面参数     ****************/
    //**   水晶   **
    x = settings.value(crystalSizeX, QVariant(60.f)).toFloat();
    y = settings.value(crystalSizeY, QVariant(60.f)).toFloat();
    z = settings.value(crystalSizeZ, QVariant(60.f)).toFloat();
    sharedPrm->crystalSize.set(x,y,z);
    //**   排序方法   **
    sharedPrm->sortingMethod = (SortingMethod)settings.value(sortMethod, QVariant(Sorting_ShortestPath)).toInt();  //排序方法
    sharedPrm->blockWidth = settings.value(blockWidth, QVariant(1.f)).toFloat();               //块宽度
    sharedPrm->boundaryDisable = settings.value(boundaryDisable, QVariant(0.1f)).toFloat();    //模糊比例
    //**   点云模型   **
    sharedPrm->minLayerDis = settings.value(minLayerDis, QVariant(0.088f)).toFloat();          //最小分层间距
    sharedPrm->distortionCorr = (DistortionCorrection)settings.value(distortionCorr, QVariant(Correct_YX)).toInt();    //扭曲校正
    //**   分块参数   **
    sharedPrm->borderType = (BorderType)settings.value(borderType, QVariant(Border_Inclined)).toInt(); //边界类型
    x = settings.value(blockSizeX, QVariant(25.f)).toFloat();
    y = settings.value(blockSizeY, QVariant(25.f)).toFloat();
    z = settings.value(blockSizeZ, QVariant(0.1f)).toFloat();
    sharedPrm->blockSize.set(x,y,z);   //分块大小
    sharedPrm->borderWidth = settings.value(borderWidth, QVariant(30.f)).toFloat();    //边界参数，宽度
    sharedPrm->borderAngle = settings.value(borderAngle, QVariant(5.f)).toFloat();     //边界参数，倾斜角度
    settings.endGroup();
    ///------ end group

    ///------ begin group
    settings.beginGroup(g_MachinePrm);
    /****************    激光振镜界面参数     ****************/
    //**   激光测试   **
    sharedPrm->testRatio = settings.value(testRatio, QVariant(0.3f)).toFloat();    //比率（占空比）
    sharedPrm->testFrequency = settings.value(testFrequency, QVariant(3000)).toInt();  //HZ,测试频率
    sharedPrm->focalLength = settings.value(focalLength, QVariant(120.f)).toFloat();   //mm,激光焦距
    sharedPrm->simmerTime = settings.value(simmerTime, QVariant(0)).toInt();       //s，激光预热时间
    sharedPrm->laserDelay = settings.value(laserDelay, QVariant(205)).toInt();     //us，激光出光延时
    //**   设置   **
    sharedPrm->scannerDelay = settings.value(scannerDelay, QVariant(500)).toInt(); //us,振镜延时
    sharedPrm->scannerSpeed = settings.value(scannerSpeed, QVariant(4130)).toInt();    //bit/ms,振镜速度
    sharedPrm->microStepDelay = settings.value(microStepDelay, QVariant(10)).toInt();  //us,微步延时
    sharedPrm->isScannerXYExchange = settings.value(scannerXYExchange, QVariant(false)).toBool();  //是否 振镜XY互换
    sharedPrm->isMicroStepOver = settings.value(microStepOver, QVariant(true)).toBool();   //是否 微步跳转
    //**   振镜标定参数   **
    sharedPrm->scannerRatio[AXISX] = settings.value(scannerXRatio, QVariant(-172.34f)).toFloat();
    sharedPrm->scannerAdjust[AXISX] = settings.value(scannerXAdjust, QVariant(0.f)).toFloat();
    sharedPrm->scannerPlatformAdjust[AXISX] = settings.value(scannerXPlatformAdjust, QVariant(0.f)).toFloat();
    sharedPrm->scannerRatio[AXISY] = settings.value(scannerYRatio, QVariant(171.66f)).toFloat();
    sharedPrm->scannerAdjust[AXISY] = settings.value(scannerYAdjust, QVariant(0.f)).toFloat();
    sharedPrm->scannerPlatformAdjust[AXISY] = settings.value(scannerYPlatformAdjust, QVariant(0.f)).toFloat();

    /****************    平台电机界面参数     ****************/
    // 三电机的参数
    sharedPrm->motorRatio[AXISX] = settings.value(motorRatioX, QVariant(640.f)).toFloat(); //电机减速比，pulse/mm
    sharedPrm->motorRatio[AXISY] = settings.value(motorRatioY, QVariant(640.f)).toFloat();
    sharedPrm->motorRatio[AXISZ] = settings.value(motorRatioZ, QVariant(427.f)).toFloat();
    // 微调
    sharedPrm->margin[AXISX] = settings.value(marginX, QVariant(0.f)).toFloat();           //电机精调，pulse
    sharedPrm->margin[AXISY] = settings.value(marginY, QVariant(0.f)).toFloat();
    sharedPrm->margin[AXISZ] = settings.value(marginZ, QVariant(0.f)).toFloat();
    // 初始偏移
    sharedPrm->initOffset[AXISX] = settings.value(initOffsetX, QVariant(295.f)).toFloat(); //初始偏移，mm
    sharedPrm->initOffset[AXISY] = settings.value(initOffsetY, QVariant(20.f)).toFloat();
    sharedPrm->initOffset[AXISZ] = settings.value(initOffsetZ, QVariant(200.f)).toFloat();
    // 起始速度
    sharedPrm->startSpeed[AXISX] = settings.value(startSpeedX, QVariant(6000)).toInt();    //起始速度，p/s
    sharedPrm->startSpeed[AXISY] = settings.value(startSpeedY, QVariant(6000)).toInt();
    sharedPrm->startSpeed[AXISZ] = settings.value(startSpeedZ, QVariant(6000)).toInt();
    // 匀速
    sharedPrm->runSpeed[AXISX] = settings.value(runSpeedX, QVariant(16000)).toInt();       //匀速，p/s
    sharedPrm->runSpeed[AXISY] = settings.value(runSpeedY, QVariant(19200)).toInt();
    sharedPrm->runSpeed[AXISZ] = settings.value(runSpeedZ, QVariant(15000)).toInt();
    // 加速度
    sharedPrm->acc[AXISX] = settings.value(motorAccX, QVariant(50000)).toInt();            //加速度，p/s^2
    sharedPrm->acc[AXISY] = settings.value(motorAccY, QVariant(50000)).toInt();
    sharedPrm->acc[AXISZ] = settings.value(motorAccZ, QVariant(50000)).toInt();
    // 平台调整
    sharedPrm->reversePlatformX = settings.value(reversePlatX, QVariant(true)).toBool();   //平台X方向反转
    sharedPrm->reversePlatformY = settings.value(reversePlatY, QVariant(true)).toBool();   //平台Y方向反转
    sharedPrm->reversePlatformZ = settings.value(reversePlatZ, QVariant(false)).toBool();  //平台Z方向反转
    sharedPrm->reverseScannerXY = settings.value(reverseScannerXY, QVariant(false)).toBool();  //振镜XY方向反转
    sharedPrm->reverseScannerZ = settings.value(reverseScannerZ, QVariant(false)).toBool();    //振镜Z方向反转
    sharedPrm->isSphereMachine = settings.value(sphereMachine, QVariant(false)).toBool();      //雕球机
    settings.endGroup();
    ///------ end group
}

void ParamWindow::writeParamToRegistry(const sharedParameter *sharedPrm)
{
    if(!sharedPrm) return;

    QSettings settings;

    ///------ begin group
    settings.beginGroup(g_CrystalPrm);
    /****************    排序方法界面参数     ****************/
    //**   水晶   **
    settings.setValue(crystalSizeX, QVariant(sharedPrm->crystalSize.x()));
    settings.setValue(crystalSizeY, QVariant(sharedPrm->crystalSize.y()));
    settings.setValue(crystalSizeZ, QVariant(sharedPrm->crystalSize.z()));
    //**   排序方法   **
    settings.setValue(sortMethod, QVariant(sharedPrm->sortingMethod));     //排序方法
    settings.setValue(blockWidth, QVariant(sharedPrm->blockWidth));        //块宽度
    settings.setValue(boundaryDisable, QVariant(sharedPrm->boundaryDisable));  //模糊比例
    //**   点云模型   **
    settings.setValue(minLayerDis, QVariant(sharedPrm->minLayerDis));      //最小分层间距
    settings.setValue(distortionCorr, QVariant(sharedPrm->distortionCorr));    //扭曲校正
    //**   分块参数   **
    settings.setValue(borderType, QVariant(sharedPrm->borderType));        //边界类型
    settings.setValue(blockSizeX, QVariant(sharedPrm->blockSize.x()));     //分块大小
    settings.setValue(blockSizeY, QVariant(sharedPrm->blockSize.y()));
    settings.setValue(blockSizeZ, QVariant(sharedPrm->blockSize.z()));
    settings.setValue(borderWidth, QVariant(sharedPrm->borderWidth));      //边界参数，宽度
    settings.setValue(borderAngle, QVariant(sharedPrm->borderAngle));      //边界参数，倾斜角度
    settings.endGroup();
    ///------ end group

    ///------ begin group
    settings.beginGroup(g_MachinePrm);
    /****************    激光振镜界面参数     ****************/
    //**   激光测试   **
    settings.setValue(testRatio, QVariant(sharedPrm->testRatio));          //比率（占空比）
    settings.setValue(testFrequency, QVariant(sharedPrm->testFrequency));  //HZ,测试频率
    settings.setValue(focalLength, QVariant(sharedPrm->focalLength));      //mm,激光焦距
    settings.setValue(simmerTime, QVariant(sharedPrm->simmerTime));        //s，激光预热时间
    settings.setValue(laserDelay, QVariant(sharedPrm->laserDelay));        //us，激光出光延时
    //**   设置   **
    settings.setValue(scannerDelay, QVariant(sharedPrm->scannerDelay));    //us,振镜延时
    settings.setValue(scannerSpeed, QVariant(sharedPrm->scannerSpeed));    //bit/ms,振镜速度
    settings.setValue(microStepDelay, QVariant(sharedPrm->microStepDelay));//us,微步延时
    settings.setValue(scannerXYExchange, QVariant(sharedPrm->isScannerXYExchange));    //是否 振镜XY互换
    settings.setValue(microStepOver, QVariant(sharedPrm->isMicroStepOver)); //是否 微步跳转
    //**   振镜标定参数   **
    settings.setValue(scannerXRatio, QVariant(sharedPrm->scannerRatio[AXISX]));
    settings.setValue(scannerXAdjust, QVariant(sharedPrm->scannerAdjust[AXISX]));
    settings.setValue(scannerXPlatformAdjust, QVariant(sharedPrm->scannerPlatformAdjust[AXISX]));
    settings.setValue(scannerYRatio, QVariant(sharedPrm->scannerRatio[AXISY]));
    settings.setValue(scannerYAdjust, QVariant(sharedPrm->scannerAdjust[AXISY]));
    settings.setValue(scannerYPlatformAdjust, QVariant(sharedPrm->scannerPlatformAdjust[AXISY]));

    /****************    平台电机界面参数     ****************/
    // 三电机的参数
    settings.setValue(motorRatioX, QVariant( sharedPrm->motorRatio[AXISX]));   //电机减速比，pulse/mm
    settings.setValue(motorRatioY, QVariant( sharedPrm->motorRatio[AXISY]));
    settings.setValue(motorRatioZ, QVariant( sharedPrm->motorRatio[AXISZ]));
    // 微调
    settings.setValue(marginX, QVariant(sharedPrm->margin[AXISX]));            //电机精调，pulse
    settings.setValue(marginY, QVariant(sharedPrm->margin[AXISY]));
    settings.setValue(marginZ, QVariant(sharedPrm->margin[AXISZ]));
    // 初始偏移
    settings.setValue(initOffsetX, QVariant(sharedPrm->initOffset[AXISX]));    //初始偏移，mm
    settings.setValue(initOffsetY, QVariant(sharedPrm->initOffset[AXISY]));
    settings.setValue(initOffsetZ, QVariant(sharedPrm->initOffset[AXISZ]));
    // 起始速度
    settings.setValue(startSpeedX, QVariant(sharedPrm->startSpeed[AXISX]));    //起始速度，p/s
    settings.setValue(startSpeedY, QVariant(sharedPrm->startSpeed[AXISY]));
    settings.setValue(startSpeedZ, QVariant(sharedPrm->startSpeed[AXISZ]));
    // 匀速
    settings.setValue(runSpeedX, QVariant( sharedPrm->runSpeed[AXISX]));       //匀速，p/s
    settings.setValue(runSpeedY, QVariant( sharedPrm->runSpeed[AXISY]));
    settings.setValue(runSpeedZ, QVariant( sharedPrm->runSpeed[AXISZ]));
    // 加速度
    settings.setValue(motorAccX, QVariant(sharedPrm->acc[AXISX]));     //加速度，p/s^2
    settings.setValue(motorAccY, QVariant(sharedPrm->acc[AXISY]));
    settings.setValue(motorAccZ, QVariant(sharedPrm->acc[AXISZ]));
    // 平台调整
    settings.setValue(reversePlatX, QVariant(sharedPrm->reversePlatformX));    //平台X方向反转
    settings.setValue(reversePlatY, QVariant(sharedPrm->reversePlatformY));    //平台Y方向反转
    settings.setValue(reversePlatZ, QVariant(sharedPrm->reversePlatformZ));    //平台Z方向反转
    settings.setValue(reverseScannerXY, QVariant(sharedPrm->reverseScannerXY));//振镜XY方向反转
    settings.setValue(reverseScannerZ, QVariant(sharedPrm->reverseScannerZ));  //振镜Z方向反转
    settings.setValue(sphereMachine, QVariant(sharedPrm->isSphereMachine));    //雕球机
    settings.endGroup();
    ///------ end group
}

void ParamWindow::initActionsAndSlots()
{
    connect(ui->pb_sortingMethod, SIGNAL(clicked()), this, SLOT(on_sortingMethod()));
    connect(ui->pb_laserAndScanner, SIGNAL(clicked()), this, SLOT(on_laserAndScanner()));
    connect(ui->pb_PlatformMotor, SIGNAL(clicked()), this, SLOT(on_platformAndMotor()));
}

void ParamWindow::getSharedParamOnUI(sharedParameter *sharedPrm)
{
    if(!sharedPrm) return;

    float x,y,z;

    /****************    排序方法界面参数     ****************/
    //**   水晶   **
    x = ui->dsb_crystalSizeX->value();
    y = ui->dsb_crystalSizeY->value();
    z = ui->dsb_crystalSizeZ->value();
    sharedPrm->crystalSize.set(x,y,z);
    //**   排序方法   **
    if(ui->rb_squenceX2Y->isChecked())
        sharedPrm->sortingMethod = Sorting_X2Y;    //排序方法
    else if(ui->rb_squenceY2X->isChecked())
        sharedPrm->sortingMethod = Sorting_Y2X;
    else if(ui->rb_ShortestPath->isChecked())
        sharedPrm->sortingMethod = Sorting_ShortestPath;
    sharedPrm->blockWidth = ui->dsb_blockWidth->value();   //块宽度
    sharedPrm->boundaryDisable = ui->dsb_boundaryDisable->value(); //模糊比例
    //**   点云模型   **
    sharedPrm->minLayerDis = ui->dsb_minLayerDis->value(); //最小分层间距
    if(ui->rb_noneCorrect->isChecked())
        sharedPrm->distortionCorr = Correct_None;  //扭曲校正
    else if(ui->rb_XYCorrect->isChecked())
        sharedPrm->distortionCorr = Correct_XY;
    else if(ui->rb_YXCorrect->isChecked())
        sharedPrm->distortionCorr = Correct_YX;
    //**   分块参数   **
    if(ui->rb_verticalBorder->isChecked())
        sharedPrm->borderType = Border_Vertical;   //边界类型
    else if(ui->rb_inclinedBorder->isChecked())
        sharedPrm->borderType = Border_Inclined;
    x = ui->dsb_blockSizeX->value();
    y = ui->dsb_blockSizeY->value();
    z = ui->dsb_blockSizeZ->value();
    sharedPrm->blockSize.set(x,y,z);  //分块大小
    sharedPrm->borderWidth = ui->dsb_borderWidth->value(); //边界参数，宽度
    sharedPrm->borderAngle = ui->dsb_borderAngle->value(); //边界参数，倾斜角度

    /****************    激光振镜界面参数     ****************/
    //**   激光测试   **
    sharedPrm->testRatio = (float)ui->s_laserRatio->value()/100.f; //比率（占空比）
    sharedPrm->testFrequency = ui->s_laserFrequency->value();      //HZ,测试频率
    sharedPrm->focalLength = ui->dsb_focalLength->value();         //mm,激光焦距
    sharedPrm->simmerTime = ui->sb_laserSimmerTime->value();       //s，激光预热时间
    sharedPrm->laserDelay = ui->sb_laserDelay->value();            //us，激光出光延时
    //**   设置   **
    sharedPrm->scannerDelay = ui->sb_scannerDelay->value();        //us,振镜延时
    sharedPrm->scannerSpeed = ui->sb_scannerSpeed->value();        //bit/ms,振镜速度
    sharedPrm->microStepDelay = ui->sb_microStepDelay->value();    //us,微步延时
    sharedPrm->isScannerXYExchange = ui->cb_exchangeXYScanner->isChecked();    //是否 振镜XY互换
    sharedPrm->isMicroStepOver = ui->cb_stepOverMicroStep->isChecked();        //是否 微步跳转
    //**   振镜标定参数   **
    sharedPrm->scannerRatio[AXISX] = ui->dsb_scannerRatioX->value();
    sharedPrm->scannerAdjust[AXISX] = ui->dsb_scannerAdjustX->value();
    sharedPrm->scannerPlatformAdjust[AXISX] = ui->dsb_scannerPlatformAdjustX->value();
    sharedPrm->scannerRatio[AXISY] = ui->dsb_scannerRatioY->value();
    sharedPrm->scannerAdjust[AXISY] = ui->dsb_scannerAdjustY->value();
    sharedPrm->scannerPlatformAdjust[AXISY] = ui->dsb_scannerPlatformAdjustY->value();

    /****************    平台电机界面参数     ****************/
    // 三电机的参数
    sharedPrm->motorRatio[AXISX] = ui->dsb_motorRatioX->value();   //电机减速比，pulse/mm
    sharedPrm->motorRatio[AXISY] = ui->dsb_motorRatioY->value();
    sharedPrm->motorRatio[AXISZ] = ui->dsb_motorRatioZ->value();
    // 微调
    sharedPrm->margin[AXISX] = ui->sb_marginX->value();            //电机精调，pulse
    sharedPrm->margin[AXISY] = ui->sb_marginY->value();
    sharedPrm->margin[AXISZ] = ui->sb_marginZ->value();
    // 初始偏移
    sharedPrm->initOffset[AXISX] = ui->dsb_initOffsetX->value();   //初始偏移，mm
    sharedPrm->initOffset[AXISY] = ui->dsb_initOffsetY->value();
    sharedPrm->initOffset[AXISZ] = ui->dsb_initOffsetZ->value();
    // 起始速度
    sharedPrm->startSpeed[AXISX] = ui->sb_startSpeedX->value();    //起始速度，p/s
    sharedPrm->startSpeed[AXISY] = ui->sb_startSpeedY->value();
    sharedPrm->startSpeed[AXISZ] = ui->sb_startSpeedZ->value();
    // 匀速
    sharedPrm->runSpeed[AXISX] = ui->sb_runSpeedX->value();        //匀速，p/s
    sharedPrm->runSpeed[AXISY] = ui->sb_runSpeedY->value();
    sharedPrm->runSpeed[AXISZ] = ui->sb_runSpeedZ->value();
    // 加速度
    sharedPrm->acc[AXISX] = ui->sb_motorAccX->value();             //加速度，p/s^2
    sharedPrm->acc[AXISY] = ui->sb_motorAccY->value();
    sharedPrm->acc[AXISZ] = ui->sb_motorAccZ->value();
    // 平台调整
    sharedPrm->reversePlatformX = ui->cb_reverseXDir->isChecked();     //平台X方向反转
    sharedPrm->reversePlatformY = ui->cb_reverseYDir->isChecked();     //平台Y方向反转
    sharedPrm->reversePlatformZ = ui->cb_reverseZDir->isChecked();     //平台Z方向反转
    sharedPrm->reverseScannerXY = ui->cb_reverseScannerXY->isChecked();//振镜XY方向反转
    sharedPrm->reverseScannerZ = ui->cb_reverseScannerZ->isChecked();  //振镜Z方向反转
    sharedPrm->isSphereMachine = ui->cb_sphereMachine->isChecked();    //雕球机
}

void ParamWindow::setSharedParamToUI(const sharedParameter *sharedPrm)
{
    if(!sharedPrm) return;

    /****************    排序方法界面参数     ****************/
    //**   水晶   **
    ui->dsb_crystalSizeX->setValue(sharedPrm->crystalSize.x());
    ui->dsb_crystalSizeY->setValue(sharedPrm->crystalSize.y());
    ui->dsb_crystalSizeZ->setValue(sharedPrm->crystalSize.z());
    //**   排序方法   **
    ui->rb_squenceX2Y->setChecked(sharedPrm->sortingMethod == Sorting_X2Y);    //排序方法
    ui->rb_squenceY2X->setChecked(sharedPrm->sortingMethod == Sorting_Y2X);
    ui->rb_ShortestPath->setChecked(sharedPrm->sortingMethod == Sorting_ShortestPath);
    ui->dsb_blockWidth->setValue(sharedPrm->blockWidth);   //块宽度
    ui->dsb_boundaryDisable->setValue(sharedPrm->boundaryDisable); //模糊比例
    //**   点云模型   **
    ui->dsb_minLayerDis->setValue(sharedPrm->minLayerDis); //最小分层间距
    ui->rb_noneCorrect->setChecked(sharedPrm->distortionCorr == Correct_None);  //扭曲校正
    ui->rb_XYCorrect->setChecked(sharedPrm->distortionCorr == Correct_XY);
    ui->rb_YXCorrect->setChecked(sharedPrm->distortionCorr == Correct_YX);
    //**   分块参数   **
    ui->rb_verticalBorder->setChecked(sharedPrm->borderType == Border_Vertical);   //边界类型
    ui->rb_inclinedBorder->setChecked(sharedPrm->borderType == Border_Inclined);
    ui->dsb_blockSizeX->setValue(sharedPrm->blockSize.x());  //分块大小
    ui->dsb_blockSizeY->setValue(sharedPrm->blockSize.y());
    ui->dsb_blockSizeZ->setValue(sharedPrm->blockSize.z());
    ui->dsb_borderWidth->setValue(sharedPrm->borderWidth); //边界参数，宽度
    ui->dsb_borderAngle->setValue(sharedPrm->borderAngle); //边界参数，倾斜角度

    /****************    激光振镜界面参数     ****************/
    //**   激光测试   **
    ui->s_laserRatio->setValue(sharedPrm->testRatio*100); //比率（占空比）
    ui->s_laserFrequency->setValue(sharedPrm->testFrequency);      //HZ,测试频率
    ui->dsb_focalLength->setValue(sharedPrm->focalLength);         //mm,激光焦距
    ui->sb_laserSimmerTime->setValue(sharedPrm->simmerTime);       //s，激光预热时间
    ui->sb_laserDelay->setValue(sharedPrm->laserDelay);            //us，激光出光延时
    //**   设置   **
    ui->sb_scannerDelay->setValue(sharedPrm->scannerDelay);        //us,振镜延时
    ui->sb_scannerSpeed->setValue(sharedPrm->scannerSpeed);        //bit/ms,振镜速度
    ui->sb_microStepDelay->setValue(sharedPrm->microStepDelay);    //us,微步延时
    ui->cb_exchangeXYScanner->setChecked(sharedPrm->isScannerXYExchange);    //是否 振镜XY互换
    ui->cb_stepOverMicroStep->setChecked(sharedPrm->isMicroStepOver);        //是否 微步跳转
    //**   振镜标定参数   **
    ui->dsb_scannerRatioX->setValue(sharedPrm->scannerRatio[AXISX]);
    ui->dsb_scannerAdjustX->setValue(sharedPrm->scannerAdjust[AXISX]);
    ui->dsb_scannerPlatformAdjustX->setValue(sharedPrm->scannerPlatformAdjust[AXISX]);
    ui->dsb_scannerRatioY->setValue(sharedPrm->scannerRatio[AXISY]);
    ui->dsb_scannerAdjustY->setValue(sharedPrm->scannerAdjust[AXISY]);
    ui->dsb_scannerPlatformAdjustY->setValue(sharedPrm->scannerPlatformAdjust[AXISY]);

    /****************    平台电机界面参数     ****************/
    // 三电机的参数
    ui->dsb_motorRatioX->setValue(sharedPrm->motorRatio[AXISX]);   //电机减速比，pulse/mm
    ui->dsb_motorRatioY->setValue(sharedPrm->motorRatio[AXISY]);
    ui->dsb_motorRatioZ->setValue(sharedPrm->motorRatio[AXISZ]);
    // 微调
    ui->sb_marginX->setValue(sharedPrm->margin[AXISX]);            //电机精调，pulse
    ui->sb_marginY->setValue(sharedPrm->margin[AXISY]);
    ui->sb_marginZ->setValue(sharedPrm->margin[AXISZ]);
    // 初始偏移
    ui->dsb_initOffsetX->setValue(sharedPrm->initOffset[AXISX]);   //初始偏移，mm
    ui->dsb_initOffsetY->setValue(sharedPrm->initOffset[AXISY]);
    ui->dsb_initOffsetZ->setValue(sharedPrm->initOffset[AXISZ]);
    // 起始速度
    ui->sb_startSpeedX->setValue(sharedPrm->startSpeed[AXISX]);    //起始速度，p/s
    ui->sb_startSpeedY->setValue(sharedPrm->startSpeed[AXISY]);
    ui->sb_startSpeedZ->setValue(sharedPrm->startSpeed[AXISZ]);
    // 匀速
    ui->sb_runSpeedX->setValue(sharedPrm->runSpeed[AXISX]);        //匀速，p/s
    ui->sb_runSpeedY->setValue(sharedPrm->runSpeed[AXISY]);
    ui->sb_runSpeedZ->setValue(sharedPrm->runSpeed[AXISZ]);
    // 加速度
    ui->sb_motorAccX->setValue(sharedPrm->acc[AXISX]);             //加速度，p/s^2
    ui->sb_motorAccY->setValue(sharedPrm->acc[AXISY]);
    ui->sb_motorAccZ->setValue(sharedPrm->acc[AXISZ]);
    // 平台调整
    ui->cb_reverseXDir->setChecked(sharedPrm->reversePlatformX);     //平台X方向反转
    ui->cb_reverseYDir->setChecked(sharedPrm->reversePlatformY);     //平台Y方向反转
    ui->cb_reverseZDir->setChecked(sharedPrm->reversePlatformZ);     //平台Z方向反转
    ui->cb_reverseScannerXY->setChecked(sharedPrm->reverseScannerXY);//振镜XY方向反转
    ui->cb_reverseScannerZ->setChecked(sharedPrm->reverseScannerZ);  //振镜Z方向反转
    ui->cb_sphereMachine->setChecked(sharedPrm->isSphereMachine);    //雕球机
}

void ParamWindow::accept()
{
    getSharedParamOnUI(_sharedPrm);
    QDialog::accept();
}

void ParamWindow::reject()
{
    setSharedParamToUI(_sharedPrm);
    QDialog::reject();
}

void ParamWindow::on_sortingMethod()
{
    ui->sa_sortingMethod->move(120,10);
    ui->sa_laserAndScanner->move(640,10);
    ui->sa_platformAndMotor->move(640,10);
}

void ParamWindow::on_laserAndScanner()
{
    ui->sa_sortingMethod->move(640,10);
    ui->sa_laserAndScanner->move(120,10);
    ui->sa_platformAndMotor->move(640,10);
}

void ParamWindow::on_platformAndMotor()
{
    ui->sa_sortingMethod->move(640,10);
    ui->sa_laserAndScanner->move(640,10);
    ui->sa_platformAndMotor->move(120,10);
}

void ParamWindow::on_setDefaultParam()
{

}

void ParamWindow::on_getDefaultParam()
{

}
