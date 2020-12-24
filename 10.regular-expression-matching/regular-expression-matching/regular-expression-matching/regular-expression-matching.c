#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

bool isMatch(char* s, char* p) {
	uchar i = 0, j = 0;
	char sc, ppc, pc;
	bool dotFlag = 0;

	if (NULL == s || NULL == p)
	{
		return false;
	}

	while (('\0' != (sc = s[i])) && ('\0' != (pc = p[j])))
	{
		switch (pc)
		{
		case '.':
			i++;
			j++;
			dotFlag = 1;
			break;
		case '*':
			if (dotFlag)
			{
				i++;
				continue;
			}
			dotFlag = 0;
			if (0 != j && sc == ppc)
			{
				i++;
				continue;
			}


			j++;
			break;
		default:
			dotFlag = 0;
			if (sc != pc)
			{
				if ('*' == p[j + 1])
				{
					i++;
					j += 2;
					break;
				}
				printf("Dismatch!\n");
				return false;
			}

			i++;
			j++;
			break;
		}
		ppc = p[j-1];
	}

	if ('\0' == s[i] && '\0' != p[j])
	{
		if ('*' == p[j] && '\0' == p[j+1])
		{
			return true;
		}
		return false;
	}
	else if ('\0' != s[i])
	{
		return false;
	}
	
	return true;
}

int main(void)
{
	bool ret;
	char* s = "aasdb";
	char* p = ".*a";

	ret = isMatch(s, p);
	printf("ret = %d\n", ret);

	return 1;
}