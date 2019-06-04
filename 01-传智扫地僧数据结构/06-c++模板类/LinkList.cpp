#include "LinkList.h"



template <typename T>
LinkList<T>::LinkList(void)
{
	//Node<T> *head; //在链表中 建一个带有头结点的链表。。。
	head = new Node<T>;
	head->next = NULL;
	this->len = 0;
}

template <typename T>
LinkList<T>::~LinkList(void)
{
	Node<T>* tmp = NULL;
	
	while (head != NULL)
	{
		tmp = head->next;  //删除链表的时候，缓存后面的结点。
		delete head;
		head = tmp;
	}
	len = 0;
	head = NULL;

}

template <typename T>
int LinkList<T>::clear(){
	Node<T>* tmp = NULL;

	while (head != NULL)
	{
		tmp = head->next;  //删除链表的时候，缓存后面的结点。
		delete head;
		head = tmp;
	}

	head = new Node<T>;
	head->next = NULL;
	this->len = 0;

	return 0;
}
template <typename T>
int LinkList<T>::getlen(){
	return len;
}
template <typename T>
int LinkList<T>::insert(T &t, int pos){
	Node<T> *current = NULL;
	current = head;

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	//思考一个问题 node结点存在么？
	Node<T> *node = new Node<T>;
	if (node == NULL)
	{
		return -1;
	}
	node->t = t;//缓存外部数据
	node->next = NULL;

	//让新结点 连接后序链表
	node->next = current->next;
	//让位置2连接 新结点2
	current->next = node;

	len++;

	return 0;
}
template <typename T>
int LinkList<T>::get(int pos, T &t){
	Node<T> *current = NULL;
	current = head;

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	t = current->next->t;  //把缓存的t 传给调用者
	return 0;
}
template <typename T>
int LinkList<T>::del(int pos, T &t){
	Node<T> *current = NULL;
	Node<T> *ret = NULL;
	current = head;

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next; //被删除的元素
	t = ret->t;   //把缓存的t copy出来

	current->next = ret->next;
	len--;

	delete ret;

	return 0;
}