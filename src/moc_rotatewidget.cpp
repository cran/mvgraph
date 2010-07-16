/****************************************************************************
** Meta object code from reading C++ file 'rotatewidget.h'
**
** Created: Thu Jul 15 12:50:31 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rotatewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rotatewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Rotatewidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x08,
      44,   36,   13,   13, 0x08,
      58,   36,   13,   13, 0x08,
      72,   36,   13,   13, 0x08,
      92,   86,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Rotatewidget[] = {
    "Rotatewidget\0\0state\0rotateAuto(int)\0"
    "toggled\0rotateX(bool)\0rotateY(bool)\0"
    "rotateZ(bool)\0value\0velocityChanged(int)\0"
};

const QMetaObject Rotatewidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Rotatewidget,
      qt_meta_data_Rotatewidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Rotatewidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Rotatewidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Rotatewidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Rotatewidget))
        return static_cast<void*>(const_cast< Rotatewidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int Rotatewidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rotateAuto((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: rotateX((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: rotateY((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: rotateZ((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: velocityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
