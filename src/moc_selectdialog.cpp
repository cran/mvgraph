/****************************************************************************
** Meta object code from reading C++ file 'selectdialog.h'
**
** Created: Sat Dec 6 16:43:09 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "selectdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Selectdialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      38,   13,   13,   13, 0x08,
      72,   65,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Selectdialog[] = {
    "Selectdialog\0\0on_button_add_clicked()\0"
    "on_button_remove_clicked()\0result\0"
    "setOk(int)\0"
};

const QMetaObject Selectdialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Selectdialog,
      qt_meta_data_Selectdialog, 0 }
};

const QMetaObject *Selectdialog::metaObject() const
{
    return &staticMetaObject;
}

void *Selectdialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Selectdialog))
        return static_cast<void*>(const_cast< Selectdialog*>(this));
    if (!strcmp(_clname, "Ui::Select"))
        return static_cast< Ui::Select*>(const_cast< Selectdialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Selectdialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_button_add_clicked(); break;
        case 1: on_button_remove_clicked(); break;
        case 2: setOk((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
