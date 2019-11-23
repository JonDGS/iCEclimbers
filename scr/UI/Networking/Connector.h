//
// Created by Jon Gs on 11/21/2019.
//

#ifndef UI_CONNECTOR_H
#define UI_CONNECTOR_H

#include <stdio.h>
#include <ws2tcpip.h>
#include <string.h>
#include "NetPackage.h"
#include "../utils/Converter.h"
#pragma comment(lib, "ws2_32.lib")

#define HOSTIP "127.0.0.1"
#define BufferMultiplier 1
#define BufferSize (512 * BufferMultiplier)
#define PORT 50000

/**
 * Sends a request to the server based on the following criteria
 * @param id of the game instance in the Server
 * @param command of what to do with the info
 * @param data to be send
 * @param type additional info
 * @return server response
 */
char* sendRequest(char* id, char* command, char* data, char* type);

/**
 * Request an update from the server
 * @param id of the game instance in the Server
 * @return the update
 */
int** update(char* id);

/**
 * Sends the movement of the players to the Server
 * @param id of the game instance in the Server
 * @param players coordinates
 * @param rows of the players array
 * @param columns of the players array
 */
void sendPlayerMovement(char* id, int** players, int rows, int columns);


/**
 * Get the game over results from the server
 * @param id of the game instance in the server
 * @return char array of scores;
 */
char* getGameOver(char* id);

/**
 * Creates a game session on the server
 * @param enemies amount
 * @param enemieID codes
 * @param rows enemieID
 * @return gameID
 */
char* createGameSession(int enemies, int enemieID[], int rows);

/**
 * Send damage done to the player to the Server
 * @param playerID
 * @param enemyID
 */
/**
 * Sends a hit from one player to an obstacule
 * @param gameID of the game in the Server
 * @param playerID 
 * @param enemyID
 */
void sendHit(char* gameID, int playerID, int enemyID);


#endif //UI_CONNECTOR_H
