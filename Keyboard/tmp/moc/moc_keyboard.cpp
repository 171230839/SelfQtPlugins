/****************************************************************************
** Meta object code from reading C++ file 'keyboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../keyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Keyboard_t {
    QByteArrayData data[19];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Keyboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Keyboard_t qt_meta_stringdata_Keyboard = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Keyboard"
QT_MOC_LITERAL(1, 9, 11), // "borderColor"
QT_MOC_LITERAL(2, 21, 11), // "borderWidth"
QT_MOC_LITERAL(3, 33, 9), // "fontColor"
QT_MOC_LITERAL(4, 43, 9), // "backColor"
QT_MOC_LITERAL(5, 53, 9), // "hanziFont"
QT_MOC_LITERAL(6, 63, 14), // "hanziFontColor"
QT_MOC_LITERAL(7, 78, 14), // "hanziBackColor"
QT_MOC_LITERAL(8, 93, 15), // "showLabelHeight"
QT_MOC_LITERAL(9, 109, 16), // "hanziPanelHeight"
QT_MOC_LITERAL(10, 126, 8), // "omitIcon"
QT_MOC_LITERAL(11, 135, 12), // "omitIconSize"
QT_MOC_LITERAL(12, 148, 10), // "clickImage"
QT_MOC_LITERAL(13, 159, 15), // "shiftClickImage"
QT_MOC_LITERAL(14, 175, 16), // "ensureClickImage"
QT_MOC_LITERAL(15, 192, 14), // "clickBackColor"
QT_MOC_LITERAL(16, 207, 18), // "showHanziBackColor"
QT_MOC_LITERAL(17, 226, 18), // "showHanziWordColor"
QT_MOC_LITERAL(18, 245, 18) // "showHanziFontColor"

    },
    "Keyboard\0borderColor\0borderWidth\0"
    "fontColor\0backColor\0hanziFont\0"
    "hanziFontColor\0hanziBackColor\0"
    "showLabelHeight\0hanziPanelHeight\0"
    "omitIcon\0omitIconSize\0clickImage\0"
    "shiftClickImage\0ensureClickImage\0"
    "clickBackColor\0showHanziBackColor\0"
    "showHanziWordColor\0showHanziFontColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Keyboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      18,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QColor, 0x00095103,
       2, QMetaType::Int, 0x00095103,
       3, QMetaType::QColor, 0x00095103,
       4, QMetaType::QColor, 0x00095103,
       5, QMetaType::QFont, 0x00095103,
       6, QMetaType::QColor, 0x00095103,
       7, QMetaType::QColor, 0x00095103,
       8, QMetaType::Int, 0x00095103,
       9, QMetaType::Int, 0x00095103,
      10, QMetaType::QIcon, 0x00095103,
      11, QMetaType::QSize, 0x00095103,
      12, QMetaType::QPixmap, 0x00095103,
      13, QMetaType::QPixmap, 0x00095103,
      14, QMetaType::QPixmap, 0x00095103,
      15, QMetaType::QColor, 0x00095103,
      16, QMetaType::QColor, 0x00095103,
      17, QMetaType::QColor, 0x00095103,
      18, QMetaType::QColor, 0x00095103,

       0        // eod
};

void Keyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        Keyboard *_t = static_cast<Keyboard *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->borderColor(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->borderWidth(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->fontColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->backColor(); break;
        case 4: *reinterpret_cast< QFont*>(_v) = _t->hanziFont(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->hanziFontColor(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->hanziBackColor(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->showLabelHeight(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->hanziPanelHeight(); break;
        case 9: *reinterpret_cast< QIcon*>(_v) = _t->omitIcon(); break;
        case 10: *reinterpret_cast< QSize*>(_v) = _t->omitIconSize(); break;
        case 11: *reinterpret_cast< QPixmap*>(_v) = _t->clickImage(); break;
        case 12: *reinterpret_cast< QPixmap*>(_v) = _t->shiftClickImage(); break;
        case 13: *reinterpret_cast< QPixmap*>(_v) = _t->ensureClickImage(); break;
        case 14: *reinterpret_cast< QColor*>(_v) = _t->clickBackColor(); break;
        case 15: *reinterpret_cast< QColor*>(_v) = _t->showHanziBackColor(); break;
        case 16: *reinterpret_cast< QColor*>(_v) = _t->showHanziWordColor(); break;
        case 17: *reinterpret_cast< QColor*>(_v) = _t->showHanziFontColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Keyboard *_t = static_cast<Keyboard *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBorderColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setFontColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setBackColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setHanziFont(*reinterpret_cast< QFont*>(_v)); break;
        case 5: _t->setHanziFontColor(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setHanziBackColor(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setShowLabelHeight(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setHanziPanelHeight(*reinterpret_cast< int*>(_v)); break;
        case 9: _t->setOmitIcon(*reinterpret_cast< QIcon*>(_v)); break;
        case 10: _t->setOmitIconSize(*reinterpret_cast< QSize*>(_v)); break;
        case 11: _t->setClickImage(*reinterpret_cast< QPixmap*>(_v)); break;
        case 12: _t->setShiftClickImage(*reinterpret_cast< QPixmap*>(_v)); break;
        case 13: _t->setEnsureClickImage(*reinterpret_cast< QPixmap*>(_v)); break;
        case 14: _t->setClickBackColor(*reinterpret_cast< QColor*>(_v)); break;
        case 15: _t->setShowHanziBackColor(*reinterpret_cast< QColor*>(_v)); break;
        case 16: _t->setShowHanziWordColor(*reinterpret_cast< QColor*>(_v)); break;
        case 17: _t->setShowHanziFontColor(*reinterpret_cast< QColor*>(_v)); break;
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

const QMetaObject Keyboard::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_Keyboard.data,
      qt_meta_data_Keyboard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Keyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Keyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Keyboard.stringdata0))
        return static_cast<void*>(this);
    return QStackedWidget::qt_metacast(_clname);
}

int Keyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 18;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
