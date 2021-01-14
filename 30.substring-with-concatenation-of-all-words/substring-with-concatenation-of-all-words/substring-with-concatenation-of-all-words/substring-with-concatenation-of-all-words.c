#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"
#include "LeetCodeHash.h"


bool comHashList(hashListNode_t* headWords, hashListNode_t* headStr, int listWordsSize, char*s, int wordLen, int wordSize)
{
    bool ret = true;
    char* temp = s;
    uint i = 0, valueWords, valueStr;


    for (i = 0; i < wordSize; i++)
    {
        valueWords = getHashValue(headWords, listWordsSize, temp, wordLen);
        if (0 == valueWords)  return false;
        addToHashList(headStr, listWordsSize, temp, wordLen);
        temp += wordLen;
    }

    //printf("\nDump headWords-->\n");
    //dumpHashList(headWords, listWordsSize);
    //printf("\nDump headStr-->\n");
    //dumpHashList(headStr, listWordsSize);

    temp = s;
    for (i = 0; i < wordSize; i++)
    {
        valueWords = getHashValue(headWords, listWordsSize, temp, wordLen);
        valueStr = getHashValue(headStr, listWordsSize, temp, wordLen);
        if (valueStr != valueWords)  return false;
        temp += wordLen;
    }


    return ret;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int* ret = NULL;
    if (NULL == s || NULL == words)  return ret;

    uint wordLen = strlen(words[0]);
    uint wordSize = wordsSize / wordLen;
    uint values = 0, listWordsSize = 0, listStrSize = 0,  i = 0, index = 0;
    bool matchFlag = 0;
    uint strLen = strlen(s);

    if (strLen < wordsSize) return ret;
    ret = malloc(sizeof(int) * (strLen - wordsSize));
    memset(ret, 0, sizeof(int) * (strLen - wordsSize));

    hashListNode_t* headWords = initHashList(wordSize, &listWordsSize);
    hashListNode_t* headStr = initHashList(wordSize, &listStrSize);

    for (i = 0; i < wordSize; i++)
    {
        addToHashList(headWords, listWordsSize, words[i], strlen(words[i]));
    }

    //printf("words = %d, listSize = %d\n", wordSize, listSize);
    //dumpHashList(headWords, listWordsSize);


    //for (i = 0; i < wordSize; i++)
    //{
    //    values = getHashValue(headWords, listWordsSize, words[i], strlen(words[i]));
    //    printf("Times of [%s] in hash is %d\n", words[i], values);
    //}

    for (i = 0; i < (strLen - wordSize); i++)
    {
        //printf("\n\n==>[%d]: \n", i);
        matchFlag = comHashList(headWords, headStr, listWordsSize, &s[i], wordLen, wordSize);
        if (matchFlag)
        {
            printf("$$$$$$$$$$ i = %d $$$$$$$$$$\n", i);
            ret[index++] = i;
        }
        freeHashList(headStr, listWordsSize);
    }
    *returnSize = index;
    return ret;
}

int main(void)
{
    char* s = "barfoothefoobarman";
    char* words[] = { "foo","bar" };
    uint i = 0;

    uint wordsSize = ARRAY_SIZE(words) * strlen(words[0]);
    int returnSize;
    int* ret;

    ret = findSubstring(s, words, wordsSize, &returnSize);
    printf("[ ");
    for (i = 0; i < returnSize; i++)
    {
        printf("%2d ", ret[i]);
    }
    printf(" ]");


    return true;
}