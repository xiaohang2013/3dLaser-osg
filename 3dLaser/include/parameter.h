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

class Parameter:public osg::Referenced
{};

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

