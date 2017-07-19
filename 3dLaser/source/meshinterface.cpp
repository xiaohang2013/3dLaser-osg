#include "meshinterface.h"
#include "visitor.h"



#include <QDir>


//OSG
#include <osg/MatrixTransform>



meshInterface::meshInterface()
{
    init_KnownIOFormatsFilters(OBJECT3D,&allKnowObjectInputFormats,&allKnowObjectOutputFormats,&inputObjectFilters,&outputObjectFilters);
    init_KnownIOFormatsFilters(OBJECTWITHTEXTURE,&allKnowTextureInputFormats,&allKnowTextureOutputFormats,&inputTextureFilters,&outputTextureFilters);
    init_KnownIOFormatsFilters(IMAGE,&allKnowImageInputFormats,&allKnowImageOutputFormats,&inputImageFilters,&outputImageFilters);
    init_KnownIOFormatsFilters(POINTCLOUD,&allKnowPointCloudInputFormats,&allKnowPointCloudOutputFormats,&inputPointCloudFilters,&outputPointCloudFilters);
}

QList<meshInterface::Format> meshInterface::importFormats(MeshType mType) const
{
    QList<Format> formatList;
    if(mType == OBJECT3D)
    {
        formatList << Format("Alias Wavefront Object","OBJ");
        formatList << Format("Stereolithography File", "STL");
        formatList << Format("3D Studio File", "3DS");
        formatList << Format("COLLADA File", "DAE");
        //....
    }
    else if(mType == OBJECTWITHTEXTURE)
    {
        formatList<<Format("Alias Wavefront Object",("OBJ"));
    }
    else if(mType == IMAGE)
    {
        formatList<<Format("Portable Network Graphics",("PNG"));
        Format fj("Jpeg Image",("JPG"));
        fj.extensions.push_back(("JPEG"));
        formatList<<fj;
        formatList<<Format("GIF Image",("GIF"));
        formatList<<Format("Windows Bitmap",("BMP"));
        formatList<<Format("PIC Image",("PIC"));
    }
    else if(mType == POINTCLOUD)
    {
        formatList<<Format("DXF File Format",("DXF"));
    }

    return formatList;
}

QList<meshInterface::Format> meshInterface::exportFormats(MeshType mType) const
{
    QList<Format> formatList;
    if(mType == OBJECT3D)
    {
//        formatList << Format("DXF File Format"							, ("DXF"));
        formatList << Format("Alias Wavefront Object"                   ,("OBJ"));
        //....
    }
    else if(mType == OBJECTWITHTEXTURE)
    {
        formatList << Format("Alias Wavefront Object"                   ,("OBJ"));
    }
    else if(mType == IMAGE)
    {
        formatList<<Format("Portable Network Graphics"                  , ("PNG"));
    }
    else if(mType == POINTCLOUD)
    {
        formatList << Format("DXF File Format"							, ("DXF"));
    }


    return formatList;
}

///initial supported IO formats filters
void meshInterface::init_KnownIOFormatsFilters(MeshType mType, QStringList *allKnowInputFormats, QStringList *allKnowOutputFormats,
                                               QStringList *inputFilters, QStringList *outputFilters)
{
    QString sHead;
    if(mType == OBJECT3D) sHead = tr("全部3D文件格式(");
    else if(mType == OBJECTWITHTEXTURE) sHead = tr("全部纹理文件格式(");
    else if(mType == IMAGE) sHead = tr("全部图片格式(");
    else if(mType == POINTCLOUD) sHead = tr("全部点云格式(");

    for(int inout=0;inout<2;++inout)
    {
        QStringList* formatFilters = NULL;
        QString allKnownFormatsFilter(sHead);
        QList<Format> format;
        QStringList* allKnowFormats = NULL;

        if(inout==0)//input
        {
            allKnowFormats=allKnowInputFormats;
            formatFilters=inputFilters;
            format=this->importFormats(mType);
        }
        else//output
        {
            allKnowFormats=allKnowOutputFormats;
            formatFilters=outputFilters;
            format=this->exportFormats(mType);
        }
        for(QList<Format>::iterator itf = format.begin();itf!=format.end();++itf)
        {
            Format curFormat = *itf;

            QString curFilterEntry = curFormat.description + " (";

            //a particular file format could be associated with more than one file extension
            QStringListIterator itExtension(curFormat.extensions);
            while(itExtension.hasNext())
            {
                QString curExtension=itExtension.next().toLower();
                if(!allKnowFormats->contains(curExtension))
                {
                    allKnowFormats->append(curExtension);
                    allKnownFormatsFilter.append(" *.");
                    allKnownFormatsFilter.append(curExtension);
                }
                curFilterEntry.append(" *.");
                curFilterEntry.append(curExtension);
            }
            curFilterEntry.append(')');
            formatFilters->append(curFilterEntry);
        }
        allKnownFormatsFilter.append(')');
        if(formatFilters!=NULL)
            formatFilters->push_front(allKnownFormatsFilter);
    }
}

