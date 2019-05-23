#include <stdio.h>
#include <malloc.h>
#include "linkstack.h"
#include "linklist.h"

typedef struct _tag_LinkStackNode  //�����ҵ��ڵ�
{
	LinkListNode node; //��һ���� (��һ��Ԫ��)
	void* item;    //ջ��ҵ��ڵ�
}TLinkStackNode;

//����ջ �൱�� ����һ�����Ա�
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

//����һ��ջ �൱�� ����һ�����Ա�
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
}

//���һ��ջ �൱�� ���һ�����Ա�
//���ջ��ʱ�� �漰��ջԪ���������ڵĹ���
//������ջ�Ľڵ㶼��malloc��
//��Ҫ���ջ����ջ��Ԫ�ص����������ͷ� ����ڴ�
void LinkStack_Clear(LinkStack* stack)
{
	if(stack == NULL){
		return ;
	}
	while(LinkList_Length(stack) > 0){
		LinkStack_Pop(stack);  //������������ͷŽ����ڴ�
	}
	return ;
}
//��ջ�� ���Ԫ�� �൱�� �����Ա��ͷ������Ԫ��
//void* item ջ��ҵ��ڵ� ---->ת���� �����ҵ��ڵ�
int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode *tmp = NULL;
	int ret = 0;
	tmp = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
	if(tmp == NULL){
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;

	ret = LinkList_Insert(stack, (LinkListNode *)tmp, 0);
	if(ret != 0){
		printf("func LinkList_Insert() err:%d\n", ret);
		if(tmp != NULL){
			free(tmp);
		}
		return ret;
	}
	return ret;
}
//��ջ�е���Ԫ�أ��൱�� �����Ա��ͷ��ɾ��Ԫ��
//�����Ա��ҵ��ڵ� ת���� ջ��ҵ��ڵ�
void* LinkStack_Pop(LinkStack* stack)
{
	void *item = NULL;  //ջ��ҵ��ڵ�
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if(tmp == NULL){
		return NULL;
	}
	item = tmp->item;
	//��ΪLinkList_Insert��ʱ��������ڴ棬����LinkList_Delete�ͷ��ڴ�
	free(tmp);
	return item;
}

//��ȡջ��Ԫ�� �൱�� ��ȡ���Ա��0��λ��
void* LinkStack_Top(LinkStack* stack)
{
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Get(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp->item;
}
//��ջ�Ĵ�С �൱�������Ա��len
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}