//
// Created by Jon Gs on 11/21/2019.
//

#ifndef UI_CONNECTOR_H
#define UI_CONNECTOR_H

#include <stdio.h>
#include <ws2tcpip.h>
#include <string.h>
#include "NetPackage.h"
#pragma comment(lib, "ws2_32.lib")

#define HOSTIP "127.0.0.1"
#define BufferMultiplier 1
#define BufferSize (512 * BufferMultiplier)
#define PORT 50000

char* sendRequest(char* id, char* command, char* data, char* type);






#endif //UI_CONNECTOR_H
