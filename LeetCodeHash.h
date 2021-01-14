#ifndef _LEETCODE_HASH_
#define _LEETCODE_HSAH_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "LeetCodeBox.h"

#define HASH_MODULO	        101
#define P_A                 3
#define P_B                 7


typedef struct hashListNode {
    char* str;
    uint value;
    struct hashListNode* next;
}hashListNode_t;


uint getMinPrime(uint num)
{
    uint sqrtNum = 0, i = 0;
    bool priFlag = true;
    uint temp = num;
    if (2 == num) return 3;
    while (true)
    {
        priFlag = true;
        sqrtNum = (uint)sqrt(temp);
        for (i = 2; i <= sqrtNum; i++)
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


hashListNode_t* initHashList(uint nums, uint* listSize)
{
    uint pri = getMinPrime(nums);
    hashListNode_t* head = malloc(sizeof(hashListNode_t) * pri);
    memset(head, 0, sizeof(hashListNode_t) * pri);

    *listSize = pri;
    return head;
}

uint getNodeIndex(char* str, uint strSize, uint listSize)
{
    uint i = 0, ret = 0;
    ull temp = 1;
    for (i = 0; i < strSize; i++)
    {
        temp = temp * HASH_MODULO + (ull)str[i];
    }

    return (uint)((P_A * temp + P_B) % listSize);
}

void freeHashList(hashListNode_t* head, uint listSize)
{
    uint i = 0;
    hashListNode_t* temp = NULL, * nxt = NULL;

    for (i = 0; i < listSize; i++)
    {
        temp = head[i].next;
        if (NULL == temp) continue;
        while (true)
        {
            nxt = temp->next;
            free(temp);

            if (NULL == nxt) break;
            temp = nxt;
        }
    }

    memset(head, 0, sizeof(hashListNode_t) * listSize);
}


bool addToHashList(hashListNode_t* head, uint listSize, char* str, uint strSize)
{
    uint nodeIndex = getNodeIndex(str, strSize, listSize);
    if (nodeIndex >= listSize)   return false;

    if (NULL == head[nodeIndex].str)
    {
        head[nodeIndex].str = malloc(strSize + 1);
        memset(head[nodeIndex].str, 0, strSize + 1);
        memcpy(head[nodeIndex].str, str, strSize);
        head[nodeIndex].value = 1;
        head[nodeIndex].next = NULL;
        return true;
    }

    hashListNode_t* cur = &head[nodeIndex];
    while (true)
    {
        if (!strncmp(cur->str, str, strSize))
        {
            cur->value++;
            return true;
        }

        if (NULL == cur->next)
        {
            hashListNode_t* temp = malloc(sizeof(hashListNode_t));
            temp->str = malloc(strSize + 1);
            memset(temp->str, 0, strSize + 1);
            memcpy(temp->str, str, strSize);
            temp->value = 1;
            temp->next = NULL;
            cur->next = temp;
            return true;
        }

        cur = cur->next;
    }
}

void dumpHashList(hashListNode_t* head, uint listSize)
{
    uint i = 0;
    for (i = 0; i < listSize; i++)
    {
        hashListNode_t* temp = &head[i];
        if (NULL == temp->str)
        {
            printf("[NULL, 0]\n");
            continue;
        }

        while (true)
        {

            printf("[%s, %d]", temp->str, temp->value);

            if (NULL == temp->next)
            {
                printf("\n");
                break;
            }
            printf(" -> ");
            temp = temp->next;
        }
    }
}

uint getHashValue(hashListNode_t* head, uint listSize, char* str, uint strSize)
{
    uint nodeIndex = getNodeIndex(str, strSize, listSize);
    if (nodeIndex >= listSize)   return false;
    if (NULL == head[nodeIndex].str)
    {
        return 0;
    }

    hashListNode_t* cur = &head[nodeIndex];
    while (true)
    {
        if (!strncmp(cur->str, str, strSize))
        {
            return cur->value;
        }

        if (NULL == cur->next)
        {
            return 0;
        }

        cur = cur->next;
    }
}


#endif
