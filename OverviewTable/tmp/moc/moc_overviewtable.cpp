/****************************************************************************
** Meta object code from reading C++ file 'overviewtable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../overviewtable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'overviewtable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OverviewTable_t {
    QByteArrayData data[16];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OverviewTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OverviewTable_t qt_meta_stringdata_OverviewTable = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OverviewTable"
QT_MOC_LITERAL(1, 14, 9), // "editClick"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "index"
QT_MOC_LITERAL(4, 31, 9), // "backColor"
QT_MOC_LITERAL(5, 41, 9), // "fontColor"
QT_MOC_LITERAL(6, 51, 4), // "font"
QT_MOC_LITERAL(7, 56, 11), // "borderWidth"
QT_MOC_LITERAL(8, 68, 11), // "borderColor"
QT_MOC_LITERAL(9, 80, 14), // "underlineColor"
QT_MOC_LITERAL(10, 95, 14), // "underlineWidth"
QT_MOC_LITERAL(11, 110, 4), // "mark"
QT_MOC_LITERAL(12, 115, 11), // "innerRadius"
QT_MOC_LITERAL(13, 127, 10), // "itemHeight"
QT_MOC_LITERAL(14, 138, 12), // "checkedColor"
QT_MOC_LITERAL(15, 151, 9) // "editImage"

    },
    "OverviewTable\0editClick\0\0index\0backColor\0"
    "fontColor\0font\0borderWidth\0borderColor\0"
    "underlineColor\0underlineWidth\0mark\0"
    "innerRadius\0itemHeight\0checkedColor\0"
    "editImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OverviewTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
      12,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // properties: name, type, flags
       4, QMetaType::QColor, 0x00095103,
       5, QMetaType::QColor, 0x00095103,
       6, QMetaType::QFont, 0x00095103,
       7, QMetaType::Int, 0x00095103,
       8, QMetaType::QColor, 0x00095103,
       9, QMetaType::QColor, 0x00095103,
      10, QMetaType::Int, 0x00095103,
      11, QMetaType::QPixmap, 0x00095103,
      12, QMetaType::Int, 0x00095103,
      13, QMetaType::Int, 0x00095103,
      14, QMetaType::QColor, 0x00095103,
      15, QMetaType::QPixmap, 0x00095103,

       0        // eod
};

void OverviewTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OverviewTable *_t = static_cast<OverviewTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->editClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (OverviewTable::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OverviewTable::editClick)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        OverviewTable *_t = static_cast<OverviewTable *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->backColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->fontColor(); break;
        case 2: *reinterpret_cast< QFont*>(_v) = _t->font(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->borderWidth(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->borderColor(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->underlineColor(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->underlineWidth(); break;
        case 7: *reinterpret_cast< QPixmap*>(_v) = _t->mark(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->innerRadius(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->itemHeight(); break;
        case 10: *reinterpret_cast< QColor*>(_v) = _t->checkedColor(); break;
        case 11: *reinterpret_cast< QPixmap*>(_v) = _t->editImage(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        OverviewTable *_t = static_cast<OverviewTable *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBackColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setFontColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setFont(*reinterpret_cast< QFont*>(_v)); break;
        case 3: _t->setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setBorderColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setUnderlineColor(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setUnderlineWidth(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setMark(*reinterpret_cast< QPixmap*>(_v)); break;
        case 8: _t->setInnerRadius(*reinterpret_cast< int*>(_v)); break;
        case 9: _t->setItemHeight(*reinterpret_cast< int*>(_v)); break;
        case 10: _t->setCheckedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 11: _t->setEditImage(*reinterpret_cast< QPixmap*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject OverviewTable::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OverviewTable.data,
      qt_meta_data_OverviewTable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OverviewTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OverviewTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OverviewTable.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OverviewTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void OverviewTable::editClick(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
