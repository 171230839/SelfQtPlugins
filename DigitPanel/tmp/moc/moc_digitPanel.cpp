/****************************************************************************
** Meta object code from reading C++ file 'digitPanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../digitPanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'digitPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DigitPanel_t {
    QByteArrayData data[7];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DigitPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DigitPanel_t qt_meta_stringdata_DigitPanel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DigitPanel"
QT_MOC_LITERAL(1, 11, 11), // "borderColor"
QT_MOC_LITERAL(2, 23, 11), // "borderWidth"
QT_MOC_LITERAL(3, 35, 9), // "fontColor"
QT_MOC_LITERAL(4, 45, 9), // "backColor"
QT_MOC_LITERAL(5, 55, 14), // "clickBackColor"
QT_MOC_LITERAL(6, 70, 10) // "clickImage"

    },
    "DigitPanel\0borderColor\0borderWidth\0"
    "fontColor\0backColor\0clickBackColor\0"
    "clickImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DigitPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QColor, 0x00095103,
       2, QMetaType::Int, 0x00095103,
       3, QMetaType::QColor, 0x00095103,
       4, QMetaType::QColor, 0x00095103,
       5, QMetaType::QColor, 0x00095103,
       6, QMetaType::QPixmap, 0x00095103,

       0        // eod
};

void DigitPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        DigitPanel *_t = static_cast<DigitPanel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->borderColor(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->borderWidth(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->fontColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->backColor(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->clickBackColor(); break;
        case 5: *reinterpret_cast< QPixmap*>(_v) = _t->clickImage(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        DigitPanel *_t = static_cast<DigitPanel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBorderColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setFontColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setBackColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setClickBackColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setClickImage(*reinterpret_cast< QPixmap*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject DigitPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DigitPanel.data,
      qt_meta_data_DigitPanel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DigitPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DigitPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DigitPanel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DigitPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
