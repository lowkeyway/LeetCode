#ifndef _LEETCODE_SEARCH_

#include <stdlib.h>

bool binSearch(int* nums, int numsSize, int target, int* index, bool low)
{
    int l = 0, r = numsSize - 1, middle = -1;
    if (NULL == nums) return false;
    if (target < nums[l] || target > nums[r])    return false;
    if (1 == numsSize) return target == nums[0] ? true : false;

    while (l <= r)
    {
        middle = (l + r) / 2;
        //if (target == nums[middle])
        //{
        //    *index = middle;
        //    return true;
        //}

        if (target < nums[middle] || (low && target == nums[middle]))
        {
            r = middle - 1;
        }
        else
        {
            l = middle + 1;
        }
    }

    if (!low) middle--;

    if (target == nums[middle])
    {
        *index = middle;
        return true;
    }

    return false;
}

#endif // !_LEETCODE_SEARCH_
#pragma once
