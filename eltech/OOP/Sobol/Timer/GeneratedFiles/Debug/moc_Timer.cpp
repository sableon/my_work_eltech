/****************************************************************************
** Meta object code from reading C++ file 'Timer.h'
**
** Created: Wed 22. May 16:08:35 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Timer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Timer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Timer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      24,    6,    6,    6, 0x0a,
      43,    6,    6,    6, 0x0a,
      61,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Timer[] = {
    "Timer\0\0ChangeMode(bool)\0StartStopClicked()\0"
    "ShowHideClicked()\0TimerSlot()\0"
};

const QMetaObject Timer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Timer,
      qt_meta_data_Timer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Timer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Timer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Timer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Timer))
        return static_cast<void*>(const_cast< Timer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Timer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ChangeMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: StartStopClicked(); break;
        case 2: ShowHideClicked(); break;
        case 3: TimerSlot(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
