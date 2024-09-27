#include "weatherplugin.h"

WeatherPlugin::WeatherPlugin() : m_manager(new QNetworkAccessManager(this))
{
    QObject::connect(m_manager, &QNetworkAccessManager::finished, this, &WeatherPlugin::onDataChanged);
}

void WeatherPlugin::fetchApi(const QString location)
{
    QString apiKey = "";
    QString url = QString("http://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg(location, apiKey);

    QNetworkRequest request((QUrl(url)));
    m_manager->get(request);
}

QString WeatherPlugin::message()
{
    return m_message;
}

void WeatherPlugin::setMessage(const QString message)
{
    if (m_message != message) {
        m_message = message;
        emit messageChanged();
    }
}

void WeatherPlugin::registerPlugin(QQmlEngine *engine)
{
    if(engine){
        engine->addImportPath(":/WeatherPlugin");
    }
}

void WeatherPlugin::onDataChanged(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();  // Read the response data
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);  // Parse it as JSON
        qDebug() << jsonDoc;

        if (jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();
            QJsonObject mainObj = jsonObj.value("main").toObject();
            double temperature = mainObj.value("temp").toDouble() - 273.15;  // Convert from Kelvin to Celsius

            QJsonArray weatherArray = jsonObj.value("weather").toArray();  // Parse the "weather" array
            QString description = weatherArray[0].toObject().value("description").toString();

            // Format the fetched weather data
            m_message = QString("Temperature: %1°C\nDescription: %2").arg(temperature).arg(description);
            emit messageChanged();  // Notify QML that the data has been updated
        }
    } else {
        m_message = "Error fetching weather data";  // Handle errors
        emit messageChanged();
    }

    reply->deleteLater();  // Clean up the reply object
}


