#include "LinkList.h"



template <typename T>
LinkList<T>::LinkList(void)
{
	//Node<T> *head; //�������� ��һ������ͷ������������
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
		tmp = head->next;  //ɾ�������ʱ�򣬻������Ľ�㡣
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
		tmp = head->next;  //ɾ�������ʱ�򣬻������Ľ�㡣
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

	//˼��һ������ node������ô��
	Node<T> *node = new Node<T>;
	if (node == NULL)
	{
		return -1;
	}
	node->t = t;//�����ⲿ����
	node->next = NULL;

	//���½�� ���Ӻ�������
	node->next = current->next;
	//��λ��2���� �½��2
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
	t = current->next->t;  //�ѻ����t ����������
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

	ret = current->next; //��ɾ����Ԫ��
	t = ret->t;   //�ѻ����t copy����

	current->next = ret->next;
	len--;

	delete ret;

	return 0;
}