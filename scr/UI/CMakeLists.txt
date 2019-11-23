cmake_minimum_required(VERSION 3.13)
project(UI C)

set(CMAKE_C_STANDARD 11)

add_executable(UI main.c Networking/NetPackage.c Networking/NetPackage.h libraries/cJSON/cJSON.c libraries/cJSON/cJSON.h Networking/Connector.h Networking/Connector.c utils/Converter.h utils/Converter.c)
target_link_libraries(UI wsock32 ws2_32)