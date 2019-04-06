#pragma once
#include "vector.h"
template<typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{  //等概率随机置乱向量区间[lo,hi)
	T* V = _elem + lo;  //将子向量_elem[lo,hi)看成是另一向量V[0,hi-lo)
	for (Rank i = hi - lo; i > 0; i--) {} //自前向后
		//swap(V[i-1],V[rand()%i]);  //将V[i-1]与V[0,i)某一元素随机交换
}