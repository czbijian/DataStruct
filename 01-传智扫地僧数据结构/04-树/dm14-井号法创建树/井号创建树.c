#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct BiTNode 
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//���������������н�����������
BiTNode* BiTree_Creat12()
{
	BiTNode *tmp = NULL;
	char ch;
	printf("\n�������ַ�: ");
	scanf("%c", &ch);
	if (ch == '#')
	{
		return NULL;
	}
	else
	{
		tmp = (BiTNode *)malloc(sizeof(BiTNode));
		if (tmp == NULL)
		{
			return NULL;
		}
		tmp->data = ch; //���ɸ����
		tmp->lchild = BiTree_Creat12();//����������
		tmp->rchild = BiTree_Creat12();//����������
		return tmp;
	}
}

void preOrder(BiTNode *root)
{
	if (root != NULL)
	{
		printf("%c ", root->data);
		preOrder(root->lchild);	
		preOrder(root->rchild);
	}
}

//���������������н�����������
void  BiTree_Free(BiTNode* T)
{
	BiTNode *tmp = NULL;
	if (T!= NULL)
	{
		if (T->rchild != NULL) BiTree_Free(T->rchild);
		if (T->lchild != NULL) BiTree_Free(T->lchild);
		if (T != NULL)
		{
			free(T); 
			T = NULL;
		}
	}
}


void main()
{
	int nCount = 0, depthval = 0;
	BiTNode * my = BiTree_Creat12();
	printf("\n�ǵݹ��㷨c++����\n");
	//InOrder(my);
	preOrder(my);

	BiTree_Free(my);
	printf("���ͷ����\n");

	printf("\n");
	system("pause");
}
