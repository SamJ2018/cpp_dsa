#pragma once
#include "vector.h"

template<typename T> //将e作为秩为r的元素插入
Rank Vector<T>::insert(Rank r, T const& e)  //assert: 0<= r <=size
{
	expand();//若空间不足，扩容
	for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1]; //自后向前，后继顺次后移一个单元
	_elem[r] = e;
	_size++;  //更新规模
	return r;
}