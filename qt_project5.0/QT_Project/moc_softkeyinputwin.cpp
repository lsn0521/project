/****************************************************************************
** Meta object code from reading C++ file 'softkeyinputwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "softkeyinputwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'softkeyinputwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SoftKeyInputWin_t {
    QByteArrayData data[6];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoftKeyInputWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoftKeyInputWin_t qt_meta_stringdata_SoftKeyInputWin = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SoftKeyInputWin"
QT_MOC_LITERAL(1, 16, 9), // "backspace"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "space"
QT_MOC_LITERAL(4, 33, 12), // "button_click"
QT_MOC_LITERAL(5, 46, 8) // "selectzh"

    },
    "SoftKeyInputWin\0backspace\0\0space\0"
    "button_click\0selectzh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoftKeyInputWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x09 /* Protected */,
       3,    0,   35,    2, 0x09 /* Protected */,
       4,    0,   36,    2, 0x09 /* Protected */,
       5,    0,   37,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SoftKeyInputWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SoftKeyInputWin *_t = static_cast<SoftKeyInputWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backspace(); break;
        case 1: _t->space(); break;
        case 2: _t->button_click(); break;
        case 3: _t->selectzh(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SoftKeyInputWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SoftKeyInputWin.data,
      qt_meta_data_SoftKeyInputWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SoftKeyInputWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoftKeyInputWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SoftKeyInputWin.stringdata0))
        return static_cast<void*>(const_cast< SoftKeyInputWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int SoftKeyInputWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
