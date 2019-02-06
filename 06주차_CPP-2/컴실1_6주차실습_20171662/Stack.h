#include "LinkedList.h"

template <class T>
class Stack : public LinkedList<T>{
public:
	virtual bool Delete(T &element){
		if(this->first == 0) 
			return false;
		Node<T> *current = this->first;
		this->first = current->link;
		element = current->data;
		delete current;
		this->current_size--;
		return true;
	} // 맨 앞의 원소를 삭제 	
};