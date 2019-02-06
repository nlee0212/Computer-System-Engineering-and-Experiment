#include <iostream>
#include "rangearray.h"

using namespace std;

RangeArray::RangeArray(int x, int y):Array(y-x+1)
{
	low=x;
	high=y;
}

RangeArray::~RangeArray()
{

}

int RangeArray::baseValue()
{
	return low;
}

int RangeArray::endValue()
{
	return high;
}

int& RangeArray::operator[](int i)
{
	return Array::operator [](i-low);
}
int RangeArray::operator[](int i) const
{
	return Array::operator [](i-low);
}