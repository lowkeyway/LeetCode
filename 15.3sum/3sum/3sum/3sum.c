#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

int cmpFunc(const void* a, const void* b)
{
	return (*(int*)a > *(int*)b);
}

static void dumpNums(int* nums, int numsSize)
{
	uchar i = 0;
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
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int** ret; uchar retIndex = 0;
	uchar i = 0;
	uchar cur, left, right;
	int temp;
	bool flag = 0;

	if (3 > numsSize)
		return NULL;
	
	ret = malloc(sizeof(int*) * numsSize);

	qsort(nums, numsSize, sizeof(int), cmpFunc);
	//dumpNums(nums, numsSize);

	for (cur = 0; cur < numsSize - 3; cur++)
	{
		if (flag)
		{
			if (cur > 0 && nums[cur] == nums[cur - 1])
				continue;
		}
		temp = -nums[cur];
		left = cur + 1;
		right = numsSize - 1;
		flag = 0;

		while (right > left)
		{
			if (nums[left] + nums[right] == temp)
			{
				flag = 1;
				int* array = malloc(sizeof(int) * 3);
				array[0] = nums[cur];
				array[1] = nums[left];
				array[2] = nums[right];
				ret[retIndex++] = array;
				
				while (left < right && nums[left] == nums[left + 1])	left++;
				while (left < right && nums[right] == nums[right - 1])	right--;

				if (left < right)
				{
					left++;
					right--;
				}
				else
				{
					break;
				}

				continue;
			}
			else if (nums[left] + nums[right] > temp)
			{
				right--;
				continue;
			}
			else
			{
				left++;
				continue;
			}
		}
	}

	*returnSize = retIndex;

	if (0 == retIndex)
	{
		return NULL;
	}

	return ret;
}

int main(void)
{
	int nums[] = { 0, 0, 0, 0, 0 };
	//int nums[] = { -1, 0, 1, 2, -1, -4 };
	int** ret;
	int  returnSize;
	int** returnColumSizes;
	uchar i = 0;

	ret = threeSum(nums, ARRAY_SIZE(nums), &returnSize, returnColumSizes);
	if (NULL == ret)
	{
		printf("ret = NULL\n");
		return 1;
	}

	for (i = 0; i < returnSize; i++)
	{
		printf("ret[%2d] = ", i);
		dumpNums(ret[i], 3);
	}

	return 0;
}