/****************************************************************************
** Meta object code from reading C++ file 'settingspage.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../settingspage.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingspage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN12SettingsPageE_t {};
} // unnamed namespace

template <> constexpr inline auto SettingsPage::qt_create_metaobjectdata<qt_meta_tag_ZN12SettingsPageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SettingsPage",
        "volumeChanged",
        "",
        "value",
        "ChinesefontChanged",
        "font",
        "EnglishfontChanged",
        "backToHome",
        "onVolumeSliderMoved",
        "onChineseFontComboBoxChanged",
        "index",
        "onEnglishFontComboBoxChanged",
        "onMuteButtonClicked",
        "checked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'volumeChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'ChinesefontChanged'
        QtMocHelpers::SignalData<void(const QFont &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QFont, 5 },
        }}),
        // Signal 'EnglishfontChanged'
        QtMocHelpers::SignalData<void(const QFont &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QFont, 5 },
        }}),
        // Signal 'backToHome'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onVolumeSliderMoved'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'onChineseFontComboBoxChanged'
        QtMocHelpers::SlotData<void(int)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'onEnglishFontComboBoxChanged'
        QtMocHelpers::SlotData<void(int)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'onMuteButtonClicked'
        QtMocHelpers::SlotData<void(bool)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 13 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SettingsPage, qt_meta_tag_ZN12SettingsPageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SettingsPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12SettingsPageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12SettingsPageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12SettingsPageE_t>.metaTypes,
    nullptr
} };

void SettingsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SettingsPage *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->volumeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->ChinesefontChanged((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 2: _t->EnglishfontChanged((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 3: _t->backToHome(); break;
        case 4: _t->onVolumeSliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onChineseFontComboBoxChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->onEnglishFontComboBoxChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->onMuteButtonClicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SettingsPage::*)(int )>(_a, &SettingsPage::volumeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SettingsPage::*)(const QFont & )>(_a, &SettingsPage::ChinesefontChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SettingsPage::*)(const QFont & )>(_a, &SettingsPage::EnglishfontChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SettingsPage::*)()>(_a, &SettingsPage::backToHome, 3))
            return;
    }
}

const QMetaObject *SettingsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12SettingsPageE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SettingsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SettingsPage::volumeChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SettingsPage::ChinesefontChanged(const QFont & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void SettingsPage::EnglishfontChanged(const QFont & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void SettingsPage::backToHome()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
