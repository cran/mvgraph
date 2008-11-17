/****************************************************************************
** Meta object code from reading C++ file 'iconview.h'
**
** Created: Sat Dec 6 15:51:16 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "iconview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iconview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Iconview[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      19,    9,    9,    9, 0x08,
      28,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Iconview[] = {
    "Iconview\0\0rotate()\0zoomIn()\0zoomOut()\0"
};

const QMetaObject Iconview::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Iconview,
      qt_meta_data_Iconview, 0 }
};

const QMetaObject *Iconview::metaObject() const
{
    return &staticMetaObject;
}

void *Iconview::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Iconview))
        return static_cast<void*>(const_cast< Iconview*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Iconview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rotate(); break;
        case 1: zoomIn(); break;
        case 2: zoomOut(); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
