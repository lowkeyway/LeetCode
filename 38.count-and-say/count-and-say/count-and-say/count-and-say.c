#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

#define MAX_N 60
#define MAX_STR 512

char countSay[MAX_STR + 1] = { 0 };
char tempSay[MAX_STR + 1] = { 0 };

void loopFunc(int n)
{
    if (1 == n)  return;
    memset(tempSay, 0, MAX_STR + 1);
    uchar i = 0, tempIndex = 0;
    char curNumStr = countSay[0], numCount = 0;
    while (countSay[i] != '\0')
    {
        if (curNumStr == countSay[i])
        {
            numCount++;
            i++;
            continue;
        }
        tempSay[tempIndex++] = numCount + '0';
        tempSay[tempIndex++] = curNumStr;
        curNumStr = countSay[i];
        numCount = 1;
        i++;
    }

    tempSay[tempIndex++] = numCount + '0';
    tempSay[tempIndex++] = curNumStr;

    memcpy(countSay, tempSay, MAX_STR);
    memset(tempSay, 0, MAX_STR);
    loopFunc(n - 1);
}

char* countAndSay(int n) {
    if (0 >= n)  return NULL;
    char* ret = countSay;
    countSay[0] = '1';
    loopFunc(n);

    return ret;
}

int main(void)
{
    char* ret = NULL;
    ret = countAndSay(5);
    printf("%s\n", ret);
    return true;
}