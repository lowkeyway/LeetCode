#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN		256
#define INTI_NUM	0XFF

typedef struct Node
{
	unsigned char chr;
	unsigned int index;
}Node_t;

Node_t HashList[MAX_LEN] = {0};

unsigned int addCharToHashList(Node_t* hList, char c, unsigned int index)
{
	if (INTI_NUM != hList[c].chr)
	{
		return hList[c].index;
	}

	Node_t N;
	N.chr = c;
	N.index = index;

	hList[c] = N;
	return INTI_NUM;
}

char* longestPalindrome(char* s) {
	unsigned int cIndex = 0;
	char* palin = NULL;
	unsigned int bIndex = 0;

	palin = s;

	while (s[cIndex] != '\0')
	{
		bIndex = addCharToHashList(HashList, s[cIndex], cIndex);
		if (INTI_NUM != bIndex)
		{
			cIndex++;
			palin = (char*)malloc(cIndex - bIndex + 1);
			memset(palin, 0, cIndex - bIndex + 1);
			memcpy(palin, s + bIndex, cIndex - bIndex);
			return palin;
		}
		cIndex++;
	}

	return NULL;
}

int main(void)
{
	char* s = "malloc";
	char* palind = NULL;
	memset(HashList, INTI_NUM, MAX_LEN*sizeof(Node_t));
	palind = longestPalindrome(s);
	printf("s = [%s]\n", s);
	if (NULL != palind)
	{
		printf("palind = [%s]\n", palind);
	}
}