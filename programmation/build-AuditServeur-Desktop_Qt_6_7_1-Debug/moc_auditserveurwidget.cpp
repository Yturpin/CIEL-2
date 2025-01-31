/****************************************************************************
** Meta object code from reading C++ file 'auditserveurwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AuditServeur/auditserveurwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'auditserveurwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSAuditServeurWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSAuditServeurWidgetENDCLASS = QtMocHelpers::stringData(
    "AuditServeurWidget",
    "on_pushButtonLancementServeur_clicked",
    "",
    "onQTcpServerNewConnection",
    "onQTcpServerAcceptError",
    "onQTcpSocketConnected",
    "onQTcpSocketDisconnected",
    "onQTcpSocketReadyRead",
    "onQTcpSocketErrorOccured",
    "QAbstractSocket::SocketError",
    "_socketError",
    "onQTcpSocketStateChanged",
    "QAbstractSocket::SocketState",
    "_socketState",
    "onQTcpSocketHostFound",
    "onQTcpSocketBytesWritten",
    "_bytes",
    "onQTcpSocketAboutToClose"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAuditServeurWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    1,   86,    2, 0x08,    7 /* Private */,
      11,    1,   89,    2, 0x08,    9 /* Private */,
      14,    0,   92,    2, 0x08,   11 /* Private */,
      15,    1,   93,    2, 0x08,   12 /* Private */,
      17,    0,   96,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   16,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AuditServeurWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSAuditServeurWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAuditServeurWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAuditServeurWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AuditServeurWidget, std::true_type>,
        // method 'on_pushButtonLancementServeur_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpServerNewConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpServerAcceptError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocketConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocketDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocketReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocketErrorOccured'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QAbstractSocket::SocketError, std::false_type>,
        // method 'onQTcpSocketStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QAbstractSocket::SocketState, std::false_type>,
        // method 'onQTcpSocketHostFound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocketBytesWritten'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qint64, std::false_type>,
        // method 'onQTcpSocketAboutToClose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AuditServeurWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AuditServeurWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButtonLancementServeur_clicked(); break;
        case 1: _t->onQTcpServerNewConnection(); break;
        case 2: _t->onQTcpServerAcceptError(); break;
        case 3: _t->onQTcpSocketConnected(); break;
        case 4: _t->onQTcpSocketDisconnected(); break;
        case 5: _t->onQTcpSocketReadyRead(); break;
        case 6: _t->onQTcpSocketErrorOccured((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 7: _t->onQTcpSocketStateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 8: _t->onQTcpSocketHostFound(); break;
        case 9: _t->onQTcpSocketBytesWritten((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 10: _t->onQTcpSocketAboutToClose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

const QMetaObject *AuditServeurWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuditServeurWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAuditServeurWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AuditServeurWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
