#ifndef _LEETCODE_BOX_
#define _LEETCODE_BOX_

#include <stdio.h>

#define ARRAY_SIZE(X)	sizeof(X) / sizeof(X[0])

#define ABS(X)          (X) > 0 ? (X) : (-X)
#define MIN(a, b)       (a) < (b) ? (a) : (b)
#define MAX(a, b)       (a) > (b) ? (a) : (b)
#define ABS_MIN(a, b)   (ABS(a)) < (ABS(b)) ? (a) : (b)
#define ABS_MAX(a, b)   (ABS(a)) > (ABS(b)) ? (a) : (b)

typedef unsigned int	uint;
typedef unsigned char	uchar;
typedef unsigned long	ulong;
typedef unsigned long long ull;


void dumpIntArray(int* nums, int numsSize)
{
    uint i = 0;
    printf("[ ");
    for (i = 0; i < numsSize; i++)
    {
        printf("%4d ", nums[i]);
    }
    printf("]\n");
}

void dumpStrArray(char** nums, int numsSize)
{
    uint i = 0;
    printf("[ ");
    for (i = 0; i < numsSize; i++)
    {
        printf("\"%s\",  ", nums[i]);
    }
    printf("]\n");
}

void dumpCharArray(char* nums, int numsSize)
{
    uint i = 0;
    printf("[ ");
    for (i = 0; i < numsSize; i++)
    {
        printf("\'%c\'  ", nums[i]);
    }
    printf("]\n");
}

#endif // !_LEETCODE_BOX_
#pragma once
