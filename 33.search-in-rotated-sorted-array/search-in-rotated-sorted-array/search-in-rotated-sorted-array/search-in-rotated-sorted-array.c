#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

int search(int* nums, int numsSize, int target) {
    int ret = -1;

    if (0 == numsSize) return ret;
    if (1 == numsSize)   return nums[0] == target ? 0 : -1;

    uint l = 0, r = numsSize - 1, middle = 0;

    while (l < r)
    {
        middle = (l + r) / 2;
        if (target == nums[middle]) return 0;
        if (target == nums[l]) return 0;
        if (target == nums[r]) return 0;

        if (nums[l] < nums[middle])
        {
            if (target > nums[l] && target < nums[middle])
            {
                r = middle;
            }
            else
            {
                l = middle + 1;
            }
        }
        else
        {
            if (target > nums[middle + 1] && target < nums[r])
            {
                l = middle + 1;
            }
            else
            {
                r = middle;
            }
        }
    }

    return ret;
}

void dumpArray(int* nums, int numsSize)
{
    uint i = 0;
    printf("[ ");
    for (i = 0; i < numsSize; i++)
    {
        printf("%4d ", nums[i]);
    }
    printf("]\n");
}

int main(void)
{
    int ret = -2;
    int nums[] = { 4, 5, 6, 7, 0, 1, 2 };
    int numsSize = ARRAY_SIZE(nums);
    dumpArray(nums, numsSize);

    ret = search(nums, numsSize, 0);
    printf("ret = %d\n", ret);

    return true;
}