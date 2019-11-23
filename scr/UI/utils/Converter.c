//
// Created by jonsk on 11/22/2019.
//
#include "Converter.h"
#include "../libraries/cJSON/cJSON.h"

int** convertStringToIntegerArray(char* data) {
    cJSON* array = cJSON_Parse(data);
    int rows = cJSON_GetArraySize(array);
    cJSON* first = cJSON_GetArrayItem(array, 0);
    int columns = cJSON_GetArraySize(first);
    int** newArray = (int **) malloc(sizeof(int *) * rows);
    for(int i = 0; i < rows; i++){
        newArray[i] = (int *) malloc(sizeof(int) * columns);
    }
    for(int i = 0; i < rows; i++){
        cJSON* current = cJSON_GetArrayItem(array, i);
        for(int j = 0; j < columns; j++){
            cJSON* numberJSON = cJSON_GetArrayItem(current, j);
            char* number = cJSON_Print(numberJSON);
            newArray[i][j] = (int) strtol(number, NULL, 0);
        }
    }
    return newArray;
}

char* convertIntegerArrayToString(int **array, int rows, int columns){
    cJSON* root = cJSON_CreateArray();
    for(int i = 0; i < rows; i++){
        cJSON* current = cJSON_CreateIntArray(array[i], columns);
        cJSON_AddItemToArray(root, current);
    }
    return cJSON_Print(root);
}

char* convertStringToCharArray(char* data){
    cJSON* array = cJSON_Parse(data);
    int rows = cJSON_GetArraySize(array);
    char* newData = malloc(sizeof(char) * rows);
    for(int i = 0; i < rows; i++){
        cJSON* current = cJSON_GetArrayItem(array, i);
        newData[i] = *cJSON_Print(cJSON_GetArrayItem(current, i));
    }
    return newData;
}