#include "osgContainer.h"
#include <QInputEvent>
#include <QApplication>

#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgGA/MultiTouchTrackballManipulator>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>

osgContainer::osgContainer(QWidget *parent)
    : QOpenGLWidget(parent)
{
    init3D();
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
}

osgContainer::~osgContainer()
{

}

bool osgContainer::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:
    case QEvent::TouchEnd:
    case QEvent::TouchUpdate: {
        QList<QTouchEvent::TouchPoint> touchPoints = static_cast<QTouchEvent *>(event)->touchPoints();
        unsigned int id = 0;
        unsigned int tapCount = touchPoints.size();

        osg::ref_ptr<osgGA::GUIEventAdapter> osgEvent(NULL);
        osgGA::GUIEventAdapter::TouchPhase phase = osgGA::GUIEventAdapter::TOUCH_UNKNOWN;
        foreach (const QTouchEvent::TouchPoint& touchPoint, touchPoints) {
            if (!osgEvent) {
                if (event->type() == QEvent::TouchBegin) {
                    phase = osgGA::GUIEventAdapter::TOUCH_BEGAN;
                    osgEvent = window->getEventQueue()->touchBegan(id, osgGA::GUIEventAdapter::TOUCH_BEGAN, touchPoint.pos().x(), touchPoint.pos().y());
                } else if (event->type() == QEvent::TouchEnd) {
                    phase = osgGA::GUIEventAdapter::TOUCH_ENDED;
                    osgEvent = window->getEventQueue()->touchEnded(id, osgGA::GUIEventAdapter::TOUCH_ENDED, touchPoint.pos().x(), touchPoint.pos().y(), tapCount);
                } else if (event->type() == QEvent::TouchUpdate) {
                    phase = osgGA::GUIEventAdapter::TOUCH_MOVED;
                    osgEvent = window->getEventQueue()->touchMoved(id, osgGA::GUIEventAdapter::TOUCH_MOVED, touchPoint.pos().x(), touchPoint.pos().y());
                }
            } else {
                osgEvent->addTouchPoint(id, osgGA::GUIEventAdapter::TOUCH_ENDED, touchPoint.pos().x(), touchPoint.pos().y());
                osgEvent->addTouchPoint(id, phase, touchPoint.pos().x(), touchPoint.pos().y());
            }
            id++;
        }
        break;
    }
    default:
        break;
    }
    return QOpenGLWidget::event(event);
}

void osgContainer::setKeyboardModifiers(QInputEvent *event)
{
    int modkey = event->modifiers() & (Qt::ShiftModifier | Qt::ControlModifier | Qt::AltModifier);
    unsigned int mask = 0;
    if (modkey & Qt::ShiftModifier) {
        mask |= osgGA::GUIEventAdapter::MODKEY_SHIFT;
    }
    if (modkey & Qt::ControlModifier) {
        mask |= osgGA::GUIEventAdapter::MODKEY_CTRL;
    }
    if (modkey & Qt::AltModifier) {
        mask |= osgGA::GUIEventAdapter::MODKEY_ALT;
    }

    window->getEventQueue()->getCurrentEventState()->setModKeyMask(mask);
    update();
}

void osgContainer::keyPressEvent(QKeyEvent *event)
{
//    setKeyboardModifiers(event);
//    window->getEventQueue()->keyPress(event->key());
//    QOpenGLWidget::keyPressEvent(event);
//    update();
    setKeyboardModifiers(event);
    int keyValue=(osgGA::GUIEventAdapter::KeySymbol)*(event->text().toLatin1());
    window->getEventQueue()->keyPress(keyValue);
    QOpenGLWidget::keyPressEvent(event);
    update();
}

void osgContainer::keyReleaseEvent(QKeyEvent *event)
{
    setKeyboardModifiers(event);
    int keyValue=(osgGA::GUIEventAdapter::KeySymbol)*(event->text().toLatin1());
    window->getEventQueue()->keyRelease(keyValue);
    QOpenGLWidget::keyReleaseEvent(event);
    update();
}

