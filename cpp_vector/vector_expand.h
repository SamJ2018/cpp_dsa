#pragma once
#include "vector.h"

template<typename T>
void Vector<T>::expand()  //�����ռ䲻��ʱ�Զ�����
{
	if (_size < _capacity) return;   //�ռ仹û��
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;  //��������С����
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];  //������������

	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];   //����ԭ������������(TΪ�������ͣ������Ѿ�������"="�����)

	delete[] oldElem;   //�ͷ�ԭ�ռ�
}//ʹ��insert()ǰ����ȵ��ô˷�������ֹ����