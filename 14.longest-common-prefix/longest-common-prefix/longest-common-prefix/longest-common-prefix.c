#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

char* s[] = {
"dog","racecar","car"
};

char* longestCommonPrefix(char** strs, int strsSize) {
	uchar i = 0, j = 0;
	char temp;
	char* p; 
	char* ret = malloc(20);

	memset(ret, 0, 20);
	p = ret;

	while(true)
	{
		if ('\0' == (temp = strs[0][j]))
			goto finish;

		for (i = 1; i < strsSize; i++)
		{
			if ('\0' == strs[i][j])
				goto finish;
			if (temp != strs[i][j])
				goto finish;
		}

		
		snprintf(p, 2, "%s", &temp);
		p++;
		j++;
	} 

finish:


	return ret;
}

int main(void)
{
	uchar i = 0;
	char* ret;

	ret = longestCommonPrefix(s, ARRAY_SIZE(s));
	printf("ret = %s\n", ret);
	return 0;
}