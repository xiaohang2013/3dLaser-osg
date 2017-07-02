#-------------------------------------------------
#
# Project created by QtCreator 2016-10-09T22:18:31
#
#-------------------------------------------------
include(../general.pri)
win32 {
QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01

DEFINES += _ATL_XP_TARGETING
QMAKE_CFLAGS += /D_USING_V140_SDK71_
QMAKE_CXXFLAGS += /D_USING_V140_SDK71_
LIBS += -L$$quote(C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib)
INCLUDEPATH += $$quote(C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include)
}
INCLUDEPATH += ../.. \
               $$PWD/include/\
    $$(OSG_ROOT)/include \
    $$(OSG_ROOT)/3rdParty/x86/include \
    $$(OSG_ROOT)/3rdParty/x86/include/boost \

DEPENDPATH += . \
              $$(OSG_ROOT)/include

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3dCurving
TEMPLATE = app
CONFIG += console

SOURCES += \
    $$PWD/source/parawindow.cpp \
    $$PWD/source/markwindow.cpp \
    $$PWD/source/mainwindow.cpp\
    $$PWD/source/mcurvwindow.cpp \
    $$PWD/source/view.cpp \
    $$PWD/source/file.cpp \
    $$PWD/source/main.cpp \
    $$PWD/source/osgContainer.cpp \
    $$PWD/source/mytrackballmanipulator.cpp \
    $$PWD/source/pcgapplication.cpp \
    $$PWD/source/interfaces.cpp \
    $$PWD/source/meshinterface.cpp \
    $$PWD/source/osginterface.cpp \
    $$PWD/source/visitor.cpp \
    $$PWD/source/interaction.cpp \
    $$PWD/source/pcgmath.cpp \
    $$PWD/source/geometrymath.cpp \
    $$PWD/source/systemfontfunction.cpp \
    $$PWD/source/mytrackballmanipulator.cpp \
    $$PWD/source/qwidgetinosg.cpp \
    $$PWD/source/imagemath.cpp \
    $$PWD/source/quadtreenode.cpp \
    $$PWD/source/parameter.cpp \
    source/ctrlcard.cpp

HEADERS  += \
    $$PWD/include/mainwindow.h\
    $$PWD/include/markwindow.h\
    $$PWD/include/parawindow.h\
    $$PWD/include/mcurvwindow.h\
    $$PWD/include/view.h \
    $$PWD/include/file.h \
    $$PWD/include/macro.h \
    $$PWD/include/osgContainer.h \
    $$PWD/include/mytrackballmanipulator.h \
    $$PWD/include/pcgapplication.h \
    $$PWD/include/pcgexception.h \
    $$PWD/include/interfaces.h \
    $$PWD/include/meshinterface.h \
    $$PWD/include/osginterface.h \
    $$PWD/include/visitor.h \
    $$PWD/include/interaction.h \
    $$PWD/include/pcgmath.h \
    $$PWD/include/geometrymath.h \
    $$PWD/include/parameter.h \
    $$PWD/include/linefunctor.h \
    $$PWD/include/systemfontfunction.h \
    $$PWD/include/mytrackballmanipulator.h \
    $$PWD/include/qwidgetinosg.h \
    $$PWD/include/imagemath.h \
    $$PWD/include/quadtreenode.h \
    $$PWD/include/adt8933.h \
    $$PWD/include/ctrlcard.h


FORMS    += \
    $$PWD/ui/mainwindow.ui \
    $$PWD/ui/parawindow.ui \
    $$PWD/ui/mcurvwindow.ui\
    $$PWD/ui/markwindow.ui

RESOURCES += \
    $$PWD/ui/icon.qrc

