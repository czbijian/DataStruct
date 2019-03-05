#include <stdio.h>
#include <malloc.h>
#include "dlinklist.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider;
	int length;
}TDlinkList;

DLinkList* DLinkList_Create()
{
	TDlinkList* ret = (TDlinkList*)malloc(sizeof(TDlinkList));
	if(ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}

	return ret;
}

void DLinkList_Destroy(DLinkList* list)
{
	if (list != NULL)
	{
		free(list);
	}
	return ;
}

void DLinkList_Clear(DLinkList* list)
{
	TDlinkList* sList = (TDlinkList*)list;

	if (sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
		sList->header.pre = NULL;
		sList->slider = NULL;
	}
	return ;
}

int DLinkList_Length(DLinkList* list)
{
	TDlinkList* sList = (TDlinkList*)list;
	int ret = -1;

	if (sList != NULL)
	{
		ret = sList->length;
	}

	return ret;
}

//���һ��Ҫע�⣬�̿��鲻������� ��Ŀ������� ��Щ������Ŀ���ص�
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	int ret = 0, i = 0;
	TDlinkList* sList = (TDlinkList*)list;

	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* next = NULL;//��Ҫ����nextָ��

		for (i = 0; (i < pos)&&(current->next != NULL); i++)
		{
			current = current->next;
		}
		next = current->next;

		//����1-2
		current->next = node;
		node->next = next;

		//����3-4
		if (next != NULL)//����������һ��Ԫ�أ���Ҫ���⴦��;
		{
			next->pre = node;
		}
		node->pre = current;

		if (sList->length == 0)
		{
			sList->slider = node;//����������һ��Ԫ�ش����α�;
		}

		//����0λ�ò��룬��Ҫ���⴦�� �����ڵ�nextǰpreָ��null;
		if (current == (DLinkListNode*)sList)
		{
			node->pre = NULL;
		}
		sList->length++;
	}

	return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	TDlinkList* sList = (TDlinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (sList != NULL &&(0 <= pos)&&(pos < sList->length))
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		for (i = 0; i < pos; i++)
		{
			current = current->next;
		}
		ret = current->next;
	}
	
	return ret;
}

//�����һ���ڵ�
//ɾ���������һ���ڵ㣬������δ���
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	TDlinkList* sList = (TDlinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	if (sList == NULL || pos < 0)
	{
		return NULL;
	}
	//if (sList != NULL &&(0 <= pos)&&(pos < sList->length))
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* next = NULL;//��Ҫ����nextָ��

		for (i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
		next = ret->next;

		//����1
		current->next = next;

		//����2
		if (next != NULL)//��Ҫ���⴦��
		{
			next->pre = current;
			if (current == (DLinkListNode*)sList)//����0��λ�ã���Ҫ���⴦��
			{
				next->pre = NULL;
			}
		}

		if (sList->slider = ret)
		{
			sList->slider = next;
		}
		sList->length--;
	}
	return ret;
}

//-- add
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	TDlinkList* sList = (TDlinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (sList != NULL)
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		for (i = 0; i <sList->length; i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}
		if (ret != NULL)
		{
			DLinkList_Delete(sList, i);
		}
	}
	return ret;
}

DLinkListNode*  DLinkList_Reset(DLinkList* list)
{
	TDlinkList* sList = (TDlinkList*)list;
	DLinkListNode* ret = NULL;

	if (sList != NULL)
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}

	return ret;
}

DLinkListNode*  DLinkList_Current(DLinkList* list)
{
	TDlinkList* sList = (TDlinkList*)list;
	DLinkListNode* ret = NULL;

	if (sList != NULL)
	{
		ret = sList->slider;
	}

	return ret;
}

DLinkListNode*  DLinkList_Next(DLinkList* list)
{
	TDlinkList* sList = (TDlinkList*)list;
	DLinkListNode* ret = NULL;

	if (sList != NULL && (sList->slider != NULL))
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}

	return ret;
}

DLinkListNode*  DLinkList_Pre(DLinkList* list)
{
	TDlinkList* sList = (TDlinkList*)list;
	DLinkListNode* ret = NULL;

	if (sList != NULL && (sList->slider != NULL))
	{
		ret = sList->slider;
		sList->slider = ret->pre;
	}

	return ret;
}