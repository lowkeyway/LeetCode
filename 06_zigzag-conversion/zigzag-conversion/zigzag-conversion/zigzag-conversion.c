#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LeetCodeBox.h"
#include "LeetCodeList.h"

#define MAX_LIST_NUM 4

typedef struct Node {
	uchar c;
	struct list_head list;
}Node_t;

typedef struct List {
	struct list_head head;
	struct list_head list;
}List_t;
 

static char* convert(char* s, int numRows, struct list_head *listHead) {
	uint sLen = 0, index = 0, flag = 0;
	struct list_head *currentHead;
	Node_t *node;
	List_t *lNode;

	sLen = strlen(s);
	char* ret = malloc(sLen+1);
	if (NULL != ret)
	{
		memset(ret, '\0', sLen+1);
	}

	currentHead = listHead->next;
	while (s[index] != '\0')
	{
		Node_t* N = malloc(sizeof(Node_t));
		N->c = s[index++];
		INIT_LIST_HEAD(&N->list);
		List_t* L = container_of(currentHead, List_t, list);
		list_add_tail(&N->list, &L->head); 
		if (0 == flag)
		{
			if (listHead == currentHead->next)
			{
				currentHead = currentHead->prev;
				flag = 1;
			}
			else
			{
				currentHead = currentHead->next;
			}
		}
		else if (1 == flag)
		{
			if (listHead == currentHead->prev)
			{
				currentHead = currentHead->next;
				flag = 0;
			}
			else
			{
				currentHead = currentHead->prev;
			}
		}
	}

	index = 0;
	list_for_each_entry(lNode, listHead, list)
	{
		list_for_each_entry(node, &lNode->head, list)
		{
			ret[index++] = node->c;
		}
	}


	return ret;
}


int main(void)
{
	uint i = 0;
	char* s = "LEETCODEISHIRING";
	char* ret = NULL;

	LIST_HEAD(listHead);

	for (; i < MAX_LIST_NUM; i++)
	{
		List_t* L = malloc(sizeof(List_t));
		INIT_LIST_HEAD(&L->head);
		INIT_LIST_HEAD(&L->list);
		list_add_tail(&L->list, &listHead);
	}

	ret = convert(s, MAX_LIST_NUM, &listHead);

	printf("ret = [%s]\n", ret);
}