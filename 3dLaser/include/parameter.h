/*
 * Date: 2016.11.14
 * By: Liu
 * Function: point cloud building parameters.
 * */

#ifndef PARAMETER
#define PARAMETER

#include <osg/Referenced>

/** Building points cloud mode*/
enum BuildMode
{
    /** means that build points cloud based on curve.*/
    BASECURVE,
    /** means that build points cloud based on face.*/
    BASEFACE,
    /** means that build points cloud based on curve and face.*/
    BASECURVEANDFACE
};

/** Point Spread Type*/
enum PointSpreadType
{
    /** means that build points cloud by randomA type.*/
    RANDOMA,
    /** means that build points cloud by randomB type.*/
    RANDOMB,
    /** means that build points cloud by rectangleA type - regular rectangle.*/
    RECTANGLEA,
    /** means that build points cloud by rectangleB type - free rectangle.*/
    RECTANGLEB,
    /** means that build points cloud by diamondA type - regular diamond.*/
    DIAMONDA,
    /** means that build points cloud by diamondB type - free diamond.*/
    DIAMONDB
};

enum ScanType
{
    SCAN_X2Y,
    SCAN_Y2X,
    SCAN_SHORT
};
enum BlockType
{
    BLOCK_X2Y,
    BLOCK_Y2X,
    BLOCK_SHORT
};
enum FuzzySet
{
    Fuz_Normal,
    Fuz_Uniform
};

enum CorrectType
{
    COR_NO,
    COR_X2Y,
    COR_Y2X
};
enum BorderType
{
    Vertical,
    Bevel
};
enum CurvMode
{
    single_model_one,
    single_model_mass,
    multi_model_mass
};

struct Point
{
    float x;
    float y;
    float z;
};

class Parameter:public osg::Referenced
{
public:
};

class Crystal
{
public:
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
        FuzzySet fuzzySet;
        Point size;
        float width;
        float angle;
        float stdDev;
        bool isCenter;
    };

    S_BlockSet blockSet;
    Point size;
    S_PointCloud pointCloud;
    int layMin;
    ScanType scanType;
    CurvMode curvMode;
    bool isAlarm;
    Point mov;
};
class Scaner
{
    struct S_Scaner
    {
        float ratio;   //%
        float adjust;
        float fineTrim;
    };
    S_Scaner XScaner;
    S_Scaner YScaner;
    int delay;    //us
    int speed;    //bit/ms
    bool isXYExchange;
};
class Laser
{
public:
    int ratio;
    int frequency;     //Hz
    int focalLenth;    //mm
    int preHeatTime;   //s
    int lightOutDelay; //us
    int microStepDelay;
    bool isMicroStep;
    bool isSerialLink;
};
class Plat
{
public:
    Point size;
    Point mechPos;
    Point relPos;
};
class Motor
{
public:
    Motor(){}
    ~Motor(){}
    struct S_Motor
    {
        int ratio;    //p/mm
        int inchCtrl;
        int offset;
        int v0;       //p/s
        int v;        //p/s
        int a;        //p/s^2
    };

    S_Motor motorX;
    S_Motor motorY;
    S_Motor motorZ;
};

class ordinaryParameter:public Parameter
{
public:

    BuildMode buildPointsMode = BASEFACE;
    PointSpreadType pointSpreadType=RANDOMA;
    float pointDisInLine=0.12f;
    float pointDisInFace=0.12f;
    float pointDisSide=0.14f;
    float pointDisInZDir=0.14f;//暂未用到

};

class pictureParameter:public Parameter
{
public:
    pictureParameter(){}

    enum LayerAddingType//加层方式
    {
        CONVEX,//凸形加层
        CONCAVE//凹形加层
    };

    LayerAddingType layerAddingType = CONCAVE;
    float pointDis = 0.1f;
    int layerNum = 4;
    float layerDis = 0.35f;
    float layerAttenuation = 0.1f;

};


#endif // PARAMETER

