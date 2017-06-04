#ifndef IMAGEMATH_H
#define IMAGEMATH_H

#include "qmath.h"
#include "pcgmath.h"
#include "parameter.h"

#include <osg/Image>
#include <osg/Geometry>
#include <osg/Array>
#include <osg/Matrix>


class imageMath : public pcgMath
{
    Q_OBJECT

public:
    imageMath();

    bool convertColorMapToGray(osg::Image *image);
    //  R>255:R=255;  R<0: R=0; 否则，R=R
    inline int checkValue(int value){ return (value & ~0xff) == 0? value : value > 255? 255 : 0;}
    // 亮度/对比度调整
    bool adjustBrightAndContrast(osg::Image *image, int bright, int contrast, unsigned char threshold);
    bool sharpenImage(osg::Image *image, osg::Image *blurredImg, float amount, char threshold=0);
    bool sharpenImage(osg::Image *image, float amount, int radius=1, float sigma=1.0f, char threshold=0);
    // 第一种gaussianBlur是行列分别blur后合成的，速度较快；第二三种gaussianBlur原理相同，为原生的gaussianBlur，速度稍慢；
    // 第四种是网友优化的gaussianBlur（高斯模糊），速度较快
    bool gaussianBlurRowColSeparate(osg::Image *image, int radius, float sigma);
    bool gaussianBlur(osg::Image *image, int radius, float sigma);
    bool gaussianBlur(unsigned char* src, unsigned char*& dst, int radius, int width, int height, float sigma, int channel);
    bool gaussianBlur(unsigned char* src, unsigned char*& dst, int width, int height, float sigma, int chan);

    inline unsigned char* getImageData(osg::Image *img, unsigned int column, unsigned int row = 0, unsigned int image = 0) const
    {
        if (!img->data()) return NULL;
        return img->data()+(column*img->getPixelSizeInBits())/8+row*img->getRowStepInBytes()+image*img->getImageStepInBytes();
    }

    // 生成点云
    osg::Vec3Array *buildPictureLayerToPointCloud(const osg::Image *image, osg::Vec3Array *vertexArray, osg::Vec2Array *texCoordArray, pictureParameter prm);


protected:
    /**
     * Function: 生成多边形面片的法线，方向1-2-3-...右手定则
     * 参数：polygon：多边形顶点数组
     * reverse:是否反转法线
    */
    osg::Vec3 getNormalofPolygon(const osg::Vec3Array *polygon, bool reverse)
    {
        osg::Vec3 ab(polygon->at(1)-polygon->at(0));
        osg::Vec3 bc(polygon->at(2)-polygon->at(1));
        osg::Vec3 norm = getNormalizedCrossProduct(ab,bc,reverse);
        return norm;
    }

    /**
     * Function: 获取单位化的两向量叉积
     * 参数：polygon：多边形顶点数组
     * reverse:是否反转法线
    */
    osg::Vec3 getNormalizedCrossProduct(const osg::Vec3 v1, const osg::Vec3 v2, bool reverse)
    {
        osg::Vec3 v(v1^v2);
        v.normalize();
        if(reverse) v = -v;
        return v;
    }
};

#endif // IMAGEMATH_H
