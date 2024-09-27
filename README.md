# Weather Plugin using QNetworkAccessManager in Qt

## Overview

This project demonstrates how to create a dynamic link library (DLL) in Qt that functions as a weather plugin. The plugin fetches weather data from an external API using `QNetworkAccessManager`. This data is then made available for use in a QML application through the plugin interface.

## Requirements

- **Qt 6.x** (or later)
- **OpenWeatherMap API Key** (for fetching weather data)
- Basic knowledge of C++ and QML in Qt
- **CMake** for building the project

## Project Structure
```
│   .gitignore
│   CMakeLists.txt
│   main.cpp
│   Main.qml
│   qmldir
│
└───WeatherPlugin
        CMakeLists.txt
        weatherplugin.cpp
        weatherplugin.h
        WeatherPluginInterface.cpp
        WeatherPluginInterface.h
```

### Plugin Interface

Define a base plugin interface in `WeatherPluginInterface.h` that all plugins should implement. This ensures consistency for registering QML types and exposes a way for the plugin to interact with the QML engine.

### Plugin Implementation

In `WeatherPlugin.h` and `WeatherPlugin.cpp`, implement the weather plugin class. This class will use `QNetworkAccessManager` to make HTTP requests to the OpenWeatherMap API and emit the weather data once it is fetched. Be sure to include methods for registering the plugin's QML types and handling the network reply.

### Main Application

In `main.cpp`, use `QPluginLoader` to dynamically load the plugin. If successfully loaded, the plugin will be used to register QML types and allow fetching of weather data in the QML interface.

### QML

Create a `Main.qml` file that will interact with the plugin. It should include input for a location, a button to fetch the weather, and a text area to display the results.

### CMake Configuration

The following `CMakeLists.txt` files are used to configure the build process.

#### `plugin/CMakeLists.txt`

This file handles building the weather plugin as a shared library.

```cmake
cmake_minimum_required(VERSION 3.14)

project(WeatherPlugin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Network Qml)

add_library(WeatherPlugin SHARED
    WeatherPlugin.cpp
)

target_link_libraries(WeatherPlugin
    Qt6::Core
    Qt6::Network
    Qt6::Qml
)

qt_add_qml_module(WeatherPlugin
    URI WeatherPlugin
    VERSION 1.0
    QML_FILES
    qml/Main.qml
)

set_target_properties(WeatherPlugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugin
)
```
### Main Application CMakeLists.txt
This file configures the main application that will load and use the weather plugin.
```
cmake_minimum_required(VERSION 3.14)

project(WeatherApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Qml)

add_executable(WeatherApp
    main.cpp
    resources.qrc
)

target_link_libraries(WeatherApp
    Qt6::Core
    Qt6::Quick
    Qt6::Qml
)

qt_add_resources(WeatherApp "resources"
    PREFIX /
    FILES
    Main.qml
)

install(TARGETS WeatherApp
    RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin
)
```
