project(helloworld)

cmake_minimum_required(VERSION 2.8)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(AMXConfig)
include(AddSAMPPlugin)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/lib
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/sampsdk
)

add_definitions(-DSAMPGDK_AMALGAMATION)

add_samp_plugin(helloworld
  lib/sampsdk/amxplugin.cpp
  src/main.c
  src/main.h
  src/main.def
  lib/sampgdk/sampgdk.c
  lib/sampgdk/sampgdk.h
)