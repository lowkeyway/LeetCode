#ifndef _LEETCODE_SEARCH_

#include <stdlib.h>

bool binSearch(int* nums, int numsSize, int target, int* index, bool low)
{
    int l = 0, r = numsSize - 1, middle = -1, cur = -1;
    if (NULL == nums) return false;
    if (target < nums[l])
    {
        *index = 0;
        return false;
    }
    if (target > nums[r])
    {
        *index = numsSize;
        return false;
    }

    while (l <= r)
    {
        middle = (l + r) / 2;

        if (target < nums[middle] || (low && target == nums[middle]))
        {
            r = middle - 1;
            cur = middle;
        }
        else
        {
            l = middle + 1;
        }
    }

    if (!low) cur--;

    *index = cur;

    if (target == nums[cur])
    {
        return true;
    }

    return false;
}

#endif // !_LEETCODE_SEARCH_
#pragma once
