#pragma once
#include "vector.h"

template<typename T> //��e��Ϊ��Ϊr��Ԫ�ز���
Rank Vector<T>::insert(Rank r, T const& e)  //assert: 0<= r <=size
{
	expand();//���ռ䲻�㣬����
	for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1]; //�Ժ���ǰ�����˳�κ���һ����Ԫ
	_elem[r] = e;
	_size++;  //���¹�ģ
	return r;
}