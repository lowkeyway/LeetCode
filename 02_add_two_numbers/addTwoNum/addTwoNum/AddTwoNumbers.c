#include <stdio.h>
#include <stdlib.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

struct ListNode {
	unsigned int val;
	struct list_head list;
};

unsigned int listToInt(struct list_head *head)
{
	unsigned int ret = 0;
	//struct ListNode *pos = NULL;

	//list_for_each_entry(pos, head, list)
	//{
	//	ret = ret * 10 + pos->val;
	//}

	//for (pos = __container_of(head->list.next, pos, list); head != pos->list.next; pos = container_of(pos->list.next, pos, list))
	//{
	//	ret = ret * 10 + pos->val;
	//}

	return ret;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	return NULL;
}

void addListTail(struct list_head *head, unsigned int val)
{
	struct ListNode *entry = NULL;

	entry = malloc(sizeof(struct ListNode));
	entry->val = val;
	entry->list.prev = NULL;
	entry->list.next = NULL;

	list_add_tail(&(entry->list), head);
}

void dumpList(struct list_head *head)
{
	//struct ListNode *pos;

	//for()
}

int main(void)
{
	unsigned int int1, int2;
	struct ListNode *pos;

	LIST_HEAD(L1);
	LIST_HEAD(L2);
	INIT_LIST_HEAD(&L1);
	INIT_LIST_HEAD(&L2);

	addListTail(&L1, 2);
	addListTail(&L1, 4);
	addListTail(&L1, 3);

	addListTail(&L2, 5);
	addListTail(&L2, 6);
	addListTail(&L2, 4);

	int1 = listToInt(&L1);
	int2 = listToInt(&L2);

	printf("L1 = %d, L2 = %d\n", int1, int2);

	pos = container_of(L1.next->next, struct ListNode, list);
	//pos = container_of(L1.next->next, (_typeof_(*pos)), list);
	printf("pos->val = %d\n", pos->val);

	system("pause");
	return 0;
}