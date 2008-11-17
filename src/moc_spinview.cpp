/****************************************************************************
** Meta object code from reading C++ file 'spinview.h'
**
** Created: Sun Dec 7 15:26:22 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "spinview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spinview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Spinview[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x05,
      38,   10,    9,    9, 0x05,
      60,   10,    9,    9, 0x05,
      87,   82,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     104,   10,    9,    9, 0x0a,
     117,   10,    9,    9, 0x0a,
     130,   10,    9,    9, 0x0a,
     143,    9,    9,    9, 0x0a,
     156,    9,    9,    9, 0x0a,
     170,    9,    9,    9, 0x0a,
     184,    9,    9,    9, 0x0a,
     206,  198,    9,    9, 0x0a,
     227,  222,    9,    9, 0x0a,
     260,  254,    9,    9, 0x0a,
     284,  274,    9,    9, 0x0a,
     319,  303,    9,    9, 0x0a,
     340,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Spinview[] = {
    "Spinview\0\0angle\0xRotationChanged(int)\0"
    "yRotationChanged(int)\0zRotationChanged(int)\0"
    "zoom\0zoomChanged(int)\0rotateX(int)\0"
    "rotateY(int)\0rotateZ(int)\0autoRotate()\0"
    "autoRotateX()\0autoRotateY()\0autoRotateZ()\0"
    "newZoom\0changeZoom(int)\0icon\0"
    "changeIcon(Iconview::Icon)\0index\0"
    "identify(int)\0new_index\0setGroupIndex(int)\0"
    "new_index,color\0setColor(int,QColor)\0"
    "blink()\0"
};

const QMetaObject Spinview::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Spinview,
      qt_meta_data_Spinview, 0 }
};

const QMetaObject *Spinview::metaObject() const
{
    return &staticMetaObject;
}

void *Spinview::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Spinview))
        return static_cast<void*>(const_cast< Spinview*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Spinview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: zoomChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: rotateX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: rotateY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: rotateZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: autoRotate(); break;
        case 8: autoRotateX(); break;
        case 9: autoRotateY(); break;
        case 10: autoRotateZ(); break;
        case 11: changeZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: changeIcon((*reinterpret_cast< Iconview::Icon(*)>(_a[1]))); break;
        case 13: identify((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: setGroupIndex((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 15: setColor((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2]))); break;
        case 16: blink(); break;
        }
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Spinview::xRotationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Spinview::yRotationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Spinview::zRotationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Spinview::zoomChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
