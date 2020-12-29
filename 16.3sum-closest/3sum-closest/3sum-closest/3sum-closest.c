#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

#define ERROR_NUM	0XA5A5

typedef struct sumClosest {
	uint abs;
	int  sum;
}sumClosest_t;

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


int threeSumClosest(int* nums, int numsSize, int target) {
	sumClosest_t s, sPre = { UINT_MAX , INT_MAX};

	int ret = 0, retPre = INT_MAX, temp = 0;
	uint abs = 0, absPre = UINT_MAX;
	int array[3] = { 0 };
	uchar cur, left, right;
	uchar i = 0;
	bool flag = 0;

	if (3 > numsSize)
		return ERROR_NUM;

	qsort(nums, numsSize, sizeof(int), cmpFunc);
	dumpNums(nums, numsSize);

	for (cur = 0; cur < numsSize - 2; cur++)
	{
		if (cur > 0 && nums[cur] == nums[cur - 1])
			continue;

		left = cur + 1;
		right = numsSize - 1;
		absPre = UINT_MAX;
		//flag = 0;

		while (right > left)
		{
			temp = target - (nums[cur] + nums[left] + nums[right]);
			abs = ABS(temp);
			if (0 == abs)
			{
				return temp;
			}

			if (abs > absPre)
			{
				//flag = 1;
				break;
			}
			absPre = abs;
			ret = nums[cur] + nums[left] + nums[right];

			while (left < right && nums[left] == nums[left + 1])	left++;
			while (left < right && nums[right] == nums[right - 1])	right--; 
			
			if (0 > temp)
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

		s.abs = absPre;
		s.sum = ret;

		s = s.abs > sPre.abs ? sPre : s;
		sPre = s;
	}

	ret = s.sum;
	return ret;
}

int main(void)
{
	int ret;
	int nums[] = { -1,2,1,1, 0, -2 };
	int target = 1;

	ret = threeSumClosest(nums, ARRAY_SIZE(nums), target);

    printf("ret = %d\n", ret);
    return 1;
}