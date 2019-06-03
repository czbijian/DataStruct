#pragma once

template <typename T>
class SeqList
{
public:
	SeqList(int capacity);
	~SeqList(void);

	int getlen();
	
	int getCapacity();

	int insert(T &t, int pos);

	int get(int pos, T& t);

	int del(int pos, T &t);

private:
	int len;
	int capacity;
	T *pArray;  //สýื้

};

