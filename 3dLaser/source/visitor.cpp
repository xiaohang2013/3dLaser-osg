#include <visitor.h>

#include <QString>






LocalToWorldMatrix::LocalToWorldMatrix(osg::NodeVisitor::TraversalMode tm)
    :osg::NodeVisitor(tm),_done(false)//默认遍历全部父节点
{}

void LocalToWorldMatrix::apply(osg::Node &node)
{
    if(!_done)
    {
        //到达根节点，此时节点路径也已记录完整
        if(0==node.getNumParents())
        {
            _wcMatrix.set(osg::computeLocalToWorld(this->getNodePath()));
            _done=true;
        }
        //继续遍历
        traverse(node);
    }
}

unificateNodeStructure::unificateNodeStructure(osg::NodeVisitor::TraversalMode tm)
    :osg::NodeVisitor(tm)//默认遍历全部children
{
    _group=new osg::Group;
}

void unificateNodeStructure::apply(osg::Geode &geode)
{
    unsigned int numd=geode.getNumDrawables();
    if(numd > 0)
    {
        //到世界坐标系的转化矩阵
        LocalToWorldMatrix _nLTWM;
        geode.accept(_nLTWM);
        osg::Matrixd matrix=_nLTWM.getLocalToWorldMatrix();
        osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform;
        std::string name = geode.getName();
        if(name.empty())
        {
            geode.setName(qPrintable(defultGeodeName));
            name = qPrintable(defultGeodeName);
        }
        //是否已存在（值）相等osg::MatrixTransform，是：直接添加geode；否：新建后添加
        findNamedNodeList fnnl(name);
        _group->accept(fnnl);
        osg::NodeList mtList=fnnl.getNamedMatrixTransformList();
        if(mtList.size()>0)//同名项
        {
            osg::ref_ptr<osg::Node> node = mtList.at(0);
            osg::ref_ptr<osg::MatrixTransform> mtf=dynamic_cast<osg::MatrixTransform*>(node.get());
            if(mtf && mtf->getMatrix()==matrix)//是
            {
                 mt = mtf;
                 mt->addChild(&geode);
                 return;
            }
            else//否
            {
                std::string nametemp=name;
                for(int i=1;fnnl.getNamedMatrixTransformList().size()>0;++i)
                {
                    nametemp = name + "_" + qPrintable(QString::number(i));
                    fnnl.setName(nametemp);
                    _group->accept(fnnl);
                }
                name=nametemp;
            }
        }

        mt->setMatrix(matrix);//否
        mt->addChild(&geode);
        mt->setName(name);
        _group->addChild(mt.get());

        //未绑定颜色的绘制体绑定颜色（白色），防止受其他颜色干扰
        setModelColorVisitor smcv(osg::Vec4(1.f,1.f,1.f,1.f));
        geode.accept(smcv);
    }
}






void vertexExtractor::apply(osg::Geode &geode)
{
    LocalToWorldMatrix nLTWM;
    geode.accept(nLTWM);
    osg::Matrix m = nLTWM.getLocalToWorldMatrix();

    //得到每个Drawable
    for(unsigned int i=0; i<geode.getNumDrawables();++i)
    {
        osg::Geometry *geom=geode.getDrawable(i)->asGeometry();
        if(!geom) continue;

        //得到可绘制结点的顶点序列
        osg::ref_ptr<osg::Vec3Array> vec3a=dynamic_cast<osg::Vec3Array*> (geom->getVertexArray());
        if(!vec3a) continue;
        //插入顶点集
        if(m.isIdentity())//单位阵
        {
            if(vec3a->size()>0)
                _vertexArray->insert(_vertexArray->end(),vec3a->begin(),vec3a->end());
        }
        else//非单位阵
        {
            for(unsigned int i=0; i<vec3a->size(); ++i)
            {
                osg::Vec4 vt4(vec3a->at(i),1.0f);
                vt4=vt4*m;
                _vertexArray->push_back(osg::Vec3(vt4.x(),vt4.y(),vt4.z()));
            }
        }
    }
}
