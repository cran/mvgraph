/****************************************************************************
** Meta object code from reading C++ file 'multiDialog.h'
**
** Created: Thu Jul 15 12:50:26 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "multiDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MultiDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      37,   12,   12,   12, 0x08,
      70,   64,   12,   12, 0x08,
      98,   64,   12,   12, 0x08,
     132,  126,   12,   12, 0x08,
     166,  126,   12,   12, 0x08,
     211,  203,   12,   12, 0x08,
     247,  203,   12,   12, 0x08,
     286,  203,   12,   12, 0x08,
     324,   64,   12,   12, 0x08,
     364,  357,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MultiDialog[] = {
    "MultiDialog\0\0on_button_add_clicked()\0"
    "on_button_remove_clicked()\0index\0"
    "xC_currentIndexChanged(int)\0"
    "yC_currentIndexChanged(int)\0state\0"
    "on_checkBox_add_stateChanged(int)\0"
    "on_checkBox_labels_stateChanged(int)\0"
    "checked\0on_radioButton_simple_toggled(bool)\0"
    "on_radioButton_boardered_toggled(bool)\0"
    "on_radioButton_diamonds_toggled(bool)\0"
    "on_tabWidget_currentChanged(int)\0"
    "result\0setOk(int)\0"
};

const QMetaObject MultiDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MultiDialog,
      qt_meta_data_MultiDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MultiDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MultiDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MultiDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MultiDialog))
        return static_cast<void*>(const_cast< MultiDialog*>(this));
    if (!strcmp(_clname, "Ui::MultiGraph"))
        return static_cast< Ui::MultiGraph*>(const_cast< MultiDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MultiDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_button_add_clicked(); break;
        case 1: on_button_remove_clicked(); break;
        case 2: xC_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: yC_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_checkBox_add_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_checkBox_labels_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_radioButton_simple_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: on_radioButton_boardered_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: on_radioButton_diamonds_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: setOk((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
