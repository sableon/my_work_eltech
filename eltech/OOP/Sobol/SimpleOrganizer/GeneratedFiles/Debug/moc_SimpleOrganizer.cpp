/****************************************************************************
** Meta object code from reading C++ file 'SimpleOrganizer.h'
**
** Created: Wed 22. May 16:28:07 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SimpleOrganizer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimpleOrganizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimpleOrganizer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SimpleOrganizer[] = {
    "SimpleOrganizer\0\0DataSelected(QDate)\0"
};

const QMetaObject SimpleOrganizer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SimpleOrganizer,
      qt_meta_data_SimpleOrganizer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimpleOrganizer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimpleOrganizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimpleOrganizer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleOrganizer))
        return static_cast<void*>(const_cast< SimpleOrganizer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SimpleOrganizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: DataSelected((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
