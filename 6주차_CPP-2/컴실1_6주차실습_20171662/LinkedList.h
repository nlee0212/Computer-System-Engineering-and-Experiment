#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

// Linked List Node
template <class T>
class Node{
public:
	T data;
	Node *link;
	Node(T element){
		data = element;
		link = 0; 
	}
};

template <class T>
// Linked List Class
class LinkedList
{
protected:
	Node<T> *first;
	int current_size;
public:
	LinkedList(){
		first = 0;
		current_size = 0; 
	}

	int GetSize() { 
		return current_size; 
	} // ��� ������ ����

	void Insert(T element){
		Node<T> *newnode = new Node<T>(element);
		newnode->link = first;
		first = newnode;
		current_size++;	
	} // �� �տ� ���Ҹ� ����

	virtual bool Delete(T &element){
		if(first == 0) 
			return false;
		Node<T> *current = first, *previous = 0;
		while(1){ // ������ ������ ã�ư��� �ݺ���
			if(current->link == 0) // find end node
			{
				if(previous) previous->link = current->link;
				else first = first->link;
				break;
			}
			previous = current;
			current = current->link;
		}
		element = current->data;
		delete current;
		current_size--;
		return true;
	} // �� ���� ���Ҹ� ����

	void Print(){
		int i;
		Node<T> *current = first;

		for(i=0;i<current_size;i++)
		{
			cout << "[" << i+1 << "|" << current->data << "]";
			if(i<current_size-1)
				cout << "->";
			current = current->link;
		}
		
		if(current_size>0)
			cout << endl;
	} // ����Ʈ�� ���
};
#endif

