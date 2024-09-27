add_library(WeatherPlugin MODULE
	weatherplugin.h weatherplugin.cpp
	WeatherPluginInterface.h)

qt_add_qml_module(WeatherPlugin
	URI WeatherPlugin
	NO_PLUGIN
	SOURCES WeatherPlugin.cpp WeatherPluginInterface.h
	SOURCES WeatherPluginInterface.cpp
)

target_link_libraries(WeatherPlugin PUBLIC Qt6::Core)

set_target_properties(WeatherPlugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugin
)
