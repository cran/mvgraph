/****************************************************************************
** Meta object code from reading C++ file 'groupwidget.h'
**
** Created: Mon May 25 17:37:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "groupwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Groupwidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,
      49,   37,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   13,   12,   12, 0x08,
      92,   13,   12,   12, 0x08,
     111,   13,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Groupwidget[] = {
    "Groupwidget\0\0index\0indexChanged(int)\0"
    "index,color\0colorChanged(int,QColor)\0"
    "groupClicked(int)\0buttonClicked(int)\0"
    "currentIconChanged(int)\0"
};

const QMetaObject Groupwidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Groupwidget,
      qt_meta_data_Groupwidget, 0 }
};

const QMetaObject *Groupwidget::metaObject() const
{
    return &staticMetaObject;
}

void *Groupwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Groupwidget))
        return static_cast<void*>(const_cast< Groupwidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int Groupwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: indexChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: colorChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2]))); break;
        case 2: groupClicked((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: buttonClicked((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: currentIconChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Groupwidget::indexChanged(const int & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Groupwidget::colorChanged(const int & _t1, const QColor & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
