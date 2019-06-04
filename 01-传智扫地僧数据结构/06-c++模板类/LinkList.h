#pragma once

//在插入元素时，模板类 中 应该把每一个t保存下来
//模板类中应该能 分配节点 缓存结点 ====>思想

//怎么样缓存  ===>linklist 做链表
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
	Node<T> *head; //在链表中 建一个带有头节点的链表
	int len;
};

