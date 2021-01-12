#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

uint getMinPrime(uint num)
{
    uint sqrtNum = 0, i = 0;
    bool priFlag = true;
    uint temp = num;

    while (true)
    {
        priFlag = true;
        sqrtNum = (uint)sqrt(temp);
        for(i = 2; i <= sqrtNum; i++)
        {
            if (0 == (temp % i))
            {
                priFlag = false;
                temp++;
                break;
            }
        }

        if (priFlag) return temp;
    }
}

int main(void)
{
    uint ret = 0;

    ret = getMinPrime(8);
    printf("ret = %d\n", ret);

    return true;
}