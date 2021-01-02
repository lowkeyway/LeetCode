#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

typedef struct Node {
    char val;
    list_head_t list;
}Node_t;


void dumpNode(list_head_t* head)
{
    Node_t* N;
    list_for_each_entry(N, head, list)
    {
        printf("%d -> ", N->val);
    }

    printf("\n");
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


list_head_t* mergeTwoLists(list_head_t* l1, list_head_t* l2) {
    Node_t *N1, *N2, *Nt;
    list_head_t *t1, *t2, *ret;
    bool flag1, flag2;

    ret = malloc(sizeof(list_head_t));
    INIT_LIST_HEAD(ret);

    t1 = l1->next;
    t2 = l2->next;

    flag1 = flag2 = 0;

    while (t1 != l1 || t2 != l2)
    {
        if (!flag1)
        {
            if (t1 != l1)
            {
                N1 = container_of(t1, typeof(*N1), list);
                //t1 = t1->next;
            }
            else
            {
                flag1 = 1;
            }
            
        }

        if (!flag2)
        {
            if (t2 != l2)
            {
                N2 = container_of(t2, typeof(*N2), list);
                //t2 = t2->next;
            }
            else
            {
                flag2 = 1;
            }
        }

        if (flag1)
        {
            Nt = N2;
            t2 = t2->next;
        }
        else if(flag2)
        {
            Nt = N1;
            t1 = t1->next;
        }
        else
        {
            Nt = N1->val < N2->val ? N1 : N2;
            N1->val < N2->val ? (t1 = t1->next) : (t2 = t2->next);
        }
        list_add_tail(&Nt->list, ret);
    }

    return ret;
}

int main(void)
{
    char i, j;
    char s1[] = { 1, 2, 4 };
    char s2[] = { 1, 3, 4 };
    list_head_t* ret;

    LIST_HEAD(head1);
    LIST_HEAD(head2);

    for (i = 0; i < ARRAY_SIZE(s1); i++)
    {
        Node_t* N = malloc(sizeof(Node_t));
        N->val = s1[i];
        list_add_tail(&N->list, &head1);
    }

    for (j = 0; j < ARRAY_SIZE(s2); j++)
    {
        Node_t* N = malloc(sizeof(Node_t));
        N->val = s2[j];
        list_add_tail(&N->list, &head2);
    }

    dumpNode(&head1);
    dumpNode(&head2);

    ret = mergeTwoLists(&head1, &head2);
    dumpNode(ret);

    return true;
}