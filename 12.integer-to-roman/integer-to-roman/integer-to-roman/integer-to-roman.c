#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

char* intToRoman(int num) {
	char	index = 0, i = 0;
	int		temp = 0;
	bool	flag = 0;

	temp = num;
	//¸ö Ê® °Ù Ç§
	uchar dNum[4] = { 0 };
	char* ret = malloc(20);
	memset(ret, 0, 20);
	char *p = ret;

	for (index = 0; index < 4; index++)
	{
		if (0 == temp)
		{
			break;
		}

		if (3 == index)
		{
			dNum[index] = temp;
			index++;
			break;
		}

		dNum[index] = temp % 10;
		temp /= 10;
	}

	for (index--; index >= 0; index--)
	{
 		flag = dNum[index] >= 5 ? 1 : 0;
		switch (index)
		{
		case 3:
			for (i = 0; i < dNum[index]; i++)
			{
				snprintf(p, 2, "M");
				p++;
			}
			break;
		case 2:
			if(4 == dNum[index])
			{
				snprintf(p, 3, "CD");
				p+=2;
				break;
			}

			if (9 == dNum[index])
			{
				snprintf(p, 3, "CM");
				p += 2;
				break;
			}

			if (flag)
			{
				snprintf(p, 2, "D");
				p++;
			}

			for (i = 0; i < (dNum[index] - flag * 5); i++)
			{
				snprintf(p, 2, "C");
				p++;
			}
			break;

		case 1:
			if (4 == dNum[index])
			{
				snprintf(p, 3, "XL");
				p += 2;
				break;
			}

			if (9 == dNum[index])
			{
				snprintf(p, 3, "XC");
				p += 2;
				break;
			}

			if (flag)
			{
				snprintf(p, 2, "L");
				p++;
			}

			for (i = 0; i < (dNum[index] - flag * 5); i++)
			{
				snprintf(p, 2, "X");
				p++;
			}
			break;

		case 0:
			if (4 == dNum[index])
			{
				snprintf(p, 3, "IV");
				p += 2;
				break;
			}

			if (9 == dNum[index])
			{
				snprintf(p, 3, "IX");
				p += 2;
				break;
			}

			if (flag)
			{
				snprintf(p, 2, "V");
				p++;
			}

			for (i = 0; i < (dNum[index] - flag * 5); i++)
			{
				snprintf(p, 2, "%s", "I");
				p++;
			}
			break;

		default:
			break;
		}
	}

	return ret;
}

int main(void)
{
	char* ret = NULL;
	unsigned int number = 184;
	ret = intToRoman(number);
	if(NULL != ret)
		printf("%d = %s!\n", number, ret);

	return 0;
}