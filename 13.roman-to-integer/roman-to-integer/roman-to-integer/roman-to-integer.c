#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

typedef struct int_to_rom
{
	char* rom;
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

int romanToInt(char* s) {
	uchar i = 0;
	int ret = 0;
	if (NULL == s)
	{
		return 0;
	}

	while (*s != '\0')
	{
		for (i = 0; i < ARRAY_SIZE(table); i++)
		{
			if (0 == strncmp(s, table[i].rom, strlen(table[i].rom)))
			{
				ret += table[i].num;
				s += strlen(table[i].rom);
			}
		}
	}

	return ret;
}

int main(void)
{
	char* s = "MCMXCIV";
	int ret = romanToInt(s);
	printf("%s = %d\n", s, ret);
	return 0;
}