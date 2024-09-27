/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <weatherplugin.h>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_WeatherPlugin()
{
    qmlRegisterModule("WeatherPlugin", 254, 0);
    QMetaType::fromType<PluginBase *>().id();
    qmlRegisterTypesAndRevisions<WeatherPlugin>("WeatherPlugin", 254);
    qmlRegisterModule("WeatherPlugin", 254, 254);
}

static const QQmlModuleRegistration weatherPluginRegistration("WeatherPlugin", qml_register_types_WeatherPlugin);
