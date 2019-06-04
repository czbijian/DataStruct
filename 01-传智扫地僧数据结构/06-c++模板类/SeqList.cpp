#include "SeqList.h"

template <typename T>
SeqList<T>::SeqList(int capacity)
{
	//T *pArray;
	//aArray = new char[10];
	pArray = new T[capacity];
	this->capacity = capacity;
	this->len = 0;
}

template <typename T>
SeqList<T>::~SeqList(void)
{
	delete[] pArray;
	pArray = NULL;
	len = 0;
	capacity = 0;
}

template <typename T>
int SeqList<T>::getlen(){
	return this->len;
}

template <typename T>
int SeqList<T>::getCapacity(){
	return this->capacity;
}

template <typename T>
int SeqList<T>::insert(T &t, int pos){
	int i = 0;
	if (pos < 0)
	{
	return -1;
	}

	//元素后移
	for (i = len; i > pos; i--)
	{
		pArray[i] = pArray[i-1];
	}
	//插入元素
	pArray[i] = t; //stl元素保存是通过 复制的机制实现的，你的类要可以复制才行。
	this->len ++;
	return 0;

}

template <typename T>
int SeqList<T>::get(int pos, T& t){
	int i = 0;
	t = pArray[pos]; //复制
	return 0;
}

template <typename T>
int SeqList<T>::del(int pos, T &t){
	int i = 0;

	t = pArray[pos]; //缓存pos的位置

	for (i = pos+1; i < len; i++)
	{
		pArray[i-1] = pArray[i];
	}
	len--;
	return 0;

}

template <typename T>
int SeqList<T>::clear(){
	this->len = 0;
	return 0;
}
