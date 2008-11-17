/****************************************************************************
** Meta object code from reading C++ file 'identifywidget.h'
**
** Created: Mon May 25 17:38:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "identifywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'identifywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Identifywidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Identifywidget[] = {
    "Identifywidget\0\0index\0identify(int)\0"
};

const QMetaObject Identifywidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Identifywidget,
      qt_meta_data_Identifywidget, 0 }
};

const QMetaObject *Identifywidget::metaObject() const
{
    return &staticMetaObject;
}

void *Identifywidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Identifywidget))
        return static_cast<void*>(const_cast< Identifywidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int Identifywidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: identify((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Identifywidget::identify(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
