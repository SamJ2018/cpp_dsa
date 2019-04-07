#pragma once
#include "vector.h"

template <typename T> T& Vector<T>::operator[](Rank r) const //重载下标操作符
{   //作为左值和右值，可代替set()和get()操作
	return  _elem[r];  //assert: 0<= r < _size
}