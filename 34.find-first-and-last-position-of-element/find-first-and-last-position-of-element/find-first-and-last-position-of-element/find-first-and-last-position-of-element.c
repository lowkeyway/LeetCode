#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LeetCodeBox.h"
#include "LeetCodeSearch.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int leftIndex = -1, rightIndex = -1;
    int* ret = malloc(sizeof(int) * 2);
    memset(ret, -1, sizeof(int) * 2);
    *returnSize = 2;
    if (NULL == nums) return ret;
    if (!binSearch(nums, numsSize, target, &leftIndex, true))  return ret;
    if (!binSearch(nums, numsSize, target, &rightIndex, false))  return ret;
    printf("leftIndex = %d, rightIndex = %d\n", leftIndex, rightIndex);
    ret[0] = leftIndex; ret[1] = rightIndex;
    return ret;
}

int main(void)
{
    int nums[] = { 5,7,7,8,8,10 };
    int *ret = NULL;
    int index = -1;
    int target = 6;
    bool flag = false;
    int returnSize = -1;
    int numsSize = ARRAY_SIZE(nums);

    dumpArray(nums, numsSize);
    ret = searchRange(nums, numsSize, target, &returnSize);
    dumpArray(ret, returnSize);
    return true;
}