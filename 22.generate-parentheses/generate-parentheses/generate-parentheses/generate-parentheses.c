#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

#define BRA_NUM 2

char** rets;
char* ret;

bool isValid(char* s, uint sSize)
{
    uint i = 0;
    uint left = 0, right = 0;
    if (0 != sSize % 2) return false;

    for (i = 0; i < sSize; i++)
    {
        if ('(' == s[i]) left++;
        if (')' == s[i]) right++;
        if (left < right) return false;
    }

    if (left != right)   return false;

    return true;
}

void callBack(char *ret, int* retIndex, uint size, char **rets, int* returnIndex)
{
    if (size == strlen(ret))
    {
        if (isValid(ret, size))
        {
            char* temp = malloc(size + 1);
            memset(temp, 0, size + 1);
            memcpy(temp, ret, size);
            rets[(*returnIndex)++] = temp;
        }
        return;
    }
    ret[(*retIndex)++] = '(';
    callBack(ret, retIndex, size, rets, returnIndex);
    ret[*retIndex] = '\0';
    (*retIndex)--;
    ret[(*retIndex)++] = ')';
    callBack(ret, retIndex, size, rets, returnIndex);
    ret[*retIndex] = '\0';
    (*retIndex)--;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    int retIndex = 0;
    callBack(ret, &retIndex, BRA_NUM * 2, rets, returnSize);
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

    valid = isValid(s, strlen(s));
    printf("valid = %d\n", valid);

    return true;
}