CONFIG(debug,debug|release){

LIBS += \
        $$PWD/lib/adt8933.lib\
        $$(OSG_ROOT)\lib\OpenThreadsd.lib\
        $$(OSG_ROOT)\lib\osgAnimationd.lib\
        $$(OSG_ROOT)\lib\osgd.lib\
        $$(OSG_ROOT)\lib\osgDBd.lib\
        $$(OSG_ROOT)\lib\osgFXd.lib\
        $$(OSG_ROOT)\lib\osgGAd.lib\
        $$(OSG_ROOT)\lib\osgManipulatord.lib\
        $$(OSG_ROOT)\lib\osgParticled.lib\
        $$(OSG_ROOT)\lib\osgPresentationd.lib\
        $$(OSG_ROOT)\lib\osgQtd.lib\
        $$(OSG_ROOT)\lib\osgShadowd.lib\
        $$(OSG_ROOT)\lib\osgSimd.lib\
        $$(OSG_ROOT)\lib\osgTerraind.lib\
        $$(OSG_ROOT)\lib\osgTextd.lib\
        $$(OSG_ROOT)\lib\osgUtild.lib\
        $$(OSG_ROOT)\lib\osgViewerd.lib\
        $$(OSG_ROOT)\lib\osgVolumed.lib\
        $$(OSG_ROOT)\lib\osgWidgetd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\caresd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\fftssd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\freetype250_D.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\giflibd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\glut32d.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icuind.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icuiod.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\iculed.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\iculxd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icutestd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icutud.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icuucd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\jpegd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libcollada14dom22-d.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libcurld.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libexpatd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libexpatwd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libpng16d.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libpng16_staticd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libtiff.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libxml2_a_dllD.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libxml2_aD.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libxml2D.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\minizipD.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\pcrecppd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\pcred.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\pcreposixd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\posh_d.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\proj.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\squish_d.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\testplugd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\zlibd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\zlibstaticd.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_atomic-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_chrono-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_context-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_coroutine-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_date_time-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_exception-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_filesystem-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_graph-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_iostreams-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_locale-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_log_setup-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_log-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_c99f-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_c99l-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_c99-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_tr1f-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_tr1l-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_tr1-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_prg_exec_monitor-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_program_options-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_python-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_random-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_regex-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_signals-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_system-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_test_exec_monitor-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_thread-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_timer-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_unit_test_framework-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_wave-vc120-mt-gd-1_55.lib\
        User32.lib\
        gdi32.lib\
        kernel32.lib\
        Advapi32.lib

} else {

LIBS += \
        $$PWD/lib/adt8933.lib\
        $$(OSG_ROOT)\lib\OpenThreads.lib\
        $$(OSG_ROOT)\lib\osgAnimation.lib\
        $$(OSG_ROOT)\lib\osg.lib\
        $$(OSG_ROOT)\lib\osgDB.lib\
        $$(OSG_ROOT)\lib\osgFX.lib\
        $$(OSG_ROOT)\lib\osgGA.lib\
        $$(OSG_ROOT)\lib\osgManipulator.lib\
        $$(OSG_ROOT)\lib\osgParticle.lib\
        $$(OSG_ROOT)\lib\osgPresentation.lib\
        $$(OSG_ROOT)\lib\osgQt.lib\
        $$(OSG_ROOT)\lib\osgShadow.lib\
        $$(OSG_ROOT)\lib\osgSim.lib\
        $$(OSG_ROOT)\lib\osgTerrain.lib\
        $$(OSG_ROOT)\lib\osgText.lib\
        $$(OSG_ROOT)\lib\osgUtil.lib\
        $$(OSG_ROOT)\lib\osgViewer.lib\
        $$(OSG_ROOT)\lib\osgVolume.lib\
        $$(OSG_ROOT)\lib\osgWidget.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\cares.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\fftss.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\freetype250.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\giflib.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\glut32.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icuin.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icuio.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icule.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\iculx.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icutest.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icutu.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\icuuc.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\jpeg.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libcollada14dom22.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libcurl.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libexpat.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libexpatw.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libpng16.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libpng16_static.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libtiff.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libxml2_a_dll.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libxml2_a.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libxml2.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\minizip.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\pcrecpp.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\pcre.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\pcreposix.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\posh.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\proj.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\squish.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\testplug.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\zlib.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\zlibstatic.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_atomic-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_chrono-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_context-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_coroutine-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_date_time-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_exception-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_filesystem-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_graph-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_iostreams-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_locale-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_log_setup-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_log-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_c99f-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_c99l-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_c99-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_tr1f-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_tr1l-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_math_tr1-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_prg_exec_monitor-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_program_options-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_python-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_random-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_regex-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_signals-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_system-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_test_exec_monitor-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_thread-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_timer-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_unit_test_framework-vc120-mt-gd-1_55.lib\
        $$(OSG_ROOT)\3rdParty\x86\lib\libboost_wave-vc120-mt-gd-1_55.lib\
        User32.lib\
        gdi32.lib\
        kernel32.lib\
        Advapi32.lib

}