// file reader读入文件，存放成了不同的结构。此处将其统一转换成 Group->MatrixTransform->Node(Geode)
osg::Group* meshInterface::openMesh(const QString &formatName, const QString &fileName)
{
    /* obj reader supports options  */
    /*  supportsExtension("obj","Alias Wavefront OBJ format");
        supportsOption("noRotation","Do not do the default rotate about X axis");
        supportsOption("noTesselateLargePolygons","Do not do the default tesselation of large polygons");//复杂多边形（如凹多边形）分格化（成凸多边形）
        supportsOption("noTriStripPolygons","Do not do the default tri stripping of polygons");//多边形的三角带化
        supportsOption("generateFacetNormals","generate facet normals for verticies without normals");//

        supportsOption("DIFFUSE=<unit>", "Set texture unit for diffuse texture");
        supportsOption("AMBIENT=<unit>", "Set texture unit for ambient texture");
        supportsOption("SPECULAR=<unit>", "Set texture unit for specular texture");
        supportsOption("SPECULAR_EXPONENT=<unit>", "Set texture unit for specular exponent texture");
        supportsOption("OPACITY=<unit>", "Set texture unit for opacity/dissolve texture");
        supportsOption("BUMP=<unit>", "Set texture unit for bumpmap texture");
        supportsOption("DISPLACEMENT=<unit>", "Set texture unit for displacement texture");
        supportsOption("REFLECTION=<unit>", "Set texture unit for reflection texture");
     *
     * */

    /*.obj file reader structure: group->geode
      1，  obj reader 以 group name + object name命名为geode的name，因此名字有可能为空
      2，  遇到obj文件中的g,o,s,usemtl关键字,objreader都会新建一个geode（除非已存在完全相同的g,o,s,usemtl关键字的geode）
    */

    if(fileName.isEmpty()) return NULL;
    // 使得软件环境在外语环境下也支持中文路径
    QTextCodec *code = QTextCodec::codecForName("gb2312");
    std::string stdfileName = code->fromUnicode(fileName).data();

    QString lowerformat=formatName.toLower();
    if(lowerformat == "obj")
    {
        osg::ref_ptr<osgDB::Options> opt = new osgDB::Options(std::string("noRotation"));
//        opt->setObjectCacheHint(osgDB::Options::CACHE_NONE);
//        opt->setBuildKdTreesHint( osgDB::Options::BUILD_KDTREES );

        osg::ref_ptr<osg::Node> node=osgDB::readNodeFile(stdfileName, opt.get());
        if(!node) return NULL;
        osg::ref_ptr<osg::Group> groupResult=new osg::Group;
        //将读入文件架构统一化为group->MatrixTransform->geode
        unificateNodeStructure snv;
        node->accept(snv);
        groupResult=snv.getStructurizedGroup();

        return groupResult.release();
    }
    /*.dxf file reader structure: MatrixTransform->MatrixTransform->group->geode */
    else if(lowerformat=="dxf")
    {
        osg::ref_ptr<osgDB::Options> opt = new osgDB::Options();

        osg::ref_ptr<osg::Node> node=osgDB::readNodeFile(stdfileName,opt.get());
        if(!node) return NULL;
        //将读入文件架构统一化为group->MatrixTransform->geode
        unificateNodeStructure snv;
        node->accept(snv);
        osg::ref_ptr<osg::Group> groupResult = snv.getStructurizedGroup();

        return groupResult.release();
    }
    return NULL;
}

bool meshInterface::saveMesh(const osg::Node *node, const QString &formatName, const QString &fileName)
{
    if(fileName.isEmpty()) return false;

    // 使得软件环境在外语环境下也支持中文路径
    QTextCodec *code = QTextCodec::codecForName("gb2312");
    std::string stdfileName = code->fromUnicode(fileName).data();

    QString lowerformat=formatName.toLower();
    if(lowerformat == "dxf")
        return osgDB::writeNodeFile(*node, stdfileName);
    else if(lowerformat == "obj")
        return osgDB::writeNodeFile(*node, stdfileName);

    return false;
}

bool meshInterface::saveMesh(const osg::Image *image, const QString &formatName, const QString &fileName)
{
    if(fileName.isEmpty()) return false;

    // 使得软件环境在外语环境下也支持中文路径
    QTextCodec *code = QTextCodec::codecForName("gb2312");
    std::string stdfileName = code->fromUnicode(fileName).data();

    QString lowerformat=formatName.toLower();
    if(lowerformat == "png")
        return osgDB::writeImageFile(*image, stdfileName);

    return false;
}


