#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

bool comFunc(const void* a, const void* b)
{
    return (*(int*)a) > (*(int*)b);
}

void dumpNums(int* nums, int numsSize)
{
    int i = 0;
    printf("nums[] = ");
    for (i = 0; i < numsSize; i++)
    {
        printf("%4d ", nums[i]);
    }
    printf("\n");
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** rets = NULL; uchar retsIndex = 0;
    int* ret = NULL;
    uchar curL, curR, left, right;
    int temp = 0;

    if (NULL == nums || 4 > numsSize)
    {
        printf("Something wrong!\n");
        return rets;
    }

    rets = malloc(sizeof(int*) * numsSize);
    qsort(nums, numsSize, sizeof(int), comFunc);
    dumpNums(nums, numsSize);

    for (curL = 0; curL < numsSize - 3; curL++)
    {
        if (curL > 0 && nums[curL] == nums[curL - 1])    continue;
        for (curR = curL + 1; curR < numsSize - 2; curR++)
        {
            if ((curR > curL + 1) && (nums[curR] == nums[curR - 1]))    continue;
            temp = target - nums[curL] - nums[curR];
            left = curR + 1;
            right = numsSize - 1;
            while (left < right)
            {
                if (temp == (nums[left] + nums[right]))
                {
                    ret = malloc(sizeof(int) * 4);
                    ret[0] = nums[curL];
                    ret[1] = nums[curR];
                    ret[2] = nums[left];
                    ret[3] = nums[right];

                    rets[retsIndex++] = ret;

                    while (left < right && nums[left] == nums[left + 1])   left++;
                    while (left < right && nums[right] == nums[right - 1])   right--;
                    left++; right++;
                }
                else if (temp > (nums[left] + nums[right]))
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    *returnSize = retsIndex;

    return rets;
}

int main(void)
{
    int** ret;
    int target = 0;
    int nums[] = { 1, 0, -1, 0, -2, 2 };
    //int nums[] = { 0, 0, 0, 0, 0, 0 };
    int returnSize;
    int** returnColumnSizes;
    int i = 0;

    ret = fourSum(nums, ARRAY_SIZE(nums), target, &returnSize, returnColumnSizes);
    printf("returnSize = %d\n", returnSize);
    if (NULL != ret)
    {
        for (i = 0; i < returnSize; i++)
        {
            printf("ret[%d] = [%4d %4d %4d %4d] \n", i, ret[i][0], ret[i][1], ret[i][2], ret[i][3]);
        }
    }
    return 1;
}