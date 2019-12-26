/****************************************************************************
** Meta object code from reading C++ file 'helpother.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../remote_assistance/helpother.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'helpother.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_helpOther_t {
    QByteArrayData data[7];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_helpOther_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_helpOther_t qt_meta_stringdata_helpOther = {
    {
QT_MOC_LITERAL(0, 0, 9), // "helpOther"
QT_MOC_LITERAL(1, 10, 11), // "sendOsignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 20), // "on_break_btn_clicked"
QT_MOC_LITERAL(4, 44, 9), // "setUpConn"
QT_MOC_LITERAL(5, 54, 12), // "setCompleter"
QT_MOC_LITERAL(6, 67, 9) // "errorConn"

    },
    "helpOther\0sendOsignal\0\0on_break_btn_clicked\0"
    "setUpConn\0setCompleter\0errorConn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_helpOther[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void helpOther::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        helpOther *_t = static_cast<helpOther *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendOsignal(); break;
        case 1: _t->on_break_btn_clicked(); break;
        case 2: _t->setUpConn(); break;
        case 3: _t->setCompleter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->errorConn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (helpOther::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&helpOther::sendOsignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject helpOther::staticMetaObject = {
    { &DMainWindow::staticMetaObject, qt_meta_stringdata_helpOther.data,
      qt_meta_data_helpOther,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *helpOther::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *helpOther::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_helpOther.stringdata0))
        return static_cast<void*>(this);
    return DMainWindow::qt_metacast(_clname);
}

int helpOther::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void helpOther::sendOsignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