void osgContainer::mousePressEvent(QMouseEvent *event)
{
    int button = 0;
    switch (event->button()) {
    case Qt::LeftButton: button = 1; break;
    case Qt::MidButton: button = 2; break;
    case Qt::RightButton: button = 3; break;
    case Qt::NoButton: button = 0; break;
    default: button = 0; break;
    }
    setKeyboardModifiers(event);
    window->getEventQueue()->mouseButtonPress(event->x(), event->y(), button);
    update();
}

void osgContainer::mouseReleaseEvent(QMouseEvent *event)
{
    int button = 0;
    switch (event->button()) {
    case Qt::LeftButton: button = 1; break;
    case Qt::MidButton: button = 2; break;
    case Qt::RightButton: button = 3; break;
    case Qt::NoButton: button = 0; break;
    default: button = 0; break;
    }
    setKeyboardModifiers(event);
    window->getEventQueue()->mouseButtonRelease(event->x(), event->y(), button);

    QOpenGLWidget::mouseReleaseEvent(event);
    update();
}

void osgContainer::mouseDoubleClickEvent(QMouseEvent *event)
{
    int button = 0;
    switch (event->button()) {
    case Qt::LeftButton: button = 1; break;
    case Qt::MidButton: button = 2; break;
    case Qt::RightButton: button = 3; break;
    case Qt::NoButton: button = 0; break;
    default: button = 0; break;
    }
    setKeyboardModifiers(event);
    window->getEventQueue()->mouseDoubleButtonPress(event->x(), event->y(), button);

    QOpenGLWidget::mouseDoubleClickEvent(event);
    update();
}

void osgContainer::mouseMoveEvent(QMouseEvent *event)
{
    setKeyboardModifiers(event);
    window->getEventQueue()->mouseMotion(event->x(), event->y());
    QOpenGLWidget::mouseMoveEvent(event);
    update();
}

void osgContainer::wheelEvent(QWheelEvent *event)
{
    setKeyboardModifiers(event);
    window->getEventQueue()->mouseScroll(
                event->orientation() == Qt::Vertical ?
                    (event->delta() > 0 ? osgGA::GUIEventAdapter::SCROLL_UP : osgGA::GUIEventAdapter::SCROLL_DOWN) :
                    (event->delta() > 0 ? osgGA::GUIEventAdapter::SCROLL_LEFT : osgGA::GUIEventAdapter::SCROLL_RIGHT));
    QOpenGLWidget::wheelEvent(event);
    update();
}

void osgContainer::resizeEvent(QResizeEvent *event)
{
    const QSize& size = event->size();
    window->resized(x(), y(), size.width(), size.height());
    window->getEventQueue()->windowResize(x(), y(), size.width(), size.height());
    window->requestRedraw();

    QOpenGLWidget::resizeEvent(event);
}

void osgContainer::moveEvent(QMoveEvent *event)
{
    const QPoint& pos = event->pos();
    window->resized(pos.x(), pos.y(), width(), height());
    window->getEventQueue()->windowResize(pos.x(), pos.y(), width(), height());

    QOpenGLWidget::moveEvent(event);
}

void osgContainer::timerEvent(QTimerEvent *)
{
    update();
}

void osgContainer::paintGL()
{
    if (isVisibleTo(QApplication::activeWindow())) {
        frame();
    }
}

