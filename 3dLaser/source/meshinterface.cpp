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
        formatList << Format("Alias Wavefront Object",tr("OBJ"));
        formatList << Format("Stereolithography File", tr("STL"));
        formatList << Format("3D Studio File", tr("3DS"));
        formatList << Format("COLLADA File", tr("DAE"));
        //....
    }
    else if(mType == OBJECTWITHTEXTURE)
    {
        formatList<<Format("Alias Wavefront Object",tr("OBJ"));
    }
    else if(mType == IMAGE)
    {
        formatList<<Format("Portable Network Graphics",tr("PNG"));
        Format fj("Jpeg Image",tr("JPG"));
        fj.extensions.push_back(tr("JPEG"));
        formatList<<fj;
        formatList<<Format("GIF Image",tr("GIF"));
        formatList<<Format("Windows Bitmap",tr("BMP"));
        formatList<<Format("PIC Image",tr("PIC"));
    }
    else if(mType == POINTCLOUD)
    {
        formatList<<Format("DXF File Format",tr("DXF"));
    }

    return formatList;
}

QList<meshInterface::Format> meshInterface::exportFormats(MeshType mType) const
{
    QList<Format> formatList;
    if(mType == OBJECT3D)
    {
//        formatList << Format("DXF File Format"							, tr("DXF"));
        formatList << Format("Alias Wavefront Object"                   ,tr("OBJ"));
        //....
    }
    else if(mType == OBJECTWITHTEXTURE)
    {
        formatList << Format("Alias Wavefront Object"                   ,tr("OBJ"));
    }
    else if(mType == IMAGE)
    {
        formatList<<Format("Portable Network Graphics",tr("PNG"));
    }
    else if(mType == POINTCLOUD)
    {
        formatList << Format("DXF File Format"							, tr("DXF"));
    }


    return formatList;
}

///initial supported IO formats filters
void meshInterface::init_KnownIOFormatsFilters(MeshType mType, QStringList *allKnowInputFormats, QStringList *allKnowOutputFormats,
                                               QStringList *inputFilters, QStringList *outputFilters)
{
    QString sHead;
    if(mType == OBJECT3D) sHead = QStringLiteral("全部3D文件格式(");
    else if(mType == OBJECTWITHTEXTURE) sHead = QStringLiteral("全部纹理文件格式(");
    else if(mType == IMAGE) sHead = QStringLiteral("全部图片格式(");
    else if(mType == POINTCLOUD) sHead = QStringLiteral("全部点云格式(");

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
                    allKnownFormatsFilter.append(tr(" *."));
                    allKnownFormatsFilter.append(curExtension);
                }
                curFilterEntry.append(tr(" *."));
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

    QString lowerformat=formatName.toLower();
    if(lowerformat == tr("obj"))
    {
        osg::ref_ptr<osgDB::Options> opt = new osgDB::Options(std::string("noRotation"));
//        opt->setObjectCacheHint(osgDB::Options::CACHE_NONE);
//        opt->setBuildKdTreesHint( osgDB::Options::BUILD_KDTREES );

        osg::ref_ptr<osg::Node> node=osgDB::readNodeFile(qPrintable(fileName),opt.get());
        if(!node) return NULL;
        osg::ref_ptr<osg::Group> groupResult=new osg::Group;
//        osg::Group *groupReadin=node->asGroup();
//        for(unsigned int i=0;i < groupReadin->getNumChildren(); i++)
//        {
//            //获取其节点至世界坐标系的变换矩阵
//            nodeLocalToWorldMatrix nLTWM;
//            groupReadin->getChild(i)->accept(nLTWM);
//            osg::Matrixd matrix=*(nLTWM.getLocalToWorldMatrix());
//            //插入osg::MatrixTransform节点
//            osg::ref_ptr<osg::MatrixTransform> mt=new osg::MatrixTransform;
//            mt->setMatrix(matrix);
//            mt->addChild(groupReadin->getChild(i));
//            mt->setName(groupReadin->getChild(i)->getName());
//            groupResult->addChild(mt);
//        }

        //将读入文件架构统一化为group->MatrixTransform->geode
        unificateNodeStructure snv;
        node->accept(snv);
        groupResult=snv.getStructurizedGroup();

        return groupResult.release();
    }
    //3ds的option有：noMatrixTransforms checkForEspilonIdentityMatrices restoreMatrixTransformsNoMeshes
    else if(lowerformat==tr("stl")||lowerformat==tr("3ds")||lowerformat==tr("dae"))
    {
        osg::ref_ptr<osgDB::Options> opt = new osgDB::Options();

        osg::ref_ptr<osg::Node> node=osgDB::readNodeFile(qPrintable(fileName),opt.get());
        if(!node) return NULL;
        //将读入文件架构统一化为group->MatrixTransform->geode
        unificateNodeStructure snv;
        node->accept(snv);
        osg::ref_ptr<osg::Group> groupResult = snv.getStructurizedGroup();

        return groupResult.release();
    }
    else if(lowerformat==tr("png")||lowerformat==tr("jpg")||lowerformat==tr("jpeg")||
            lowerformat==tr("gif")||lowerformat==tr("bmp")||lowerformat==tr("pic"))
    {
        osg::ref_ptr<osgDB::Options> opt = new osgDB::Options();

        osg::ref_ptr<osg::Image> image = osgDB::readImageFile(qPrintable(fileName), opt.get());
        if(!image || !image.valid()) return NULL;
        //读入文件架构统一化为group->MatrixTransform->geode
        osg::ref_ptr<osg::Geode> geode = createGeodeForImage(image.get());
        if (image->isImageTranslucent())
        {
//            OSG_INFO<<"Image "<<image->getFileName()<<" is translucent; setting up blending."<<std::endl;
            geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
            geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
        }
        osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform;
        mt->addChild(geode.get());
        osg::ref_ptr<osg::Group> groupResult = new osg::Group;
        groupResult->addChild(mt.get());

        return groupResult.release();
    }
    /*.dxf file reader structure: MatrixTransform->MatrixTransform->group->geode */
    else if(lowerformat==tr("dxf"))
    {
        osg::ref_ptr<osgDB::Options> opt = new osgDB::Options();
        osg::ref_ptr<osg::Node> node=osgDB::readNodeFile(qPrintable(fileName),opt.get());
        if(!node) return NULL;
        //将读入文件架构统一化为group->MatrixTransform->geode
        unificateNodeStructure snv;
        node->accept(snv);
        osg::ref_ptr<osg::Group> groupResult = snv.getStructurizedGroup();

        return groupResult.release();
    }
    return NULL;
}

