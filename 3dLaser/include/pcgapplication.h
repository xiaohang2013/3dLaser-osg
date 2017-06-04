#ifndef PCGAPPLICATION_H
#define PCGAPPLICATION_H

#include <QApplication>
#include <QString>


class PCGApplication : public QApplication
{
public:
    enum HW_ARCHITECTURE {HW_32BIT=32,HW_64BIT=64};

    PCGApplication(int &argc, char *argv[]):QApplication(argc,argv){}
    ~PCGApplication(){}

    bool notify(QObject *rec, QEvent *ev);

    static const QString appName(){return tr("PCGware");}
    static const QString architecturalSuffix(const HW_ARCHITECTURE hw){return "_"+QString::number(int(hw))+"bit";}
    static const QString appArchitecturalName(const HW_ARCHITECTURE hw) {return appName() + architecturalSuffix(hw);}
    static const QString appVer() {return tr("1.0.0"); }
    static const QString completeName(const HW_ARCHITECTURE hw){return appArchitecturalName(hw) + " v" + appVer(); }
    static const QString organization(){return tr("PCG");}
    static const QString organizationHost() {return tr("http://___");}
    static const QString webSite() {return tr("http://___");}
    static const QString downloadSite() {return tr("http://___");}
    static const QString downloadUpdatesSite() {return downloadSite() + tr("/updates");}

//    static const QString pluginsPathRegisterKeyName() {return tr("pluginsPath");}
//    static const QString versionRegisterKeyName() {return tr("version");}
//    static const QString wordSizeKeyName() {return tr("wordSize");}

};

#endif // PCGAPPLICATION_H
