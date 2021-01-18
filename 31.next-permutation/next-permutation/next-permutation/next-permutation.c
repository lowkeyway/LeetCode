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

void nextPermutation(int* nums, int numsSize) {
    uint i = 0;
    int k = -1, l = -1;

    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] < nums[i + 1]) k = i;
    }
    printf("k = %d\n", k);
    if (-1 == k)
    {
        trunAroundArray(nums, numsSize);
        return;
    }

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > nums[k]) l = i;
    }
    printf("l = %d\n", l);

    swipe(&nums[k], &nums[l]);
    trunAroundArray(&nums[k+1], numsSize - k - 1);
}

int main(void)
{
    int nums[] = { 1, 2, 7, 4, 3, 1};
    int numsSize = ARRAY_SIZE(nums);
    dumpArray(nums, numsSize);
    nextPermutation(nums, numsSize);
    dumpArray(nums, numsSize);
    return true;
}