//
// Created by Jon Gs on 11/21/2019.
//
#include "Connector.h"

char* addNewLineAtTheEnd(char* entry){
    int size = strlen(entry);
    char* newEntry = malloc(sizeof(char) * (size + 2));
    ZeroMemory(newEntry, (sizeof(char) * (size + 2)));
    int i;
    newEntry[0] = '\n';
    for(i = 0; i < size; i++){
        newEntry[i + 1] = entry[i];
    }
    newEntry[size] = '\n';
    printf("Turn into %s\n", newEntry);
    return newEntry;
}

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

char* getDataFromBuffer(char* buffer, int bytesReceived){
    char* data = malloc(bytesReceived * sizeof(char));
    ZeroMemory(data, bytesReceived);
    int i;
    for(i = 0; i < bytesReceived; i++){
        data[i] = buffer[i];
    }
    return data;
}

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
    /* cannot direclty use &size because of strict aliasing rules */
    return (WSAAddressToString((struct sockaddr *)&ss, sizeof(ss), NULL, dst, &s) == 0)?
           dst : NULL;
}

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
    printf("Sending %s\n", json);
    int sendResult = send(sock, json, strlen(json) + 1, 0);
    if(sendResult != SOCKET_ERROR){
        ZeroMemory(buf, BufferSize);
        bytesReceived = recv(sock, buf, BufferSize, 0);
        if(bytesReceived > 0){
            closesocket(sock);
            WSACleanup();
            char* response = getDataFromBuffer(buf, bytesReceived);
            printf("Got response: %s\n", response);
            return response;
        }
    }
    return "";
}
