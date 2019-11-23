//
// Created by jonsk on 11/20/2019.
//

#ifndef UI_NETPACKAGE_H
#define UI_NETPACKAGE_H

#include "../libraries/cJSON/cJSON.h"

/**
 * Converts the NetPackage to json
 * @param from who the package comes
 * @param command with server should follow
 * @param data to be send
 * @param type additional info
 * @return json String
 */
char* convertToJSON(char* from, char* command, char* data, char* type);

/**
 * Gets the attribute from
 * @param json to consult
 * @return attribute from
 */
char* getSenderFromJSON(char* json);

/**
 * Gets the command of the json
 * @param json to be consulted
 * @return json command
 */
char* getCommandFromJSON(char* json);

/**
 * Gets the data from the json
 * @param json to be consulted
 * @return json data
 */
char* getDataFromJSON(char* json);

/**
 * Gets the type from json
 * @param json to be consulted
 * @return json type
 */
char* getTypeFromJSON(char* json);


#endif //UI_NETPACKAGE_H
