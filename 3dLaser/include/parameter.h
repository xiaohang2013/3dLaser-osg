/*
 * Date: 2016.11.14
 * By: Liu
 * Function: point cloud building parameters.
 * */

#ifndef PARAMETER
#define PARAMETER

#include <osg/Referenced>
#include <osg/Vec3>

#define MAXNUM_MOTOR 3      //电机最大数目
#define MAXNUM_SCANNERAXIS 2 //振镜最大轴数

// 坐标轴
enum AXIS
{
    AXISX=0,
    AXISY=1,
    AXISZ=2
};

// 排序方法
enum SortingMethod
{
    Sorting_X2Y,
    Sorting_Y2X,
    Sorting_ShortestPath
};

// 分块方法
enum BlockType
{
    Block_X2Y,
    Block_Y2X,
    Block_ZShortestPath
};

// 扭曲修正方式
enum DistortionCorrection
{
    Correct_None,
    Correct_XY,
    Correct_YX
};

// 边界类型
enum BorderType
{
    Border_Vertical,
    Border_Inclined
};

// 雕刻模式
enum CurvMode
{
    Single_Model_Once,
    Single_Model_Repeat,
    Multi_Model_Repeat
};

// 电机移动方向
enum MoevDirection
{
    XP,XN,
    YP,YN,
    ZP,ZN
};

// 电机手动移动方式
enum MoveMode
{
    Continuous,
    Incremental
};

// 限位是否激活----------可以直接用true false二值化代替
enum LimitType
{
    ACTIVE,
    NONACTIVE
};

class Parameter:public osg::Referenced
{};

class sharedParameter:public Parameter
{
public:

    /****************    排序方法界面参数     ****************/
    //**   水晶   **
    osg::Vec3 crystalSize;          //水晶大小
    //**   排序方法   **
    SortingMethod sortingMethod;    //排序方法
    float blockWidth;               //块宽度
    float boundaryDisable;          //模糊比例
    //**   点云模型   **
    float minLayerDis;              //最小分层间距
    DistortionCorrection distortionCorr;    //扭曲校正
    //**   分块参数   **
    BorderType borderType;  //边界类型
    osg::Vec3 blockSize;    //分块大小
    float borderWidth;      //边界参数，宽度
    float borderAngle;      //边界参数，倾斜角度

    /****************    激光振镜界面参数     ****************/
    //**   激光测试   **
    float testRatio;    //比率（占空比）
    int testFrequency;  //HZ,测试频率
    float focalLength;  //mm,激光焦距
    int simmerTime;     //s，激光预热时间
    int laserDelay;     //us，激光出光延时
    //**   设置   **
    int scannerDelay;   //us,振镜延时
    int scannerSpeed;   //bit/ms,振镜速度
    int microStepDelay; //us,微步延时
    bool isScannerXYExchange;   //是否 振镜XY互换
    bool isMicroStepOver;       //是否 微步跳转
    //**   振镜标定参数   **
    float scannerRatio[MAXNUM_SCANNERAXIS];
    float scannerAdjust[MAXNUM_SCANNERAXIS];
    float scannerPlatformAdjust[MAXNUM_SCANNERAXIS];

    /****************    平台电机界面参数     ****************/
    // 三电机的参数
    float motorRatio[MAXNUM_MOTOR];     //电机减速比，pulse/mm
    // 微调
    int margin[MAXNUM_MOTOR];           //电机精调，pulse
    // 初始偏移
    float initOffset[MAXNUM_MOTOR];     //初始偏移，mm
    // 起始速度
    int startSpeed[MAXNUM_MOTOR];       //起始速度，p/s
    // 匀速
    int runSpeed[MAXNUM_MOTOR];         //匀速，p/s
    // 加速度
    int acc[MAXNUM_MOTOR];              //加速度，p/s^2
    // 平台调整
    bool reversePlatformX;              //平台X方向反转
    bool reversePlatformY;              //平台Y方向反转
    bool reversePlatformZ;              //平台Z方向反转
    bool reverseScannerXY;              //振镜XY方向反转
    bool reverseScannerZ;               //振镜Z方向反转
    bool isSphereMachine;               //雕球机
};



#endif // PARAMETER