void osgContainer::init3D()
{
    root = new osg::Switch;
    root->setName(qPrintable("Root"));
    setCamera(createCamera(0, 0, width(), height()).get());
    osg::ref_ptr<osgGA::TrackballManipulator> manipulator = new MyTrackballManipulator(this->getCamera())/*osgGA::TrackballManipulator*/;
    setCameraManipulator(manipulator.get());

    //设置相机操纵器的初始方位
    osg::Vec3d eye = osg::Vec3d(0.0,0.0,350.0);
    osg::Vec3d center = osg::Vec3d(0.0,0.0,0.0);
    osg::Vec3d up = osg::Vec3d(0.0,1.0,0.0);
    manipulator->setHomePosition(eye,center,up);

    addEventHandler(new osgViewer::StatsHandler);
    addEventHandler(new osgViewer::ThreadingHandler());
    addEventHandler(new osgViewer::HelpHandler);
    addEventHandler(new osgGA::StateSetManipulator(this->getCamera()->getOrCreateStateSet()));
    setThreadingModel(osgViewer::Viewer::SingleThreaded);

    // 设置灯光模式
//    osg::ref_ptr<osg::LightModel> lightmodel = new osg::LightModel();
//    lightmodel->setTwoSided(true);
    osg::ref_ptr<osg::StateSet> state = root->getOrCreateStateSet();
    //state->setAttribute(lightmodel, osg::StateAttribute::ON);

    state->setMode(GL_RESCALE_NORMAL,osg::StateAttribute::ON);
    state->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
    state->setMode(GL_LIGHTING, osg::StateAttribute::ON);

    setSceneData(root);
    setRunFrameScheme(ON_DEMAND);

    //坐标轴
    xyzAxesNode = createCoordinateAxes();
    root->addChild(xyzAxesNode,true);

    //光源
    //lightsrcGroup = createLight(root);
    //root->addChild(lightsrcGroup,true);

    // 添加cow.osg作为测试
//        osg::ref_ptr<osg::Node> pNode = osgDB::readNodeFile("cow.osg");
//        osg::ref_ptr<osg::MatrixTransform> matTrans = new osg::MatrixTransform;
//        matTrans->addChild(pNode);
//        matTrans->setMatrix(osg::Matrix::translate(osg::Vec3d(0, 0, 0)));
//        root->addChild(matTrans);

    startTimer(10);
}

void osgContainer::setAxesVisible(bool visible)
{
    root->setChildValue(xyzAxesNode,visible);
}

osg::ref_ptr<osg::Camera> osgContainer::createCamera(int x, int y, int w, int h)
{
    window = new osgViewer::GraphicsWindowEmbedded(x, y, w, h);

//    osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
    osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
    traits->windowDecoration = true;
    traits->x = x;
    traits->y = y;
    traits->width = w;
    traits->height = h;
    traits->doubleBuffer = true;
    traits->sharedContext = 0;

    osg::ref_ptr<osg::Camera> camera = this->getCamera();
    camera->setGraphicsContext(window);
    camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));
    camera->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera->setProjectionMatrixAsPerspective(30.0, double(traits->width) / double(traits->height), 1.0, 10000.0);
    camera->setClearColor(osg::Vec4(0.f, 0.f, 0.f, 1.0f));

    return camera.release();
}



