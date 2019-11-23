//
// Created by Jon Gs on 11/21/2019.
//
#include "Connector.h"

/**
 * Adds the '\n' at the end of the entry
 * @param entry to be changed
 * @return modified entry
 */
char* addNewLineAtTheEnd(char* entry){
    int size = strlen(entry);
    char* newEntry = malloc(sizeof(char) * (size + 3));
    ZeroMemory(newEntry, (sizeof(char) * (size + 3)));
    int i;
    newEntry[0] = '\n';
    for(i = 0; i < size; i++){
        newEntry[i + 1] = entry[i];
    }
    newEntry[size] = '}';
    newEntry[size+1] = '\n';
    printf("Turn into %s\n", newEntry);
    return newEntry;
}

/**
 * Counts the lines in the json file
 * @param json file
 * @return number of lines
 */
int countNumberOfLines(char* json){
    int jsonLength = strlen(json);
    int lines = 0;
    int i;
    for(i = 0; i < jsonLength; i++){
        if(json[i] == '\n'){
            lines++;
        }
    }return lines;
}

/**
 * Converts from integer to char Array
 * @param number to convert
 * @return number converted to char;
 */
char* integerToCharArray(int number){
    int counter = 1;
    int copyNumber = number;
    while((copyNumber = copyNumber / 10) > 0){
        counter++;
    }counter++;
    char* numArray = malloc((counter) * sizeof(char));
    sprintf(numArray, "%i", number);
    return numArray;
}

/**
 * Attaches the number of lines to the beginning of the json
 * @param firstjson before modifications
 * @return modified json
 */
char* attackNumberOfLines(char* firstjson){
    int numberOfLines = countNumberOfLines(firstjson);
    char* lengthArray = integerToCharArray(numberOfLines);
    char* json = malloc(sizeof(char) * (strlen(lengthArray) + strlen(firstjson)));
    strcpy(json, lengthArray);
    printf("Now %s\n", json);
    strcat(json, firstjson);
    printf("Then %s\n", json);
    printf("Turn into %s\n", json);
    return json;
}

/**
 * Converts address from big Indian to Small Indian
 * @param af
 * @param src
 * @param dst
 * @return Modification
 */
int inet_pton(int af, const char *src, void *dst)
{
    struct sockaddr_storage ss;
    int size = sizeof(ss);
    char src_copy[INET6_ADDRSTRLEN+1];

    ZeroMemory(&ss, sizeof(ss));
    /* stupid non-const API */
    strncpy (src_copy, src, INET6_ADDRSTRLEN+1);
    src_copy[INET6_ADDRSTRLEN] = 0;

    if (WSAStringToAddress(src_copy, af, NULL, (struct sockaddr *)&ss, &size) == 0) {
        switch(af) {
            case AF_INET:
                *(struct in_addr *)dst = ((struct sockaddr_in *)&ss)->sin_addr;
                return 1;
            case AF_INET6:
                *(struct in6_addr *)dst = ((struct sockaddr_in6 *)&ss)->sin6_addr;
                return 1;
        }
    }
    return 0;
}


/**
 * Converts to Small indian to big indian
 * @param af
 * @param src
 * @param dst
 * @param size
 * @return Modification
 */
 /*
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size)
{
    struct sockaddr_storage ss;
    unsigned long s = size;

    ZeroMemory(&ss, sizeof(ss));
    ss.ss_family = af;

    switch(af) {
        case AF_INET:
            ((struct sockaddr_in *)&ss)->sin_addr = *(struct in_addr *)src;
            break;
        case AF_INET6:
            ((struct sockaddr_in6 *)&ss)->sin6_addr = *(struct in6_addr *)src;
            break;
        default:
            return NULL;
    }
    return (WSAAddressToString((struct sockaddr *)&ss, sizeof(ss), NULL, dst, &s) == 0)?
           dst : NULL;
}*/

char* sendRequest(char* id, char* command, char* data, char* type) {
    //Initializing WinSock
    WSADATA wsaData;
    WORD ver = MAKEWORD(2, 2);
    int wsResult = WSAStartup(ver, &wsaData);
    if (wsResult != 0) {
        return "";
    }

    //Creating the socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        WSACleanup();
        return "";
    }

    //Fill hint structure
    struct sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(PORT);
    inet_pton(AF_INET, HOSTIP, &hint.sin_addr);

    //Connecting to Server
    int connectionResult = connect(sock, (struct sockaddr*)&hint, sizeof(hint));
    if(connectionResult == SOCKET_ERROR){
        closesocket(sock);
        return "";
    }

    //Sending and receiving data
    char buf[BufferSize];
    int bytesReceived;
    char* firstJson = convertToJSON(id, command, data, type);
    char* preJson = addNewLineAtTheEnd(firstJson);
    char* json = attackNumberOfLines(preJson);
    printf("Sending %s\n", firstJson);
    int sendResult = send(sock, json, strlen(json) + 1, 0);
    if(sendResult != SOCKET_ERROR){
        ZeroMemory(buf, BufferSize);
        bytesReceived = recv(sock, buf, BufferSize, 0);
        if(bytesReceived > 0){
            closesocket(sock);
            WSACleanup();
            //char* response = getDataFromBuffer(buf, bytesReceived);
            printf("Got response: %s\n", buf);
            char* buff = malloc(sizeof(char) * strlen(buf));
            strcpy(buff,buf);
            return buff;
        }
    }
    return "";
}

int** update(char* id){
    char* json = sendRequest(id, "getUpdate", "None", "None");
    char* data = getDataFromJSON(json);
    int** update = convertStringToIntegerArray(data);
    return update;
}

void sendPlayerMovement(char* id, int** players, int rows, int columns){
    int** newData = (int**) malloc(sizeof(int*) * rows);
    for(int i = 0; i < 2; i++){
        newData[i] = (int*) malloc(sizeof(int) * columns);
    }
    for(int i = 0; i < rows; i++){
        int* current = malloc(sizeof(int) * columns);
        for(int j = 0; j < columns; j++){
            current[j] = players[i][j];
        }
        newData[i] = current;
    }
    char* data = convertIntegerArrayToString(newData, rows, columns);
    sendRequest(id, "updatePlayers", data, "NONE");
}

char* getGameOver(char* id){
    char* response = sendRequest(id, "gameover", "NONE", "NONE");
    char* scores = getDataFromJSON(response);
    char* newScores = convertStringToCharArray(scores);
}

void sendHit(char* gameID, int playerID, int enemyID){
    int* array = malloc(sizeof(int) * 2);
    char* arrayString = cJSON_Print(cJSON_CreateIntArray(array, 2));
    sendRequest(gameID, "HIT", arrayString, "NONE");
}

char* createGameSession(int enemies, int enemieID[], int rows){
    cJSON* root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "enemies", cJSON_CreateString(integerToCharArray(enemies)));
    cJSON* array = cJSON_CreateIntArray(enemieID, rows);
    cJSON_AddItemToObject(root, "enemiesID", array);
    char* response = sendRequest("NONE", "CREATE", cJSON_Print(root), "NONE");
    char* data = getDataFromJSON(response);
    return data;
}
