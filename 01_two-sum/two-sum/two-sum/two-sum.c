#include <stdio.h>
#include <stdlib.h>
#include "LeetCodeBox.h"

typedef struct data {
	int value;
	int index;
}data_t;

int comFun(const void *a, const void *b)
{
	return(((data_t *)a)->value > ((data_t *)b)->value);
}

void dumpData(data_t *pData, int size)
{
	int i = 0;
	printf("DUMP DATA:\t");
	for (; i < size; i++)
	{
		printf("%d ", pData[i].value);
	}

	printf("\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i = 0, j = 0;
	data_t *pData = malloc(numsSize * sizeof(data_t));
	int *pResultArray = malloc(2 * sizeof(int));

	for(; i < numsSize; i++)
	{
		pData[i].value = nums[i];
		pData[i].index = i;
	}
	//dumpData(pData, numsSize);
	qsort(pData, numsSize, sizeof(data_t), comFun);
	dumpData(pData, numsSize);

	i = 0;
	j = numsSize - 1;
	while (j > i)
	{
		int sum = pData[i].value + pData[j].value;
		if (sum > target)
		{
			j--;
		}
		else if (sum < target)
		{
			i++;
		}
		else if (sum == target)
		{
			pResultArray[0] = pData[i].index;
			pResultArray[1] = pData[j].index;
			return pResultArray;
		}
	}
	free(pResultArray);
	return NULL;
}

int main(void)
{
	printf("This is the 1th LeetCode! ====> Two Sum\n");
	int nums[]		= { 2, 11, 7, 15 };
	int target		= 9;
	int returnSize	= 0;
	int *pResultArray = NULL;
	int index = 0;

	pResultArray = twoSum(nums, ARRAY_SIZE(nums), target, &returnSize);
	
	if (pResultArray)
	{
		for (index = 0; index < 2; index++)
		{
			printf("Index[%d]: %d\n", index, pResultArray[index]);
		}
		free(pResultArray);
	}
	else
	{
		printf("Cannot Find targe!");
	}
	
	system("pause");
}