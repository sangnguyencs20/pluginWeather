#pragma once
#include "WeatherPluginInterface.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QQmlEngine>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class WeatherPlugin : public PluginBase {
    Q_OBJECT

    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged FINAL)
    Q_PLUGIN_METADATA(IID "WeatherPlugin")
    Q_INTERFACES(PluginBase)

    QML_ELEMENT



public:
    explicit WeatherPlugin();

    QString message();
    void setMessage(const QString message);
    void registerPlugin(QQmlEngine* engine) final;

public slots:
    void fetchApi(const QString location);
    void onDataChanged(QNetworkReply *reply);

signals:
    void messageChanged();

private:
    QNetworkAccessManager* m_manager;
    QString m_message;
};
