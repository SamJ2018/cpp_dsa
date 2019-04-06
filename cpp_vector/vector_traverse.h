#pragma once
#include "vector.h"

template<typename T>
void Vector<T>::traverse(void(*visit)(T&)) //利用函数指针
{
	for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template<typename T>
template<typename VST> //元素类型、操作器
void Vector<T>::traverse(VST& visit)  //利用函数对象机制遍历
{
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}