#pragma once
#include "vector.h"

template<typename T>
void Vector<T>::shrink()
{//װ�����ӹ�С��ѹ���ռ�
	if (_capacity < DEFAULT_CAPACITY << 1) return;  //������������DEFAULT_CAPACITY����
	if (_size << 2 > _capacity) return;   //װ�����ӳ���25%�Ͳ�������
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];  //ԭ������������
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];  //����ԭ��������
	delete[] oldElem;  //�ͷſռ�
}