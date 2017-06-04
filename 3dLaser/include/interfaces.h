#ifndef MESHIOINTERFACE_H
#define MESHIOINTERFACE_H

#include <QTCore>
#include <QString>
#include <List>
#include <QStringList>


class MeshIOInterface : public QObject
{
public:
    class Format
    {
    public:
        Format(QString description,QString ex):description(description){extensions<<ex;}
        QString description;
        QStringList extensions;
    };

    MeshIOInterface();
    virtual ~MeshIOInterface(){}

    virtual QList<Format> importFormats() const = 0;
    virtual QList<Format> exportFormats() const = 0;

    /// callback used to actually load a mesh from a file
    virtual bool open(
        const QString &format,  /// the extension of the format,e.g. "OBJ"
        const QString &fileName /// the name of the file to be opened
            )=0;

    virtual bool save(
        const QString &format,  /// the extension of the format,e.g. "OBJ"
        const QString &fileName /// the name of the file to be opened
            )=0;


};

#endif // MESHIOINTERFACE_H
