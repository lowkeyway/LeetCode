#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

#define VAL 2

int nums[] = { 0,1,2,2,3,0,4,2 };

static void dumpArray(int *s, int size)
{
    int i = 0;
    printf("[");
    for (i = 0; i < size; i++)
    {
        printf(" %d", s[i]);
        if ((size - 1) != i) printf(",");
    }
    printf(" ]\n");
}


int removeElement(int* nums, int numsSize, int val) {
    int i = 0, cur = 0;
    for(i = 0; i < numsSize; i++)
    {
        if (val != nums[i])
        {
            nums[cur++] = nums[i];
        }
    }

    return cur;
}

int main(void)
{
    int ret;
    dumpArray(nums, ARRAY_SIZE(nums));
    ret = removeElement(nums, ARRAY_SIZE(nums), VAL);
    dumpArray(nums, ret);

    return true;
}