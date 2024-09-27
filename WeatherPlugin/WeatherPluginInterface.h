#pragma once

#include <QQmlEngine>
#include <QObject>

class PluginBase : public QObject {
    Q_OBJECT

public:
    ~PluginBase() = default;

    virtual void registerPlugin(QQmlEngine *) = 0;
};

Q_DECLARE_INTERFACE(PluginBase, "PluginBase");
