#ifndef MESHINTERFACE_H
#define MESHINTERFACE_H

//qt include files
#include <QtCore>
#include <QStringList>

//osg include files
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osg/DrawPixels>


#if _MSC_VER >= 1600
   #pragma execution_character_set("utf-8")
#endif



class meshInterface : public QObject
{
public:
    class Format
    {
    public:
        Format(QString description,QString ex):description(description){extensions<<ex;}
        QString description;
        QStringList extensions;
    };

public:
    meshInterface();



public:

    enum MeshType
    {
        OBJECT3D,
        OBJECTWITHTEXTURE,
        IMAGE,
        POINTCLOUD
    };

    QList<Format> importFormats(MeshType mType) const;
    QList<Format> exportFormats(MeshType mType) const;

    void init_KnownIOFormatsFilters(MeshType mType, QStringList *allKnowInputFormats, QStringList *allKnowOutputFormats,
                                    QStringList *inputFilters, QStringList *outputFilters);

    osg::Group* openMesh(const QString &formatName, const QString &fileName);
    bool saveMesh(const osg::Node *node, const QString &formatName, const QString &fileName);
    bool saveMesh(const osg::Image *image, const QString &formatName, const QString &fileName);

private:
    /** Convenience function to be used by image loaders to generate a valid geode
      * to return for readNode().
      * Use the image's s and t values to scale the dimensions of the image.
    */
    osg::Geode* createGeodeForImage(osg::Image* image);
    /** Convenience function to be used by image loaders to generate a valid geode
      * to return for readNode().
      * Use the specified s and t values to scale the dimensions of the image.
    */
    osg::Geode* createGeodeForImage(osg::Image* image,float s,float t);

public:
    // supported file types
    QStringList allKnowObjectInputFormats;//3D
    QStringList allKnowObjectOutputFormats;
    QStringList inputObjectFilters;
    QStringList outputObjectFilters;

    QStringList allKnowTextureInputFormats;//3D with texture
    QStringList allKnowTextureOutputFormats;
    QStringList inputTextureFilters;
    QStringList outputTextureFilters;

    QStringList allKnowImageInputFormats;//2D image
    QStringList allKnowImageOutputFormats;
    QStringList inputImageFilters;
    QStringList outputImageFilters;

    QStringList allKnowPointCloudInputFormats;//point cloud
    QStringList allKnowPointCloudOutputFormats;
    QStringList inputPointCloudFilters;
    QStringList outputPointCloudFilters;
};

#endif // MESHINTERFACE_H
