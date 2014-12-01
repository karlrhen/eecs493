/****************************************************************************
** Meta object code from reading C++ file 'boximage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Assignment_2/boximage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boximage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BoxImage_t {
    QByteArrayData data[5];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoxImage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoxImage_t qt_meta_stringdata_BoxImage = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 36),
QT_MOC_LITERAL(2, 46, 0),
QT_MOC_LITERAL(3, 47, 31),
QT_MOC_LITERAL(4, 79, 32)
    },
    "BoxImage\0assign_add_collection_button_content\0"
    "\0assign_add_image_button_content\0"
    "assign_remove_all_button_content"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoxImage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BoxImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BoxImage *_t = static_cast<BoxImage *>(_o);
        switch (_id) {
        case 0: _t->assign_add_collection_button_content(); break;
        case 1: _t->assign_add_image_button_content(); break;
        case 2: _t->assign_remove_all_button_content(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BoxImage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BoxImage.data,
      qt_meta_data_BoxImage,  qt_static_metacall, 0, 0}
};


const QMetaObject *BoxImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoxImage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BoxImage.stringdata))
        return static_cast<void*>(const_cast< BoxImage*>(this));
    return QWidget::qt_metacast(_clname);
}

int BoxImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
