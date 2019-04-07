#pragma once
#include "vector.h"
template<typename T> //ģ����
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
	_elem = new T[_capacity = (hi - lo) * 2]; //����������A[lo,hi]Ϊ������������
	_size = 0; //����ռ䣬��ģ����
	while (lo < hi)  //����A[lo,hi)��Ԫ��
		_elem[_size++] = A[lo++];   //���Ƶ�_elem[0,hi-lo)
}