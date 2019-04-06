#pragma once
#include "vector.h"

template<typename T>
void Vector<T>::expand()  //向量空间不足时自动扩容
{
	if (_size < _capacity) return;   //空间还没满
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;  //不低于最小容量
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];  //容量扩充两倍

	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];   //复制原来向量的内容(T为基本类型，或者已经重载了"="运算符)

	delete[] oldElem;   //释放原空间
}//使用insert()前最好先调用此方法，防止上溢