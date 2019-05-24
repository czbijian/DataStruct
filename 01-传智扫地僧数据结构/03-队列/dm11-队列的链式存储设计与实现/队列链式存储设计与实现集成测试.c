#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue.h"

int main(){
	int i = 0;
	int a[10];
	LinkQueue* queue = NULL;
	queue = LinkQueue_Create();
	if(queue == NULL){
		return ;
	}
	//入队列
	for(i = 0; i < 5; i++){
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}
	//打印队列的属性
	printf("len:%d\n",LinkQueue_Length(queue));
	printf("heademl:%d\n", *((int *)LinkQueue_Header(queue)));
	//出队列
	while(LinkQueue_Length(queue) > 0){
		int tmp = *((int*)LinkQueue_Retrieve(queue));
		printf("tmp:%d ", tmp);
	}
	LinkQueue_Destroy(queue);

	printf("hello...\n");
	system("pause");
	return 0;
}