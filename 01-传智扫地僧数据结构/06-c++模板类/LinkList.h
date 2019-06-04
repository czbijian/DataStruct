#pragma once

//�ڲ���Ԫ��ʱ��ģ���� �� Ӧ�ð�ÿһ��t��������
//ģ������Ӧ���� ����ڵ� ������ ====>˼��

//��ô������  ===>linklist ������
template <typename T>
struct Node{
	T t;
	Node<T>* next;
};

template<typename T>
class LinkList
{
public:
	LinkList(void);
	~LinkList(void);

	int clear();

	int getlen();

	int insert(T &t, int pos);

	int get(int pos, T &t);

	int del(int pos, T &t);

private:
	Node<T> *head; //�������� ��һ������ͷ�ڵ������
	int len;
};

