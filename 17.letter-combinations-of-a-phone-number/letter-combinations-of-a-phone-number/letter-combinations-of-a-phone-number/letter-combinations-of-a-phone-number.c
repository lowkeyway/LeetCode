#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

char* array;
char** arrays;
uchar arraySize     = 1;
uchar arraysSize    = 1;
uchar arrayIndex    = 0;
uchar arraysIndex   = 0;
uchar digSize       = 1;

char* mapTable[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "xyz" };

static void callbackFunc(uchar *digits, uchar index)
{
    uchar i = 0;
    if (index == digSize)
    {
        char* temp = malloc(arraySize); memset(temp, 0, arraySize);
        memcpy(temp, array, arraySize - 1);
        arrays[arraysIndex++] = temp;
    }
    else
    {
        char c = digits[index];
        uchar mapIndex = c - '0';
        char* str = mapTable[mapIndex];
        uchar strSize = strlen(str);
        for (i = 0; i < strSize; i++)
        {
            array[index] = str[i];
            callbackFunc(digits, index+1);
        }
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    uchar i = 0;
    char** ret;
    digSize = strlen(digits);
    
    arraySize = digSize + 1;
    for (i = 0; i < digSize; i++) arraysSize *= 4;

    arrays = malloc(sizeof(char*) * arraysSize); memset(arrays, 0, sizeof(char*) * arraysSize);
    array = malloc(sizeof(char) * arraySize); memset(array, 0, sizeof(char) * arraySize);

    callbackFunc(digits, 0);


    ret = arrays;
    *returnSize = arraysIndex;

    return ret;
}

int main(void)
{
    char** ret;
    char* digits = "234";
    int returnSize = 0;
    int i = 0;

    ret = letterCombinations(digits, &returnSize);

    for (; i < returnSize; i++)
    {
        printf(" \"%s\" ", ret[i]);
    }
    
    return 0;
}