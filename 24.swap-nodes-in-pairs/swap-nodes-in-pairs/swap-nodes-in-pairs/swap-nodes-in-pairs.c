#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

int s[] = { 1, 2, 3, 4 };

void dumpList(ListNode_t* head)
{
    ListNode_t* cur;

    for (cur = head; cur != NULL; cur = cur->next)
    {
        printf("%2d -> ", cur->val);
    }
    printf("\n");
}

void intToList(int* s, int size, ListNode_t** head)
{
    int i = 0;
    ListNode_t* tail;
    
    for (i = 0; i < size; i++)
    {
        ListNode_t* temp = malloc(sizeof(ListNode_t));
        temp->val = s[i];
        temp->next = NULL;
        if (NULL == *head)
        {
            *head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
}

static void swapPairs_(ListNode_t** head)
{
    ListNode_t* cur, * next;
    if (NULL == *head || NULL == (*head)->next)  return;

    cur = *head;
    next = (*head)->next;

    cur->next = next->next;
    *head = next;
    next->next = cur;

    swapPairs_(&(cur->next));
}

struct ListNode* swapPairs(struct ListNode* head) {
    ListNode_t* ret = head;
    swapPairs_(&ret);
    
    return ret;
}

int main(void)
{
    ListNode_t *head = NULL, *ret = NULL;
    intToList(s, ARRAY_SIZE(s), &head);
    dumpList(head);
    ret = swapPairs(head);
    dumpList(ret);
    return true;
}