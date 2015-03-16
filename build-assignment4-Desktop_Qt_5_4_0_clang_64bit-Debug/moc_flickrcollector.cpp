/****************************************************************************
** Meta object code from reading C++ file 'flickrcollector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Assignment3/flickrcollector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flickrcollector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FlickrCollector_t {
    QByteArrayData data[12];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FlickrCollector_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FlickrCollector_t qt_meta_stringdata_FlickrCollector = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FlickrCollector"
QT_MOC_LITERAL(1, 16, 5), // "ready"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "failed"
QT_MOC_LITERAL(4, 30, 7), // "execute"
QT_MOC_LITERAL(5, 38, 16), // "downloadFinished"
QT_MOC_LITERAL(6, 55, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 70, 5), // "reply"
QT_MOC_LITERAL(8, 76, 9), // "printList"
QT_MOC_LITERAL(9, 86, 12), // "printDomTree"
QT_MOC_LITERAL(10, 99, 11), // "QDomElement"
QT_MOC_LITERAL(11, 111, 7) // "subRoot"

    },
    "FlickrCollector\0ready\0\0failed\0execute\0"
    "downloadFinished\0QNetworkReply*\0reply\0"
    "printList\0printDomTree\0QDomElement\0"
    "subRoot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FlickrCollector[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x0a /* Public */,
       5,    1,   47,    2, 0x0a /* Public */,
       8,    0,   50,    2, 0x0a /* Public */,
       9,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void FlickrCollector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FlickrCollector *_t = static_cast<FlickrCollector *>(_o);
        switch (_id) {
        case 0: _t->ready(); break;
        case 1: _t->failed(); break;
        case 2: _t->execute(); break;
        case 3: _t->downloadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->printList(); break;
        case 5: _t->printDomTree((*reinterpret_cast< QDomElement(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FlickrCollector::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlickrCollector::ready)) {
                *result = 0;
            }
        }
        {
            typedef void (FlickrCollector::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlickrCollector::failed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FlickrCollector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FlickrCollector.data,
      qt_meta_data_FlickrCollector,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FlickrCollector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlickrCollector::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FlickrCollector.stringdata))
        return static_cast<void*>(const_cast< FlickrCollector*>(this));
    return QObject::qt_metacast(_clname);
}

int FlickrCollector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FlickrCollector::ready()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void FlickrCollector::failed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
