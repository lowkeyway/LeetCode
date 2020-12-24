#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LeetCodeBox.h"

char* intToStr(int num)
{
	char	flag = 0;
	int		temp = 0;
	char	index = 0, strLen = 0;
	char*	ret = NULL;


	flag = num > 0 ? 1 : -1;
	temp = num * flag;

	while (0 != temp / 10)
	{
		index++;
		temp /= 10;
	}
	if (-1 == flag)
		index++;

	ret = malloc(index + 2);
	memset(ret, 0, index + 2);

	temp = num * flag;

	for (; index >= 0; index--)
	{
		if (-1 == flag && 0 == index)
		{
			ret[0] = '-';
			continue;
		}
			
		ret[index] = temp % 10 + '0';
		temp /= 10;
	}

	return ret;
}

bool isPalindrome(int x) {
	char* ret;
	uchar strLen = 0;
	uchar i, j;

	ret = intToStr(x);
	printf("ret = [%s]\n", ret);

	strLen = strlen(ret);
	for (i = 0, j = strLen - 1; j > i; i++, j--)
	{
		if (ret[i] != ret[j])
			return 0;
	}

	return 1;
}

int main(void)
{
	uchar ret;
	ret = isPalindrome(-1221);

	printf("ret = %d!\n", ret);
	return 0;
}