/****************************************************************************
** Meta object code from reading C++ file 'interaction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../3dLaser/include/interaction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PickAndOtherEventToSignalHandler_t {
    QByteArrayData data[5];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PickAndOtherEventToSignalHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PickAndOtherEventToSignalHandler_t qt_meta_stringdata_PickAndOtherEventToSignalHandler = {
    {
QT_MOC_LITERAL(0, 0, 32), // "PickAndOtherEventToSignalHandler"
QT_MOC_LITERAL(1, 33, 23), // "signalSendOutPickedNode"
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 10), // "osg::Node*"
QT_MOC_LITERAL(4, 69, 21) // "signalSendOutDragging"

    },
    "PickAndOtherEventToSignalHandler\0"
    "signalSendOutPickedNode\0\0osg::Node*\0"
    "signalSendOutDragging"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PickAndOtherEventToSignalHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       4,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void,

       0        // eod
};

void PickAndOtherEventToSignalHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PickAndOtherEventToSignalHandler *_t = static_cast<PickAndOtherEventToSignalHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSendOutPickedNode((*reinterpret_cast< osg::Node*(*)>(_a[1])),(*reinterpret_cast< osg::Node*(*)>(_a[2]))); break;
        case 1: _t->signalSendOutDragging(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PickAndOtherEventToSignalHandler::*_t)(osg::Node * , osg::Node * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PickAndOtherEventToSignalHandler::signalSendOutPickedNode)) {
                *result = 0;
            }
        }
        {
            typedef void (PickAndOtherEventToSignalHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PickAndOtherEventToSignalHandler::signalSendOutDragging)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject PickAndOtherEventToSignalHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PickAndOtherEventToSignalHandler.data,
      qt_meta_data_PickAndOtherEventToSignalHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PickAndOtherEventToSignalHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PickAndOtherEventToSignalHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PickAndOtherEventToSignalHandler.stringdata0))
        return static_cast<void*>(const_cast< PickAndOtherEventToSignalHandler*>(this));
    if (!strcmp(_clname, "osgGA::GUIEventHandler"))
        return static_cast< osgGA::GUIEventHandler*>(const_cast< PickAndOtherEventToSignalHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int PickAndOtherEventToSignalHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PickAndOtherEventToSignalHandler::signalSendOutPickedNode(osg::Node * _t1, osg::Node * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PickAndOtherEventToSignalHandler::signalSendOutDragging()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
