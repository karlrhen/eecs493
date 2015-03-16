/****************************************************************************
** Meta object code from reading C++ file 'boximage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Assignment3/boximage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boximage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BoxImage_t {
    QByteArrayData data[19];
    char stringdata[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoxImage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoxImage_t qt_meta_stringdata_BoxImage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "BoxImage"
QT_MOC_LITERAL(1, 9, 21), // "addCollectionCallback"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "addImageCallback"
QT_MOC_LITERAL(4, 49, 17), // "deleteAllCallback"
QT_MOC_LITERAL(5, 67, 19), // "deleteImageCallback"
QT_MOC_LITERAL(6, 87, 19), // "insertImageCallback"
QT_MOC_LITERAL(7, 107, 28), // "insertMultipleImagesCallback"
QT_MOC_LITERAL(8, 136, 9), // "insertLoc"
QT_MOC_LITERAL(9, 146, 11), // "cutCallback"
QT_MOC_LITERAL(10, 158, 13), // "pasteCallback"
QT_MOC_LITERAL(11, 172, 12), // "copyCallback"
QT_MOC_LITERAL(12, 185, 4), // "quit"
QT_MOC_LITERAL(13, 190, 13), // "executeFlickr"
QT_MOC_LITERAL(14, 204, 15), // "addFlickrFailed"
QT_MOC_LITERAL(15, 220, 14), // "addFlickrReady"
QT_MOC_LITERAL(16, 235, 20), // "imageCollectorPixmap"
QT_MOC_LITERAL(17, 256, 6), // "pixmap"
QT_MOC_LITERAL(18, 263, 12) // "playCallback"

    },
    "BoxImage\0addCollectionCallback\0\0"
    "addImageCallback\0deleteAllCallback\0"
    "deleteImageCallback\0insertImageCallback\0"
    "insertMultipleImagesCallback\0insertLoc\0"
    "cutCallback\0pasteCallback\0copyCallback\0"
    "quit\0executeFlickr\0addFlickrFailed\0"
    "addFlickrReady\0imageCollectorPixmap\0"
    "pixmap\0playCallback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoxImage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    1,   94,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    1,  104,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,   17,
    QMetaType::Void,

       0        // eod
};

void BoxImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BoxImage *_t = static_cast<BoxImage *>(_o);
        switch (_id) {
        case 0: _t->addCollectionCallback(); break;
        case 1: _t->addImageCallback(); break;
        case 2: _t->deleteAllCallback(); break;
        case 3: _t->deleteImageCallback(); break;
        case 4: _t->insertImageCallback(); break;
        case 5: _t->insertMultipleImagesCallback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->cutCallback(); break;
        case 7: _t->pasteCallback(); break;
        case 8: _t->copyCallback(); break;
        case 9: _t->quit(); break;
        case 10: _t->executeFlickr(); break;
        case 11: _t->addFlickrFailed(); break;
        case 12: _t->addFlickrReady(); break;
        case 13: _t->imageCollectorPixmap((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 14: _t->playCallback(); break;
        default: ;
        }
    }
}

const QMetaObject BoxImage::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_BoxImage.data,
      qt_meta_data_BoxImage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BoxImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoxImage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BoxImage.stringdata))
        return static_cast<void*>(const_cast< BoxImage*>(this));
    return QFrame::qt_metacast(_clname);
}

int BoxImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
