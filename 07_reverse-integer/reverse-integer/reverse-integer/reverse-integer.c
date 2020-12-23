#include <stdio.h>
#include <stdlib.h>
#include "LeetCodeBox.h"

int reverse(int x) {
	int ret = 0;
	int flag = 0; 
	uchar f;
	
	flag = x > 0 ? 1 : -1;
	x *= flag;

	do{
		f = x % 10;
		ret = ret * 10 + f;
		x /= 10;
	} while (x != 0);

	ret *= flag;
	return ret;
}

int main(void)
{
	int ret;

	ret = reverse(-120);
	printf("ret = %d\n", ret);

	return 1;
}