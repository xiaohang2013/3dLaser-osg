#ifndef MYTRACKBALLMANIPULATOR_H
#define MYTRACKBALLMANIPULATOR_H

#include <osgGA/TrackballManipulator>


class MyTrackballManipulator : public osgGA::TrackballManipulator
{
    typedef osgGA::TrackballManipulator inherited;

public:
    MyTrackballManipulator(osg::Camera *camera, int flags = DEFAULT_SETTINGS );
    ~MyTrackballManipulator(){};


protected:
    virtual bool handleMouseWheel( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us );

// public functions
public:
    bool isPerspectiveProjection();
    bool isOrthoProjection();

private:
    osg::ref_ptr<osg::Camera> _camera;


};

#endif // MYTRACKBALLMANIPULATOR_H
