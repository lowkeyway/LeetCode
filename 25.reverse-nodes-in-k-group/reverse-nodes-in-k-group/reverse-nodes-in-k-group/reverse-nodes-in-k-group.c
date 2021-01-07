#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

//int s[] = { };
int s[] = { 1, 2, 3, 4, 5 };

typedef struct group {
    ListNode_t* head;
    ListNode_t* tail;
}group_t;

// 3
group_t rollOver(ListNode_t* head, ListNode_t* tail)
{
    group_t ret = { 0 };


    ListNode_t* nxt, * cur, *temp, *tNext;
    tNext = nxt = tail->next;
    cur = head;

    while (cur != tNext)
    {
        temp = cur->next;
        cur->next = nxt;
        nxt = cur;
        cur = temp;
    }

    ret.head = tail;
    ret.tail = head;

    return ret;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int i = 0;
    group_t g;
    // 2
    ListNode_t* hair = malloc(sizeof(ListNode_t));
    ListNode_t* tail = NULL, *nex = NULL, *pre;
    hair->val = 0;
    hair->next = head;
    tail = pre = hair;
    while (head)
    {
        // 2.1

        for (i = 0; i < k; i++)
        {
            tail = tail->next;
            if (NULL == tail)
            {
                return hair->next;
            }
        }
        // 2.2
        g = rollOver(head, tail);
        // 2.3
        pre->next = g.head;
        pre = tail = g.tail;
        head = g.tail->next;
    }
    return hair->next;
}

int main(void)
{
    ListNode_t* head;
    // 1
    head = intToList(s, ARRAY_SIZE(s));
    dumpList(head);
    // 2
    head = reverseKGroup(head, 1);
    dumpList(head);

    return true;
}