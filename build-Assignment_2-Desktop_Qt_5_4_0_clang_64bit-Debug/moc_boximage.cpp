/****************************************************************************
** Meta object code from reading C++ file 'boximage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Assignment_2_V2/boximage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boximage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BoxImage_t {
    QByteArrayData data[14];
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
QT_MOC_LITERAL(1, 9, 36), // "assign_add_collection_button_..."
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 31), // "assign_add_image_button_content"
QT_MOC_LITERAL(4, 79, 32), // "assign_remove_all_button_content"
QT_MOC_LITERAL(5, 112, 26), // "assign_not_implemented_msg"
QT_MOC_LITERAL(6, 139, 18), // "assign_quit_action"
QT_MOC_LITERAL(7, 158, 18), // "assign_copy_action"
QT_MOC_LITERAL(8, 177, 19), // "assign_paste_action"
QT_MOC_LITERAL(9, 197, 17), // "assign_cut_action"
QT_MOC_LITERAL(10, 215, 22), // "insert_multiple_images"
QT_MOC_LITERAL(11, 238, 16), // "QVector<QPixmap>"
QT_MOC_LITERAL(12, 255, 10), // "pixmapList"
QT_MOC_LITERAL(13, 266, 9) // "insertLoc"

    },
    "BoxImage\0assign_add_collection_button_content\0"
    "\0assign_add_image_button_content\0"
    "assign_remove_all_button_content\0"
    "assign_not_implemented_msg\0"
    "assign_quit_action\0assign_copy_action\0"
    "assign_paste_action\0assign_cut_action\0"
    "insert_multiple_images\0QVector<QPixmap>\0"
    "pixmapList\0insertLoc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoxImage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    2,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,

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
        case 3: _t->assign_not_implemented_msg(); break;
        case 4: _t->assign_quit_action(); break;
        case 5: _t->assign_copy_action(); break;
        case 6: _t->assign_paste_action(); break;
        case 7: _t->assign_cut_action(); break;
        case 8: _t->insert_multiple_images((*reinterpret_cast< QVector<QPixmap>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QPixmap> >(); break;
            }
            break;
        }
    }
}

const QMetaObject BoxImage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BoxImage.data,
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
    return QWidget::qt_metacast(_clname);
}

int BoxImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
