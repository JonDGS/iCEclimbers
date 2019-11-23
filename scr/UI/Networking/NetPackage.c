//
// Created by jonsk on 11/20/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "NetPackage.h"

char* convertToJSON(char* from, char* command, char* data, char* type){
    cJSON* root = cJSON_CreateObject();
    cJSON* netpackRoot = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "NetPackage", netpackRoot);
    cJSON_AddItemToObject(netpackRoot, "from", cJSON_CreateString(from));
    cJSON_AddItemToObject(netpackRoot, "command", cJSON_CreateString(command));
    cJSON_AddItemToObject(netpackRoot, "data", cJSON_CreateString(data));
    cJSON_AddItemToObject(netpackRoot, "type", cJSON_CreateString(type));

    return cJSON_Print(root);
}

char* getSenderFromJSON(char* json){
    cJSON* root = cJSON_Parse(json);
    cJSON* NetPackage = cJSON_GetObjectItem(root, "NetPackage");
    char* from = cJSON_GetObjectItem(NetPackage, "from")->valuestring;
    return from;
}

char* getCommandFromJSON(char* json){
    cJSON* root = cJSON_Parse(json);
    cJSON* NetPackage = cJSON_GetObjectItem(root, "NetPackage");
    char* command = cJSON_GetObjectItem(NetPackage, "command")->valuestring;
    return command;
}

char* getDataFromJSON(char* json){
    cJSON* root = cJSON_Parse(json);
    cJSON* NetPackage = cJSON_GetObjectItem(root, "NetPackage");
    char* data = cJSON_GetObjectItem(NetPackage, "data")->valuestring;
    return data;
}

char* getTypeFromJSON(char* json){
    cJSON* root = cJSON_Parse(json);
    cJSON* NetPackage = cJSON_GetObjectItem(root, "NetPackage");
    char* type = cJSON_GetObjectItem(NetPackage, "type")->valuestring;
    return type;
}


