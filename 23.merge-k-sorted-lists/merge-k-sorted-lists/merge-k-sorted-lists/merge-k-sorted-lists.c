#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

int arrayList[][3] = {
    {1,4,5},
    {1,3,4},
    {2,6,7}
};

bool getMinNode(struct ListNode** lists, int listsSize, int *index)
{
    uchar i = 0, nullCount = 0;
    int tempIndex, tempValue = INT_MAX;
    for (i = 0; i < listsSize; i++)
    {
        if (NULL != lists[i])
        {
            if (tempValue > lists[i]->val)
            {
                tempValue = lists[i]->val;
                tempIndex = i;
            }
            nullCount++;
        }
    }
    *index = tempIndex;
    if (1 == nullCount)  return false;
    return true;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int index = -1;
    ListNode_t* ret = NULL, *tail = NULL;
    ListNode_t** temp = malloc(sizeof(ListNode_t*) * listsSize);
    memcpy(temp, lists, sizeof(ListNode_t*) * listsSize);
    bool flag = true;

    while (flag)
    {
        flag = getMinNode(temp, listsSize, &index);
        if (NULL == ret)
        {
            ret = temp[index];
            tail = ret;
        }
        else
        {
            tail->next = temp[index];
            tail = temp[index];
        }
        temp[index] = temp[index]->next;
    }

    return ret;
}

void dumpNodeLists(ListNode_t** lists, uint size)
{
    uchar i = 0;
    ListNode_t* N;
   
    for (i = 0; i < size; i++)
    {
        printf("lists[%d]: ", i);
        for (N = lists[i]; NULL != N; N = N->next)
        {
            printf("%d -> ", N->val);
        }
        printf("\n");
    }

}

void dumpNodelist(ListNode_t* list)
{
    ListNode_t* N;

    for (N = list; NULL != N; N = N->next)
    {
        printf("%d -> ", N->val);
    }
}

int main(void)
{
    uchar i, j;
    ListNode_t** lists = NULL;
    ListNode_t* ret;

    lists = malloc(sizeof(ListNode_t*) * ARRAY_SIZE(arrayList));
    for (i = 0; i < ARRAY_SIZE(arrayList); i++)
    {
        ListNode_t* head = NULL, * tail = NULL;

        for (j = 0; j < ARRAY_SIZE(arrayList[i]); j++)
        {
            ListNode_t* temp = malloc(sizeof(ListNode_t));
            temp->val = arrayList[i][j];
            temp->next = NULL;
            if (NULL == head)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        lists[i] = head;
    }
    dumpNodeLists(lists, ARRAY_SIZE(arrayList));


    ret = mergeKLists(lists, ARRAY_SIZE(arrayList));
    dumpNodelist(ret);

    return true;
}