bool meshInterface::saveMesh(const osg::ref_ptr<osg::Node> node, const QString &formatName, const QString &fileName)
{
    QString lowerformat=formatName.toLower();
    if(lowerformat == tr("dxf"))
        return osgDB::writeNodeFile(*(node.get()), qPrintable(fileName));
    else if(lowerformat == tr("obj"))
        return osgDB::writeNodeFile(*(node.get()), qPrintable(fileName));

    return osgDB::writeNodeFile(*(node.get()), qPrintable(fileName));
}

bool meshInterface::saveMesh(const osg::ref_ptr<osg::Image> image, const QString &formatName, const QString &fileName)
{
    QString lowerformat=formatName.toLower();
    if(lowerformat == tr("png"))
        return osgDB::writeImageFile(*(image.get()), qPrintable(fileName));

    return osgDB::writeImageFile(*(image.get()), qPrintable(fileName));
}

osg::Geode *meshInterface::createGeodeForImage(osg::Image *image)
{
    return createGeodeForImage(image,image->s(),image->t());
}

osg::Geode *meshInterface::createGeodeForImage(osg::Image *image, float s, float t)
{
    if (image)
    {
        if (s>0 && t>0)
        {

            float y = 0.05f*t;
            float x = y*(s/t);

            float texcoord_y_b = (image->getOrigin() == osg::Image::BOTTOM_LEFT) ? 0.0f : 1.0f;
            float texcoord_y_t = (image->getOrigin() == osg::Image::BOTTOM_LEFT) ? 1.0f : 0.0f;

            // set up the texture.

#if 0
            osg::ref_ptr<osg::TextureRectangle> texture = new osg::TextureRectangle;
            texture->setFilter(osg::Texture::MIN_FILTER,osg::Texture::LINEAR);
            texture->setFilter(osg::Texture::MAG_FILTER,osg::Texture::LINEAR);
            //texture->setResizeNonPowerOfTwoHint(false);
            float texcoord_x = image->s();
            texcoord_y_b *= image->t();
            texcoord_y_t *= image->t();
#else
            osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
            texture->setFilter(osg::Texture::MIN_FILTER,osg::Texture::LINEAR);
            texture->setFilter(osg::Texture::MAG_FILTER,osg::Texture::LINEAR);
            texture->setResizeNonPowerOfTwoHint(false);
            float texcoord_x = 1.0f;
#endif
            texture->setImage(image);

            // set up the drawstate.
            osg::ref_ptr<osg::StateSet> dstate = new osg::StateSet;
            dstate->setMode(GL_CULL_FACE,osg::StateAttribute::OFF);
            dstate->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
            dstate->setTextureAttributeAndModes(0, texture.get(),osg::StateAttribute::ON);

            // set up the geoset.                unsigned int rowSize = computeRowWidthInBytes(s,_pixelFormat,_dataType,_packing);

            osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
            geom->setStateSet(dstate.get());

            osg::ref_ptr<osg::Vec3Array> coords = new osg::Vec3Array(4);
            (*coords)[0].set(-x,y,0.0f);
            (*coords)[1].set(-x,-y,0.0f);
            (*coords)[2].set(x,-y,0.0f);
            (*coords)[3].set(x,y,0.0f);
            geom->setVertexArray(coords.get());

            osg::ref_ptr<osg::Vec2Array> tcoords = new osg::Vec2Array(4);
            (*tcoords)[0].set(0.0f*texcoord_x,texcoord_y_t);
            (*tcoords)[1].set(0.0f*texcoord_x,texcoord_y_b);
            (*tcoords)[2].set(1.0f*texcoord_x,texcoord_y_b);
            (*tcoords)[3].set(1.0f*texcoord_x,texcoord_y_t);
            geom->setTexCoordArray(0,tcoords.get());

            osg::ref_ptr<osg::Vec4Array> colours = new osg::Vec4Array(1);
            (*colours)[0].set(1.0f,1.0f,1.0f,1.0f);
            geom->setColorArray(colours.get(), osg::Array::BIND_OVERALL);

            geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS,0,4));

            // set up the geode.
            osg::Geode* geode = new osg::Geode;
            geode->addDrawable(geom);

            return geode;

        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}


