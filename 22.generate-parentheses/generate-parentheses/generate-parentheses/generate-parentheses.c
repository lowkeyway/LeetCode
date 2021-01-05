#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

#define BRA_NUM 3

char** rets;
char* ret;

void callBack(char *ret, int* retIndex, uint size, char **rets, int* returnIndex, int left, int right)
{
    if (size == strlen(ret))
    {
        char* temp = malloc(size + 1);
        memset(temp, 0, size + 1);
        memcpy(temp, ret, size);
        rets[(*returnIndex)++] = temp;
        return;
    }

    if (left < size / 2)
    {
        ret[(*retIndex)++] = '(';
        callBack(ret, retIndex, size, rets, returnIndex, left+1, right);
        ret[*retIndex] = '\0';
        (*retIndex)--;
    }

    if (left > right)
    {
        ret[(*retIndex)++] = ')';
        callBack(ret, retIndex, size, rets, returnIndex, left, right+1);
        ret[*retIndex] = '\0';
        (*retIndex)--;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    int retIndex = 0, left = 0, right = 0;
    callBack(ret, &retIndex, n * 2, rets, returnSize, left, right);
    return rets;
}

uint f(x)
{
    return (1 >= x) ? (x) :  x * f(x - 1);
}

int main(void)
{
    uint retsNum = 0, retNum = 0, returnSize = 0;
    uint i = 0, j = 0;
    char *s = "(()())";
    bool valid = 0;
        

    retsNum = f(BRA_NUM);
    retNum = BRA_NUM * 2 + 1;

    rets = malloc(sizeof(char*) * retsNum);
    memset(rets, 0, sizeof(char*) * retsNum);
    ret = malloc(sizeof(char) * retNum);
    memset(ret, 0, sizeof(char) * retNum);

    rets = generateParenthesis(BRA_NUM, &returnSize);

    for (i = 0; i < returnSize; i++)
    {
        printf("[%s]\n", rets[i]);
    }

    return true;
}