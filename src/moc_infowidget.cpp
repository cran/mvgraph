/****************************************************************************
** Meta object code from reading C++ file 'infowidget.h'
**
** Created: Mon May 25 17:39:24 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "infowidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infowidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Infowidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Infowidget[] = {
    "Infowidget\0\0index\0fillFields(int)\0"
};

const QMetaObject Infowidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Infowidget,
      qt_meta_data_Infowidget, 0 }
};

const QMetaObject *Infowidget::metaObject() const
{
    return &staticMetaObject;
}

void *Infowidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Infowidget))
        return static_cast<void*>(const_cast< Infowidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int Infowidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fillFields((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
