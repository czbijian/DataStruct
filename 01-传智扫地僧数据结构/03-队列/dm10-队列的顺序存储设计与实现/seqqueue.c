#include <stdio.h>
#include "seqqueue.h"
#include "seqlist.h"
//����Ҳ��һ����������Ա�
//����һ������ �൱�� ����һ��˳��洢���Ա�
SeqQueue* SeqQueue_Create(int capacity){
	return SeqList_Create(capacity);
}
//���ٶ��� �൱�� ����һ�����Ա�
void SeqQueue_Destroy(SeqQueue* queue){
	return SeqList_Destroy(queue);
}
//��ն��� �൱�� ������Ա�
void SeqQueue_Clear(SeqQueue* queue){
	SeqList_Clear(queue);
}
//����������Ԫ�� �൱�� �����Ա������һ��Ԫ��
int SeqQueue_Append(SeqQueue* queue, void * item){
	return SeqList_Insert(queue, item, SeqQueue_Length(queue));
}
//������ �൱�� �����Ա���ɾ��0��λ��Ԫ��
void* SeqQueue_Retrieve(SeqQueue* queue){
	return SeqList_Delete(queue, 0);
}

void* SeqQueue_Header(SeqQueue* queue){
	return SeqList_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue* queue){
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue){
	return SeqList_Capacity(queue);
}