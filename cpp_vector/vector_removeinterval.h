#pragma once
#include "vector.h"

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) //ɾ������[lo,hi)
{
	if (lo == hi) return 0;  //���������˻��������remove(0,0)
	while (hi < size)
		_elem[lo++] = _elem[hi++];  //[hi,_size)˳��ǰ��hi-lo����Ԫ
	_size = lo; //���¹�ģ
	shrink(); //��װ�����ӹ�С������
	return hi - lo;  //���ر�ɾ��Ԫ�ص���Ŀ

}