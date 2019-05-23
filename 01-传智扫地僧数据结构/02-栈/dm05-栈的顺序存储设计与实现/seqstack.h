#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

typedef void SeqStack;

SeqStack* SeqStack_Create(int capacity);

void SeqStack_Destrooy(SeqStack* stack);

void SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack, void* item);

void* SeqStack_Pop(SeqStack* stack);

void* SeqStack_Top(SeqStack* stack);

int SeqStack_Size(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);

#endif