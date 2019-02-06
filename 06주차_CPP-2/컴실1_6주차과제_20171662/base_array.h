#ifndef __ARRAY__
#define __ARRAY__

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class Array {
protected:
	T *data;
	int len;
public:
	Array(int size)
	{
		if (size<0)
		{
			cout << "Array bound error!" << endl;
		}
		else
		{
			data = new T[size];
			len = size;
		}
	}

	~Array() {
		delete[] data;
	}

	int length() const {
		return len;
	}

	virtual T& operator[](int i) {
		static T tmp;

		if (i >= 0 && i < len)
		{
			return data[i];
		}

		else
		{
			cout << " Array bound error!" << endl;
			return tmp;
		}
	}

	virtual T operator[](int i) const {
		if (i >= 0 && i < len)
		{
			return data[i];
		}

		else
		{
			cout << " Array bound error!" << endl;
			return 0;
		}
	}

	void print() {
		int i;

		cout << " [";
		for (i = 0;i<len;i++)
		{
			if (i<len - 1)
				cout << data[i] << " ";
			else
				cout << data[i] << "]" << endl;
		}
	}
};
#endif