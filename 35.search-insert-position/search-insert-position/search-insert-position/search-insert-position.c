#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeSearch.h"

int searchInsert(int* nums, int numsSize, int target) {
    bool ret = false;
    int index = -1;
    ret = binSearch(nums, numsSize, target, &index, true);

    return index;
}

int main(void)
{
    int ret = -1;
    int nums[] = { 1,3,5,6 };
    int numsSize = ARRAY_SIZE(nums);
    int target = 2;

    dumpArray(nums, numsSize);
    ret = searchInsert(nums, numsSize, target);
    printf("target = %d, ret = %d\n", target, ret);

    return true;
}