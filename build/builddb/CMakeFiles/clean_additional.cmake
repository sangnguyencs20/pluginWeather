# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appWeathering_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appWeathering_autogen.dir\\ParseCache.txt"
  "WeatherPlugin\\CMakeFiles\\WeatherPlugin_autogen.dir\\AutogenUsed.txt"
  "WeatherPlugin\\CMakeFiles\\WeatherPlugin_autogen.dir\\ParseCache.txt"
  "WeatherPlugin\\WeatherPlugin_autogen"
  "appWeathering_autogen"
  )
endif()
