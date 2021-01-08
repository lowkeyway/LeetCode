#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

int nums[] = { 1 };

int removeDuplicates(int* nums, int numsSize) {
    int i = 0, cur = 0;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[cur] != nums[i])
        {
            if (1 == (i - cur))
            {
                cur++;
                continue;
            }
            else
            {
                nums[++cur] = nums[i];
                continue;
            }
        }
    }

    return cur+1;
}

static void dumpArray(int* nums, int size)
{
    int i = 0;
    printf("[ ");
    for (i = 0; i < size; i++)
    {
        printf("%d", nums[i]);
        if (i == size - 1)   printf(" ]");
        else printf(", ");
    }
    printf("\n");
}

void sortFunc(const void* a, const void* b)
{
    return (*(int *)a) > (*(int *)b);
}

int main(void)
{
    int ret = 0;
    dumpArray(nums, ARRAY_SIZE(nums));
    qsort(nums, ARRAY_SIZE(nums), sizeof(nums[0]), sortFunc);
    dumpArray(nums, ARRAY_SIZE(nums));
    ret = removeDuplicates(nums, ARRAY_SIZE(nums));
    dumpArray(nums, ret);
    return true;
}