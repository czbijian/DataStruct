#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;

}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList *ret = NULL;

	ret = (TLinkList *)malloc(sizeof(TLinkList));
	memset(ret, 0, sizeof(TLinkList));
	ret->length = 0;
	ret->header.next = NULL;

	return ret;
}

void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return ;
}

//让链表恢复到初始化状态
void LinkList_Clear(LinkList* list)
{
	TLinkList *tList = NULL;
	if (list == NULL)
	{
		return;
	}
	tList = (TLinkList *)list;

	tList->length = 0;
	tList->header.next = NULL;
	return ;
}

int LinkList_Length(LinkList* list)
{
	TLinkList *tList = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tList = (TLinkList *)list;

	return tList->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	int ret = 0, i = 0;
	LinkListNode *current = NULL;

	TLinkList *tList = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = 0;
		printf("func LinkList_Insert err:%d\n", ret);
		return ret;
	}
	tList = (TLinkList *)list;
	current = &(tList->header);//让辅助指针变量指向链表的头部

	for (i = 0; i < pos && current->next != NULL; i++)//跳pos次
	{
		current = current->next;
	}

	//1 让node接后续链表
	node->next = current->next;
	//2 让前面的链表 连接新的node节点
	current->next = node;
	tList->length++;
	
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	int ret = 0, i = 0;
	LinkListNode *current = NULL;

	TLinkList *tList = NULL;
	if (list == NULL || pos < 0)
	{
		ret = 0;
		printf("func LinkList_Get err:%d\n", ret);
		return NULL;
	}
	tList = (TLinkList *)list;
	current = &(tList->header);//让辅助指针变量指向链表的头部

	for (i = 0; i < pos && current->next != NULL; i++)//跳pos次
	{
		current = current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	int i = 0;
	LinkListNode *current = NULL;
	LinkListNode *ret = NULL;

	TLinkList *tList = NULL;
	if (list == NULL || pos < 0)
	{
		ret = NULL;
		printf("func LinkList_Delete err:%d\n", ret);
		return NULL;
	}
	tList = (TLinkList *)list;
	current = &(tList->header);//让辅助指针变量指向链表的头部

	for (i = 0; i < pos && current->next != NULL; i++)//跳pos次
	{
		current = current->next;
	}

	//缓存被删除的节点位置
	ret = current->next;

	//连线
	current->next = ret->next;
	tList->length--;

	return ret;
}
