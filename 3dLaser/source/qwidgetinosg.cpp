#include "qwidgetinosg.h"

#include <QMessageBox>


qwidgetInOSG::qwidgetInOSG()
{

}

void qwidgetInOSG::on_pbMoveClicked()
{

}

osg::Camera *qwidgetInOSG::createMoveWidgetNode()
{
    pb_Move = new QPushButton;
    pb_Move->setText(tr("move"));
    pb_Move->setStyleSheet("QPushButton{ font-family:'Microsoft YaHei';font-size:24px;color:#000000;background-color: rgb(128, 128, 128);}");
    pb_Move->setFixedSize(QSize(75,75));

    osg::ref_ptr<osg::Camera> camera = new osg::Camera;
    osg::ref_ptr<osgQt::QWidgetImage> widgetImage =
            new osgQt::QWidgetImage( pb_Move );

    osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
    texture->setImage( widgetImage.get() );
    widgetImage->getQWidget()->setAttribute(Qt::WA_TranslucentBackground);
    widgetImage->getQGraphicsViewAdapter()->setBackgroundColor(QColor(0,0,0,0));
    osg::ref_ptr<osgViewer::InteractiveImageHandler> handler =
            new osgViewer::InteractiveImageHandler( widgetImage.get(),texture.get(),camera.get());
    osg::ref_ptr<osg::Geometry> quad = osg::createTexturedQuadGeometry(osg::Vec3(), osg::X_AXIS, osg::Y_AXIS);
    quad->setEventCallback( handler.get() );
    quad->setCullCallback( handler.get() );
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable( quad.get() );
    geode->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture.get() );
    geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
    geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
    geode->getOrCreateStateSet()->setMode(GL_BLEND,osg::StateAttribute::ON);
    geode->getOrCreateStateSet()->setAttribute(new osg::Program);

    camera->setProjectionResizePolicy(osg::Camera::FIXED);
    camera->setProjectionMatrix(osg::Matrix::ortho2D(0.16,1.16,0.675,1.675));
    camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
    camera->setViewMatrix(osg::Matrix::identity());
    camera->setClearMask(GL_DEPTH_BUFFER_BIT);
    camera->setRenderOrder(osg::Camera::POST_RENDER);
    camera->addChild(geode);
//    camera->setViewport(0,0,532,384);

    return camera.release();
}

void qwidgetInOSG::initWidgets()
{

}

