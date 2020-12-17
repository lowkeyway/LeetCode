#include <stdio.h>
#include <stdlib.h>
#include "LeetCodeBox.h"

#define MAX_LEN 256
#define SET_BIT(Value, X) Value = (Value & 0xff) | (1 << X)
#define GET_BIT(Value, X) (0 == ((Value & 0xff) & (1 << X))) ? FALSE : TRUE

const char *name = "0123abc012loius";


void setBitMask(char* bitMask, unsigned int index)
{
	int byteOffSet, bitOffSet;
	byteOffSet = index / 8;
	bitOffSet = index % 8;

	SET_BIT(bitMask[byteOffSet], bitOffSet);
	
	return;
}

unsigned char getBitMask(char* bitMask, unsigned int index)
{
	int byteOffSet, bitOffSet;
	byteOffSet = index / 8;
	bitOffSet = index % 8;

	return GET_BIT(bitMask[byteOffSet], bitOffSet);
}

void dumpBitMask(char* bitMask, int len)
{
	int i = 0;
	for (; i < len; i++)
	{
		printf("[%02x] ", bitMask[i]);
	}
}

int lengthOfLongestSubstring(char* s) {
	char bitMask[MAX_LEN / 8 + 1] = { 0 };
	unsigned int index = 0;
	unsigned int temp = 0;

	while (s[index] != '\0')
	{
		temp = (unsigned int)s[index];
		if (0 != getBitMask(bitMask, temp))
		{
			printf("Find the repeat char, It is ['%c']\n", s[index]);
			return index - 1;
		}

		setBitMask(bitMask, temp);

		printf("Index = %d, temp = %d\n", index, temp);

		index++;
	}

	dumpBitMask(bitMask, MAX_LEN / 8 + 1);

	return index;
}

int main(void)
{
	int len = 0;
	len = lengthOfLongestSubstring(name);
	printf("The max len is %d\n", len);
}