/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "slot_addInfo"
QT_MOC_LITERAL(4, 46, 11), // "CHumanInfo&"
QT_MOC_LITERAL(5, 58, 9), // "humanInfo"
QT_MOC_LITERAL(6, 68, 15), // "slot_updateInfo"
QT_MOC_LITERAL(7, 84, 25), // "on_checkAllButton_clicked"
QT_MOC_LITERAL(8, 110, 7), // "checked"
QT_MOC_LITERAL(9, 118, 16), // "slot_itemChanged"
QT_MOC_LITERAL(10, 135, 14), // "QStandardItem*"
QT_MOC_LITERAL(11, 150, 4), // "item"
QT_MOC_LITERAL(12, 155, 20), // "on_delButton_clicked"
QT_MOC_LITERAL(13, 176, 12), // "slot_popMenu"
QT_MOC_LITERAL(14, 189, 3), // "pos"
QT_MOC_LITERAL(15, 193, 14), // "slot_actUpdate"
QT_MOC_LITERAL(16, 208, 14) // "slot_actDelete"

    },
    "MainWindow\0on_addButton_clicked\0\0"
    "slot_addInfo\0CHumanInfo&\0humanInfo\0"
    "slot_updateInfo\0on_checkAllButton_clicked\0"
    "checked\0slot_itemChanged\0QStandardItem*\0"
    "item\0on_delButton_clicked\0slot_popMenu\0"
    "pos\0slot_actUpdate\0slot_actDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
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
       3,    1,   60,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       7,    1,   66,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    1,   73,    2, 0x08 /* Private */,
      15,    0,   76,    2, 0x08 /* Private */,
      16,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 4,    5,
    QMetaType::Bool, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Bool, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QPoint,   14,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_addButton_clicked(); break;
        case 1: { bool _r = _t->slot_addInfo((*reinterpret_cast< CHumanInfo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->slot_updateInfo((*reinterpret_cast< CHumanInfo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_checkAllButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: { bool _r = _t->slot_itemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->on_delButton_clicked(); break;
        case 6: { bool _r = _t->slot_popMenu((*reinterpret_cast< const QPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->slot_actUpdate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->slot_actDelete();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
