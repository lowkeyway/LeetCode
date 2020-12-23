#include <stdio.h>
#include <stdlib.h>
#include "LeetCodeBox.h"


uchar isIntChar(char c)
{
	return (c >= '0' && c <= '9') ? TRUE : FALSE;
}

uchar isValidInt(long long l, char flag)
{
	char f;
	f = flag > 0 ? 1 : 0;
	return f ? (l > 0x7fffffff ? 0 : 1) : (l > 0x80000000 ? 0 : 1);
}

int myAtoi(char* s) {
	uint index = 0;
	uchar Begin = TRUE;
	char flag = 1, c, valid = 0;
	long long ret = 0;


	if (NULL == s)
	{
		printf("Incorrect Input 1!\n");
		return 0;
	}

	while ('\0' != (c = s[index++]))
	{
		if (' ' == c)
			continue;

		if (Begin)
		{
			switch (c)
			{
			case '+':
				flag = 1;
				Begin = FALSE;
				continue;
			case '-':
				flag = -1;
				Begin = FALSE;
				continue;
			default:
				if (!isIntChar(c))
				{
					printf("Incorrect Input 2!\n");
					return 0;
				}

				Begin = FALSE;
				break;
			}
		}

		if (!isIntChar(c))
		{
			break;
		}

		ret = ret * 10 + (c - '0');
		if (!isValidInt(ret, flag))
		{
			printf("Incorrect Input 3!\n");
			return 0;
		}
	}

	return (int)(ret * flag);
}

int main(void)
{
	int ret;
	ret = myAtoi("-2147483648");
	printf("ret = %d\n", ret);

	return 1;
}