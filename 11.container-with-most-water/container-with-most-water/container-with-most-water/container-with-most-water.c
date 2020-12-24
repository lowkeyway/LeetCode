#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"


int maxArea(int* height, int heightSize) {
	uchar i = 0, j = 0;
	uint tempArea = 0, maxArea = 0;
	uchar h = 0, w = 0;

	for (; i < heightSize; i++)
	{
		tempArea = 0;
		for (j = i + 1; j < heightSize; j++)
		{
			w = j - i;
			h = MIN(height[i], height[j]);
			tempArea = w * h;
			maxArea = MAX(tempArea, maxArea);
		}
	}

	return (int)maxArea;
}

int main(void)
{
	int ret = 0;
	int array[] = { 1,2,1 };
	ret = maxArea(array, ARRAY_SIZE(array));
	printf("ret = %d!\n", ret);
	return true;
}