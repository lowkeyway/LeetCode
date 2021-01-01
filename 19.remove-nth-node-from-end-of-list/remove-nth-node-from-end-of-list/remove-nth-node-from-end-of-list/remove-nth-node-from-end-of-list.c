#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LeetCodeBox.h"
#include "LeetCodeList.h"


typedef struct ListNode {
    int val;
    list_head_t list;
}ListNode_t;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
uchar removeNthFromEnd(list_head_t* head, int n) {
    uchar i = 0;
    list_head_t* cur;
    cur = head;
    for (i = 0; i < n; i++)
    {
        if (head == cur->prev)   return 0;
        cur = cur->prev;
    }

    list_del(cur);
    return 1;
}


void addListNode(list_head_t *head, int val)
{
    ListNode_t* N = malloc(sizeof(ListNode_t));
    N->val = val;
    list_add_tail(&N->list, head);
}

void dumpNode(list_head_t *head)
{
    ListNode_t* N;
    list_for_each_entry(N, head, list)
    {
        printf("%d -> ", N->val);
    }
    printf("\n");
}

int main(void)
{
    uchar i = 0;
    LIST_HEAD(head);
    //INIT_LIST_HEAD(&head);
    for (i = 0; i < 5; i++)
    {
        addListNode(&head, i);
    }

    dumpNode(&head);

    removeNthFromEnd(&head, 1);
    dumpNode(&head);

    return 0;
}