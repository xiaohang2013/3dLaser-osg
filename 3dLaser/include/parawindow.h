#ifndef PARAWINDOW_H
#define PARAWINDOW_H

#include <QDialog>
#include <QCoreApplication>
#include "parameter.h"
#include <osg/ref_ptr>

namespace Ui {
class ParaWindow;
}

// 注册表组
const QString g_CrystalPrm = "CrystalPrm";
const QString g_DefaultCrystalPrm = "DefaultCrystalPrm";
const QString g_MachinePrm = "MachinePrm";
const QString g_DefaultPrmMachinePrm = "DefaultMachinePrm";

// 水晶参数
const QString crystalSizeX = "CrystalWidth";
const QString crystalSizeY = "CrystalLength";
const QString crystalSizeZ = "CrystalHeight";
const QString sortMethod = "SortingMethod";
const QString blockWidth = "BlockWidth";
const QString boundaryDisable = "BoundaryDisable";
const QString minLayerDis = "MinLayerDistance";
const QString distortionCorr = "DistortionCorr";
const QString borderType = "BorderType";
const QString blockSizeX = "BlockSizeX";
const QString blockSizeY = "BlockSizeY";
const QString blockSizeZ = "BlockSizeZ";
const QString borderWidth = "BorderWidth";
const QString borderAngle = "InclinedAngle";

// 机器参数（振镜和电机参数）
// 振镜
const QString testRatio = "LaserDutyRation";
const QString testFrequency = "LaserFrequency";
const QString focalLength = "FocalLength";
const QString simmerTime = "SimmerTime";
const QString laserDelay = "LaserDelay";
const QString scannerDelay = "ScannerDelay";
const QString scannerSpeed = "ScannerSpeed";
const QString microStepDelay = "MicroDealy";
const QString scannerXYExchange = "ScannerXYExchange";
const QString microStepOver = "MicroStepOver";
const QString scannerXRatio = "ScannerXRatio";
const QString scannerYRatio = "ScannerYRatio";
const QString scannerXAdjust = "ScannerXAdjust";
const QString scannerYAdjust = "ScannerYAdjust";
const QString scannerXPlatformAdjust = "ScannerXPlatformAdjust";
const QString scannerYPlatformAdjust = "ScannerYPlatformAdjust";
// 电机
const QString motorRatioX = "MotorRatioX";
const QString motorRatioY = "MotorRatioY";
const QString motorRatioZ = "MotorRatioZ";
const QString marginX = "MarginX";
const QString marginY = "MarginY";
const QString marginZ = "MarginZ";
const QString initOffsetX = "InitOffsetX";
const QString initOffsetY = "InitOffsetY";
const QString initOffsetZ = "InitOffsetZ";
const QString startSpeedX = "StartSpeedX";
const QString startSpeedY = "StartSpeedY";
const QString startSpeedZ = "StartSpeedZ";
const QString runSpeedX = "RunSpeedX";
const QString runSpeedY = "RunSpeedY";
const QString runSpeedZ = "RunSpeedZ";
const QString motorAccX = "MotorAccX";
const QString motorAccY = "MotorAccY";
const QString motorAccZ = "MotorAccZ";
const QString reversePlatX = "ReversePlatformX";
const QString reversePlatY = "ReversePlatformY";
const QString reversePlatZ = "ReversePlatformZ";
const QString reverseScannerXY = "ReverseScannerXY";
const QString reverseScannerZ = "ReverseScannerZ";
const QString sphereMachine = "SphereMachine";





class ParamWindow : public QDialog
{
    Q_OBJECT
public:
    explicit ParamWindow(sharedParameter *sharedPrm, QWidget *parent = 0);
    ~ParamWindow();

    // 私有变量
private:
    Ui::ParaWindow *ui;

    sharedParameter *_sharedPrm;

    // 公有函数
public:
    static void readParamFromRegistry(sharedParameter *sharedPrm);
    static void writeParamToRegistry(const sharedParameter *sharedPrm);


    // 私有函数
private:
    void initActionsAndSlots();
    void initParam();

    void getSharedParamOnUI(sharedParameter *sharedPrm);
    void setSharedParamToUI(const sharedParameter *sharedPrm);

    // 槽函数
private slots:
    void accept();
    void reject();

    void on_sortingMethod();
    void on_laserAndScanner();
    void on_platformAndMotor();

    void on_setDefaultParam();
    void on_getDefaultParam();

};

#endif // PARAWINDOW_H
