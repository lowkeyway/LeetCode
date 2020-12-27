#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LeetCodeBox.h"

typedef struct int_to_rom
{
	char*	rom;
	int		num;
}int_to_rom_t;

int_to_rom_t table[] = {
	{"M",  1000},
	{"CM", 900},
	{"D",  500},
	{"CD", 400},
	{"C",  100},
	{"XC", 90},
	{"L",  50},
	{"XL", 40},
	{"X",  10},
	{"IX", 9},
	{"V",  5},
	{"IV", 4},
	{"I",  1},
};

char* intToRoman(int num) {
	uchar i = 0;
	char* ret = malloc(20);
	memset(ret, 0, 20);

	char* p = ret;
	int temp = num;
	//while (temp > 0)
	//{
	//	for (i = 0; i < ARRAY_SIZE(table); i++)
	//	{
	//		if (temp >= table[i].num)
	//		{
	//			uchar strLen = strlen(table[i].rom);
	//			snprintf(p, strLen + 1, "%s", table[i].rom);
	//			p += strLen;
	//			temp -= table[i].num;
	//			break;
	//		}

	//		continue;
	//	}
	//}

	for (i = 0; i < ARRAY_SIZE(table); i++)
	{
		while (temp > table[i].num)
		{
			uchar strLen = strlen(table[i].rom);
			snprintf(p, strLen + 1, "%s", table[i].rom);
			p += strLen;
			temp -= table[i].num;
			break;
		}
	}

	return ret;
}

int main(void)
{
	char* ret = NULL;;
	int number = 1994;
	ret = intToRoman(number);
	if (NULL != ret)
		printf("%d = %s\n", number, ret);
	return 0;
}
