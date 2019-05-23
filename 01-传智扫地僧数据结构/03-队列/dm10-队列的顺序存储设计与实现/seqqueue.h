#ifndef _MY_SEQQUEUE_H_
#define _MY_SEQQUEUE_H_

typedef void SeqQueue;

SeqQueue* SeqQueue_Create(int capacity);

void SeqQueue_Destroy(SeqQueue* queue);

void SeqQueue_Clear(SeqQueue* queue);

int SeqQueue_Append(SeqQueue* queue, void * item);

void* SeqQueue_Retrieve(SeqQueue* queue);

void* SeqQueue_Header(SeqQueue* queue);

int SeqQueue_Length(SeqQueue* queue);

int SeqQueue_Capacity(SeqQueue* queue);

#endif