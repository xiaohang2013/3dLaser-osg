/*
 * Date: 2016.11.14
 * By: Liu
 * Function: point cloud building parameters.
 * */

#ifndef PARAMETER
#define PARAMETER

#include <osg/Referenced>


//
enum ScanType
{
    Scan_X2Y,
    Scan_Y2X,
    Scan_MIN
};

enum BlockType
{
    Block_X2Y,
    Block_Y2X,
    Block_MIN
};

enum CorrectType
{
    Correct_None,
    Correct_X2Y,
    Correct_Y2X
};

enum BorderType
{
    Border_Vertical,
    Border_Bevel
};

enum CurvMode
{
    single_model_one,
    single_model_mass,
    multi_model_mass
};

enum MovDir
{
    XP,XN,
    YP,YN,
    ZP,ZN
};

enum MovMode
{
    Continuous,
    Incremental
};

enum LimitType
{
    ACTIVE,
    NONACTIVE
};

struct Point
{
    float x;
    float y;
    float z;
    Point operator+ (const Point p)
    {
        Point temp;
        temp.x = this->x + p.x;
        temp.y = this->y + p.y;
        temp.z = this->z + p.z;
        return temp;
    }
    Point operator- (const Point p)
    {
        Point temp;
        temp.x = this->x - p.x;
        temp.y = this->y - p.y;
        temp.z = this->z - p.z;
        return temp;
    }
};

struct S_PointCloud
{
    int pointNum;
    Point pointMin;
    Point pointMax;
    CorrectType correctType;
};

struct S_BlockSet
{
    BorderType borderType;
    BlockType blockType;
    float fuzzyRatio;
    Point size;
    float width;
    float angle;
    float stdDev;
    bool isCenter;
};

struct S_Scaner
{
    float ratio;   //%
    int adjust;
    int fineTrim;
};

struct S_Motor
{
    int ratio;    //p/mm
    int inchCtrl;
    int offset;
    int v0;       //p/s
    int v;        //p/s
    int a;        //p/s^2
    int num;
    int subdivision;
    float stepAngle;
    MovDir dir;
    MovMode mod;
    LimitType limitP;
    LimitType limitN;
    LimitType limitL;
};
class Parameter:public osg::Referenced
{};

class Crystal:public Parameter
{
public:

    S_BlockSet blockSet;
    Point size;
    S_PointCloud pointCloud;
    int layMin;
    ScanType scanType;
    CurvMode curvMode;
    bool isAlarm;
    Point mov;
};
class Scaner:public Parameter
{
public:
    S_Scaner XScaner;
    S_Scaner YScaner;
    int delay;    //us
    int speed;    //bit/ms
    int microStepDelay;//us
    bool isXYExchange;
    bool isStepOver;
};
class Laser:public Parameter
{
public:
    int ratio;
    int frequency;     //Hz
    int focalLenth;    //mm
    int preHeatTime;   //s
    int lightOutDelay; //us
    bool isMicroStep;
    bool isSerialLink;
};
class Plat:public Parameter
{
public:
    Point CurPos;
    Point DstPos;
    Point HomPos;
    Point MovPos;
    Point size;
    Point mechPos;
    Point relPos;
};
class Motor:public Parameter
{
public:

    S_Motor motorX;
    S_Motor motorY;
    S_Motor motorZ;
};



#endif // PARAMETER

