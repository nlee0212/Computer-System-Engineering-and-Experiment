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
	} // 노드 개수를 리턴

	void Insert(T element){
		Node<T> *newnode = new Node<T>(element);
		newnode->link = first;
		first = newnode;
		current_size++;	
	} // 맨 앞에 원소를 삽입

	virtual bool Delete(T &element){
		if(first == 0) 
			return false;
		Node<T> *current = first, *previous = 0;
		while(1){ // 마지막 노드까지 찾아가는 반복문
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
	} // 맨 뒤의 원소를 삭제

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
	} // 리스트를 출력
};
#endif

