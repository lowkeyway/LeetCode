#include <stdio.h>
#include <stdlib.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"
#include <stddef.h>

struct ListNode {
	unsigned int val;
	struct list_head list;
};


void addListTail(struct list_head* head, unsigned int val)
{
	struct ListNode* entry = NULL;

	entry = malloc(sizeof(struct ListNode));
	entry->val = val;
	entry->list.prev = NULL;
	entry->list.next = NULL;

	list_add_tail(&(entry->list), head);
}

void dumpList(struct list_head* head)
{
	struct ListNode* pos = NULL;

	list_for_each_entry(pos, head, list)
	{
		printf("%d -> ", pos->val);
	}

	printf("\n");
}

unsigned int listToInt(struct list_head *head)
{
	unsigned int ret = 0;
	struct ListNode *pos = NULL;

	list_for_each_entry(pos, head, list)
	{
		ret = ret * 10 + pos->val;
	}

	return ret;
}

unsigned char intToList(unsigned int num, struct list_head* head)
{
	unsigned int index;
	if (!num)
		return FALSE;

	for (; num != 0; num = num/10)
	{
		index = num % 10;
		printf("Add index[%d]\n", index);
		addListTail(head, index);
	}

	return TRUE;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static char addTwoNumbers(struct list_head* l1, struct list_head* l2, struct list_head* l3) {
	unsigned int int1, int2, int3;
	char ret = -1;

	int1 = listToInt(l1);
	int2 = listToInt(l2);

	int3 = int1 + int2;
	printf("int3 = %d\n", int3);

	ret = intToList(int3, l3);

	return ret;
}


int main(void)
{
	//struct ListNode *pos;

	LIST_HEAD(L1);
	LIST_HEAD(L2);
	LIST_HEAD(L3);
	INIT_LIST_HEAD(&L1);
	INIT_LIST_HEAD(&L2);
	INIT_LIST_HEAD(&L3);

	addListTail(&L1, 2);
	addListTail(&L1, 4);
	addListTail(&L1, 3);

	addListTail(&L2, 5);
	addListTail(&L2, 6);
	addListTail(&L2, 4);

	//pos = container_of(L1.next->next, struct ListNode, list);
	//pos = container_of(L1.next->next, typeof(*pos), list);
	//printf("pos->val = %d\n", pos->val);

	addTwoNumbers(&L1, &L2, &L3);
	dumpList(&L3);

	system("pause");
	return 0;
}