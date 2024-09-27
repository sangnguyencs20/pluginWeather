import QtQuick 2.15
import QtQuick.Controls 2.15
import WeatherPlugin

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Weather App"

    WeatherPlugin {
        id: weatherPlugin
    }

    Rectangle {
        anchors.fill: parent
        color: "lightblue"

        Column {
            anchors.centerIn: parent
            spacing: 20

            Text {
                text: "Welcome to the Weather App!"
                font.pixelSize: 24
            }

			TextField {
				id: name
			}

            Button {
                text: "Fetch Weather"
                onClicked: weatherPlugin.fetchApi(name.text)
            }

            Text {
                text: weatherPlugin.message
                font.pixelSize: 18
            }
        }
    }
}
