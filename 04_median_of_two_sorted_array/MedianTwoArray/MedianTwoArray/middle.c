#include <stdio.h>
#include <stdlib.h>
#include "LeetCodeBox.h"

int compFunc(const void* a, const void* b)
{
	return *(int *)a < *(int *)b;
}

double getMedian(int* numArray, int arraySize)
{
	unsigned int tempIndex;
	if (0 == arraySize)
	{
		return 0;
	}

	if (0 == arraySize % 2)
	{
		tempIndex = arraySize / 2 - 1;
		return (numArray[tempIndex] + numArray[tempIndex + 1]) / 2.0;
	}
	else
	{
		return numArray[arraySize / 2];
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
	double median;
	int i = 0, j = 0, k = 0;
	int* tempArray = NULL;

	tempArray = malloc((nums1Size + nums2Size) * sizeof(int));
	printf("Size Nums1 = %d, Size Nums2 = %d\n", nums1Size, nums2Size);
	
	while (i != nums1Size || j != nums2Size)
	{
		tempArray[k++] = nums1[i] > nums2[j] ? (i == nums1Size ? nums2[j++] : nums1[i++]) : (j == nums2Size ? nums1[i++]: nums2[j++]);
	}

	median = getMedian(tempArray, nums1Size + nums2Size);

	printf("median = %f\n", median);
	return median;
}

int main(void)
{
	int array1[] = { 2, 1, 0 , 4};
	int array2[] = { 3 };

	qsort(array1, ARRAY_SIZE(array1), sizeof(int), compFunc);
	qsort(array2, ARRAY_SIZE(array2), sizeof(int), compFunc);

	findMedianSortedArrays(array1, ARRAY_SIZE(array1), array2, ARRAY_SIZE(array2));

	return 1;
}