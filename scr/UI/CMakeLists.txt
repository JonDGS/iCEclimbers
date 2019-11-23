cmake_minimum_required(VERSION 3.13)
project(UI C)

set(CMAKE_C_STANDARD 11)

add_executable(UI Networking/NetPackage.c Networking/NetPackage.h libraries/cJSON/cJSON.c libraries/cJSON/cJSON.h Networking/Connector.h Networking/Connector.c utils/Converter.h utils/Converter.c gui.c)
target_link_libraries(UI wsock32 ws2_32)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

TARGET_LINK_LIBRARIES(UI ${GTK3_LIBRARIES})