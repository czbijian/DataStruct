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

	//Ԫ�غ���
	for (i = len; i > pos; i--)
	{
		pArray[i] = pArray[i-1];
	}
	//����Ԫ��
	pArray[i] = t; //stlԪ�ر�����ͨ�� ���ƵĻ���ʵ�ֵģ������Ҫ���Ը��Ʋ��С�
	this->len ++;
	return 0;

}

template <typename T>
int SeqList<T>::get(int pos, T& t){
	int i = 0;
	t = pArray[pos]; //����
	return 0;
}

template <typename T>
int SeqList<T>::del(int pos, T &t){
	int i = 0;

	t = pArray[pos]; //����pos��λ��

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
