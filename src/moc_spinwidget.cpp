/****************************************************************************
** Meta object code from reading C++ file 'spinwidget.h'
**
** Created: Mon May 25 17:41:18 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "spinwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spinwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Spinwidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,
      35,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     145,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Spinwidget[] = {
    "Spinwidget\0\0value\0zoomChanged(int)\0"
    "zoomInClicked()\0zoomOutClicked()\0"
    "setRotateMode()\0setMoveMode()\0"
    "setBrushMode()\0setInfoMode()\0"
    "setIdentifyMode()\0changeIcon()\0"
};

const QMetaObject Spinwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Spinwidget,
      qt_meta_data_Spinwidget, 0 }
};

const QMetaObject *Spinwidget::metaObject() const
{
    return &staticMetaObject;
}

void *Spinwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Spinwidget))
        return static_cast<void*>(const_cast< Spinwidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Spinwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: zoomChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: zoomInClicked(); break;
        case 2: zoomOutClicked(); break;
        case 3: setRotateMode(); break;
        case 4: setMoveMode(); break;
        case 5: setBrushMode(); break;
        case 6: setInfoMode(); break;
        case 7: setIdentifyMode(); break;
        case 8: changeIcon(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE