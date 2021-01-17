#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LeetCodeBox.h"

void swipe(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

void trunAroundArray(int* nums, int size)
{
    uint i = 0;
    int temp;
    for (i = 0; i < size / 2; i++)
    {
        swipe(&nums[i], &nums[size - i - 1]);
    }
    return;
}

void dumpArray(int* nums, int size)
{
    uint i = 0;
    printf("[ ");
    for (i = 0; i < size; i++)
    {
        printf("%4d ", nums[i]);
    }
    printf("]\n");
}

int main(void)
{
    int nums[] = { 1, 2, 3, 4};
    int numsSize = ARRAY_SIZE(nums);
    dumpArray(nums, numsSize);
    trunAroundArray(nums, numsSize);
    dumpArray(nums, numsSize);
    return true;
}