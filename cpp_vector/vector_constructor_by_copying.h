#pragma once
#include "vector.h"
template<typename T> //模板类
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
	_elem = new T[_capacity = (hi - lo) * 2]; //以数组区间A[lo,hi]为蓝本复制向量
	_size = 0; //分配空间，规模清零
	while (lo < hi)  //遍历A[lo,hi)内元素
		_elem[_size++] = A[lo++];   //复制到_elem[0,hi-lo)
}