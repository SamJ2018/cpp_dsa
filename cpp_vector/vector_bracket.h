#pragma once
#include "vector.h"

template <typename T> T& Vector<T>::operator[](Rank r) const //�����±������
{   //��Ϊ��ֵ����ֵ���ɴ���set()��get()����
	return  _elem[r];  //assert: 0<= r < _size
}