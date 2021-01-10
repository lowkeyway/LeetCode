#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

#define DVD    1
#define DVS    3

static long divLee(long dvd, long dvs)
{
    long ret = 1, temp = dvs;
    if (dvd < dvs) return 0;

    while ((temp + temp) < dvd)
    {
        temp += temp;
        ret += ret;
    }

    return ret + divLee(dvd - temp, dvs);
}

int divide(int dividend, int divisor) {
    long ret = 0;
    long a = dividend, b = divisor;
    int flag = 1;

    if (0 == divisor || 0 == dividend)   return 0;
    if (1 == divisor)    return dividend;
    if (-1 == divisor)
    {
        dividend == INT_MIN ? (dividend = INT_MAX) : (dividend = -dividend);
        return dividend;
    }

    if (0 > dividend) { flag = -flag; a = -a; }
    if (0 > divisor) { flag = -flag; b = -b; }

    ret = divLee(a, b);

    if (0 < flag)
    {
        return MIN(ret, INT_MAX);
    }
    else
    {
        return -ret;
    }
}

int main(void)
{
    int ret;
    ret = divide(DVD, DVS);
    printf("ret = %d\n", ret);
    return true;
}