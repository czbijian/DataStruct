#include <stdio.h>
#include <malloc.h>
#include "seqstack.h"

int main()
{
	int i = 0;
	int a[10];
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	if (stack == NULL)
	{
		return;
	}
	//压栈
	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
	}
	printf("Capacity:%d\n",SeqStack_Capacity(stack));
	printf("length:%d\n",SeqStack_Size(stack));
	printf("top:%d\n",*((int *)SeqStack_Top(stack)));

	while (SeqStack_Size(stack) > 0)
	{
		int tmp = *((int *)SeqStack_Pop(stack));
		printf("tmp:%d ", tmp);
	}
	printf("\n");
	

	return 0;
}