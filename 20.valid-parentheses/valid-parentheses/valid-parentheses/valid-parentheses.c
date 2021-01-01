#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"

char isPair(char c)
{
    if (')' == c) return '(';
    if (']' == c) return '[';
    if ('}' == c) return '{';

    return '\0';
}

bool isValid(char* s) {
    char temp[100] = { 0 };

    uchar sIndex = 0, tIndex = 0;
    while ('\0' != s[sIndex])
    {
        switch (s[sIndex])
        {
        case '(':
        case '[':
        case '{':
            temp[tIndex++] = s[sIndex];
            break;
        case ')':
        case ']':
        case '}':
            if (0 == tIndex)
                return false;
            if (isPair(s[sIndex]) != temp[tIndex - 1])
                return false;
            tIndex--;
            break;
        default:
            break;
        }

        sIndex++;

    }

    if (0 != tIndex) return false;

    return true;
}

int main(void)
{
    bool ret = 0;
    char* s = "{[()]}";
    ret = isValid(s);
    printf("ret = %d\n", ret);

    return 0;
}