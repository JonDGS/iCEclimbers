//
// Created by jonsk on 11/20/2019.
//

#ifndef UI_NETPACKAGE_H
#define UI_NETPACKAGE_H

#include "../libraries/cJSON/cJSON.h"

char* convertToJSON(char* from, char* command, char* data, char* type);
char* getSenderFromJSON(char* json);
char* getCommandFromJSON(char* json);
char* getDataFromJSON(char* json);
char* getTypeFromJSON(char* json);


#endif //UI_NETPACKAGE_H
