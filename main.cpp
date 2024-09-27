#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <WeatherPluginInterface.h>
#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QString pluginPath = QCoreApplication::applicationDirPath() + "/plugin/WeatherPlugin.dll";

    QPluginLoader plugin(pluginPath);

    if (plugin.load()){
        PluginBase* pluginInstance = qobject_cast<PluginBase*>(plugin.instance());
        if (pluginInstance){
            pluginInstance->registerPlugin(&engine);
        }else{
            qFatal()<< "Cannot cast to WeatherPlugin";
        }
    }else{
        qFatal() << "Cannot load plugin " << plugin.errorString();
    }

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Weathering", "Main");

    return app.exec();
}
