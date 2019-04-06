#pragma once
#include "vector.h"

template<typename T> 
int Vector<T>::deduplicate()
{ //ɾ�������������ظ�Ԫ��(��Ч��)
	int oldSize = _size; //��¼ԭ����ģ
	Rank i = 1;  //��_elem[1]��ʼ

	while (i < _size)  //��ǰ�����һ�����Ԫ��_elem[i]
		(find(_elem[i], 0, i) < 0) ? i++ : remove(i); //��ǰ׺��Ѱ����ͬ��(���һ��),�ҵ�ɾ��

	return oldSize - _size;  //���ر�ɾ��Ԫ�صĸ���
}