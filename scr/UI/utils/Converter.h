//
// Created by jonsk on 11/22/2019.
//

#ifndef UI_CONVERTER_H
#define UI_CONVERTER_H

#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

/**
 * Converts String to an Integer Array
 * @param data to be converted
 * @return Integer array of the data
 */
int** convertStringToIntegerArray(char* data);

/**
 * Converts from Integer Array to String
 * @param array to be converted
 * @param rows in the array
 * @param columns in the array
 * @return String of the array
 */
char* convertIntegerArrayToString(int** array, int rows, int columns);

char* convertStringToCharArray(char* data);

#endif //UI_CONVERTER_H
