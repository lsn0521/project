/****************************************************************************
** Meta object code from reading C++ file 'menuwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menuwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menuwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MenuWindow_t {
    QByteArrayData data[11];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuWindow_t qt_meta_stringdata_MenuWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MenuWindow"
QT_MOC_LITERAL(1, 11, 11), // "connect_suc"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "connect_dis"
QT_MOC_LITERAL(4, 36, 9), // "read_data"
QT_MOC_LITERAL(5, 46, 18), // "on_Recombt_clicked"
QT_MOC_LITERAL(6, 65, 19), // "on_guicaibt_clicked"
QT_MOC_LITERAL(7, 85, 17), // "on_yuecai_clicked"
QT_MOC_LITERAL(8, 103, 17), // "on_yinpin_clicked"
QT_MOC_LITERAL(9, 121, 18), // "on_Orderbt_clicked"
QT_MOC_LITERAL(10, 140, 20) // "on_servicebt_clicked"

    },
    "MenuWindow\0connect_suc\0\0connect_dis\0"
    "read_data\0on_Recombt_clicked\0"
    "on_guicaibt_clicked\0on_yuecai_clicked\0"
    "on_yinpin_clicked\0on_Orderbt_clicked\0"
    "on_servicebt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuWindow[] = {

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
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuWindow *_t = static_cast<MenuWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connect_suc(); break;
        case 1: _t->connect_dis(); break;
        case 2: _t->read_data(); break;
        case 3: _t->on_Recombt_clicked(); break;
        case 4: _t->on_guicaibt_clicked(); break;
        case 5: _t->on_yuecai_clicked(); break;
        case 6: _t->on_yinpin_clicked(); break;
        case 7: _t->on_Orderbt_clicked(); break;
        case 8: _t->on_servicebt_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MenuWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MenuWindow.data,
      qt_meta_data_MenuWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MenuWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MenuWindow.stringdata0))
        return static_cast<void*>(const_cast< MenuWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MenuWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
