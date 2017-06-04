#ifndef INTERACTION_H
#define INTERACTION_H

#include <QObject>

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>

#include <osg/Node>
#include <osg/Geode>
#include <osg/Group>
#include <osg/MatrixTransform>
#include <osgFX/Scribe>
#include <osgGA/GUIEventHandler>




//对象选取事件处理器
class PickAndOtherEventToSignalHandler : public QObject,public osgGA::GUIEventHandler
{
     Q_OBJECT

public:

    PickAndOtherEventToSignalHandler():
      _mx(0.0f),
      _my(0.0f)
      { }

      ~PickAndOtherEventToSignalHandler()
      { }

        //事件处理函数
      bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
        //对象选取事件处理器
      void pick(osg::ref_ptr<osgViewer::View> view, float x, float y);


signals:
      void signalSendOutPickedNode(osg::Node*,osg::Node*);
      void signalSendOutDragging();

public:
    //得到鼠标的位置
    float _mx ;
    float _my;

};


#endif // INTERACTION_H