osg::ref_ptr<osg::Node> osgContainer::createCoordinateAxes()
{
    //创建保存几何信息的对象
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry();

    float len = 45.0f; //坐标系长度
    float al = 3.0f; //箭头在坐标轴的投影长度
    float aw = 1.5f; //箭头开度（宽）
    //创建四个顶点
    osg::Vec3 pH = osg::Vec3(0.0f, 0.0f, 0.0f);
    osg::Vec3 pX = osg::Vec3(len, 0.0f, 0.0f);
    osg::Vec3 pY = osg::Vec3(0.0f, len, 0.0f);
    osg::Vec3 pZ = osg::Vec3(0.0f, 0.0f, len);

    osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array();
    geom->setVertexArray(v.get());
    //坐标轴端点
    v->push_back(pH);
    v->push_back(pX);
    v->push_back(pH);
    v->push_back(pY);
    v->push_back(pH);
    v->push_back(pZ);
    //箭头
    v->push_back(osg::Vec3(len-al, -aw, 0.0f));//x arrow
    v->push_back(pX);
    v->push_back(osg::Vec3(len-al, aw, 0.0f));
    v->push_back(osg::Vec3(-aw, len-al, 0.0f));//y arrow
    v->push_back(pY);
    v->push_back(osg::Vec3(aw, len-al, 0.0f));
    v->push_back(osg::Vec3(-aw, 0.0f, len-al));//z arrow
    v->push_back(pZ);
    v->push_back(osg::Vec3(aw, 0.0f, len-al));


    //为图元指定颜色
    osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array();
    osg::Vec4 red = osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f);
    osg::Vec4 green = osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f);
    osg::Vec4 blue = osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f);
    c->push_back(red); //x red
    c->push_back(red);
    c->push_back(green); //y green
    c->push_back(green);
    c->push_back(blue); //z blue
    c->push_back(blue);
    c->push_back(red); //x-arrow red
    c->push_back(red);
    c->push_back(red);
    c->push_back(green); //y-arrow green
    c->push_back(green);
    c->push_back(green);
    c->push_back(blue); //z-arrow blue
    c->push_back(blue);
    c->push_back(blue);
    //如果没指定颜色则会变为黑色
    geom->setColorArray(c.get());
    geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

    osg::ref_ptr<osg::Vec3Array> n = new osg::Vec3Array();
    n->push_back(osg::Vec3(0.f,0.f,1.f));
    geom->setNormalArray(n.get());
    geom->setNormalBinding(osg::Geometry::BIND_OVERALL); //用一条法向绑定所有的顶点（顶点数组中）

    //三个轴
    geom->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, 6)); // X
    //geom->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::LINES, 2, 2)); // Y
    //geom->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::LINES, 4, 2)); // Z
    geom->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP, 6, 3));//X->
    geom->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP, 9, 3));//Y->
    geom->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP, 12, 3));//Z->

    osg::ref_ptr<osg::Geode> geode = new osg::Geode();
    geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
    geode->addDrawable(geom.get());

    //Label XYZ
    geode->addDrawable(createAixsLabel("X", pX + osg::Vec3(3.0f,0.f,0.f)));
    geode->addDrawable(createAixsLabel("Y", pY + osg::Vec3(0.0f,3.f,0.f)));
    geode->addDrawable(createAixsLabel("Z", pZ + osg::Vec3(0.0f,0.f,5.f)));
    return geode.release();
}

//创建坐标系label，如要支持中文，必须修改font为支持中文的字体
osg::ref_ptr<osg::Drawable> osgContainer::createAixsLabel(const std::string& text, const osg::Vec3& pos)
{
    osg::ref_ptr<osgText::Text> t = new osgText::Text;
    osg::ref_ptr<osgText::Font> font = osgText::readFontFile("fonts/isocp3_.ttf");
    t->setFont(font.get());
    t->setText(text,osgText::String::ENCODING_UTF8);
    t->setPosition(pos);
    t->setAlignment(osgText::Text::CENTER_CENTER);
    t->setAxisAlignment( osgText::Text::SCREEN );
    t->setCharacterSize(60.0f);
    t->setCharacterSizeMode( osgText::Text::SCREEN_COORDS );
    t->setFontResolution( 64, 64 );

    return t.release();
}

//osg::ref_ptr<osg::Group> osgContainer::createLight(osg::ref_ptr<osg::Node> node)
//{
//    osg::ref_ptr<osg::Group> lightroot = new osg::Group();//光源组（此处只有一个光源）

//    lightroot->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);
//    lightroot->getOrCreateStateSet()->setMode(GL_LIGHT1, osg::StateAttribute::ON);

//    osg::ref_ptr<osg::Light> light = new osg::Light();
//    light->setLightNum(1);
//    if(node)
//    {
//        node->computeBound();
//        osg::BoundingSphere bs=node->getBound();
//        light->setPosition(osg::Vec4(bs.center().x(),bs.center().y(),bs.center().z()+bs.radius(),1.0f));
//    }
//    light->setPosition(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
//    //light->setDirection(osg::Vec3(0.0f, 0.0f, -1.0f));
//    light->setDiffuse(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
//    //light->setSpecular(osg::Vec4(0.6f, 0.6f, 0.6f, 1.0f));
//    light->setAmbient(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));

//    light->setConstantAttenuation(1.0f);//恒衰减
//    light->setLinearAttenuation(0.1f);//线性衰减
//    light->setQuadraticAttenuation(0.0f);//二次方衰减

//    osg::ref_ptr<osg::LightSource> lightsource = new osg::LightSource();
//    lightsource->setLight(light.get());
//    lightsource->setLocalStateSetModes(osg::StateAttribute::ON);

//    lightroot->addChild(lightsource.get());

//    return lightroot.get();
//}


