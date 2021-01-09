#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

char* haystack = "aaaaa";
char* needle = "bba";

int strStr(char* haystack, char* needle) {
    int i = 0, j = 0;
    int lenH = 0, lenN = 0;
    if (NULL == haystack)    return -1;
    if (NULL == needle)  return 0;

    lenH = strlen(haystack);
    lenN = strlen(needle);

    printf("lenH = %d, lenN = %d\n", lenH, lenN);

    if (lenN > lenH) return -1;


    for (i = 0; i < lenH - lenN; i++)
    {
        j = 0; 
        while (needle[j++] != '\0')
        {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (lenN == j)   return 0;
    }

    return -1;
}

int main(void)
{
    int ret;
    printf("haystack: %s\n", haystack);
    printf("needle: %s\n", needle);
    ret = strStr(haystack, needle);
    printf("ret = %d\n", ret);



    return true;
}