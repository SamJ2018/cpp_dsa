#pragma once
#include "vector.h"

template<typename T>
void Vector<T>::traverse(void(*visit)(T&)) //���ú���ָ��
{
	for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template<typename T>
template<typename VST> //Ԫ�����͡�������
void Vector<T>::traverse(VST& visit)  //���ú���������Ʊ���
{
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}