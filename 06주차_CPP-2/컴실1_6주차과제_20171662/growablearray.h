#include "base_array.h"

template <class T>
class GrowableArray : public Array<T> {
public:
	GrowableArray(int x) : Array<T>(x) {}
	~GrowableArray() {}

	virtual T& operator[](int i) {
		if (i >= this->len)
		{
			int tmplen = i * 2;
			T* tmp;
			tmp = new T[tmplen];

			for (int j = 0; j<tmplen; j++)
				tmp[j] = 0;

			for (int j = 0; j<(this->len); j++)
				tmp[j] = (this->data)[j];

			delete[] (this->data);
			this->data = tmp;
			this->len = tmplen;
		}

		return Array<T>::operator[](i);
	}

	virtual T operator[](int i) const {

		return Array<T>::operator[](i);
	}
};