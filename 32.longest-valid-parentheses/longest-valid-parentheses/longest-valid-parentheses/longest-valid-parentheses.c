#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

int longestValidParentheses(char* s) {
    int ret = 0, temp = 0;
    uint left = 0;
    uint i = 0;

    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case '(':
            left++;
            break;
        case ')':
            if (0 == left)
            {
                ret = MAX(ret, temp);
                break;
            }

            left--;
            temp++;
            break;

        default:
            break;
        } 
        i++;
        continue;
    }

    ret = MAX(ret, temp);
    return ret * 2;
}

int main(void)
{
    int ret;
    char* s = "(()";
    ret = longestValidParentheses(s);
    printf("ret = %d\n", ret);
    return true;
}