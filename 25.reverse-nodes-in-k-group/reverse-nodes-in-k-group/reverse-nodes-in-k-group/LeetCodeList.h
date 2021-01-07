#ifndef _LEETCODE_LIST_
#define _LEETCODE_LIST_

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#define container_of(ptr, type, member)     (type *)((char *)(ptr) - (char *) &((type *)0)->member)

typedef struct list_head{
	struct list_head *next, *prev;
}list_head_t;

#define LIST_HEAD_INIT(name) {&(name), &(name)}
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

static inline void
INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list->prev = list;
}

static inline void
__list_add(struct list_head *entry, struct list_head *prev, struct list_head *next)
{
	next->prev = entry;
	entry->next = next;
	entry->prev = prev;
	prev->next = entry;
}

static inline void
list_add(struct list_head *entry, struct list_head *head)
{
	__list_add(entry, head, head->next);
}

static inline void
list_add_tail(struct list_head *entry, struct list_head *head)
{
	__list_add(entry, head->prev, head);
}

static inline void
__list_del(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void 
list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
}

static inline char 
list_empty(struct list_head *head)
{
	return head->next == head;
}


#define list_entry(ptr, type, member)			container_of(ptr, type, member)
#define list_first_entry(ptr, type, member)		list_entry((ptr)->next, type, member)
#define list_last_entry(ptr, type, member)		list_entry((ptr)->prev, type, member)
#define list_next_entry(pos, member)			list_entry((pos)->member.next, typeof(*(pos)), member)
#define list_entry_is_head(pos, head, member)	(&pos->member == (head))

//#define __container_of(ptr, sample, member)		(void *)container_of((ptr), typeof(*(sample)), member)
//
//#define list_for_each_entry(pos, head, member)					\
//	for(pos = __container_of((head)->next, pos, member);		\
//		&pos->member != (head);									\
//		pos = __container_of(pos->member.next, pos, member))



#define list_for_each_entry(pos, head, member)					\
	for (pos = list_first_entry(head, typeof(*pos), member);	\
	     !list_entry_is_head(pos, head, member);				\
	     pos = list_next_entry(pos, member))


/************************************/
/********** Sigle List **************/
/************************************/
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode_t;

static ListNode_t* 
intToList(int* s, int size)
{
    int i = 0;
    ListNode_t *head = NULL, *cur = NULL;
    for (i = 0; i < size; i++)
    {
        ListNode_t* temp = malloc(sizeof(ListNode_t));
        temp->val = s[i];
        temp->next = NULL;
        if (NULL == head)
        {
            head = temp;
            cur = head;
        }
        else
        {
            cur->next = temp;
            cur = cur->next;
        }
    }

    return head;
}

static void 
dumpList(ListNode_t* head)
{
    while (true)
    {
        if (NULL == head)    return;
        printf("%d ", head->val);
        if (NULL == head->next)
        {
            printf("\n");
            return;
        }
        head = head->next;
        printf("-> ");
    }
   
}

#endif // !_LEETCODE_LIST_
#pragma once
