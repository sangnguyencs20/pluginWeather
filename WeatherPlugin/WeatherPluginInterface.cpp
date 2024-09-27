#include "WeatherPluginInterface.h"

void PluginBase::registerPlugin(QQmlEngine* engine){
    if(engine){
        engine->addImportPath(":/PluginBase");
    }
}
