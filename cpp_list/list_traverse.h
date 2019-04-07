#pragma once
#include "List.h"

template <typename T> void List<T>::traverse(void(*visit)(T&))
{   //利用函数指针机制的遍历
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
		visit(p->data);
}

template<typename T> template<typename VST> //元素类型、操作器
void List<T>::traverse(VST& visit) //利用函数对象机制的遍历
{
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
		visit(p->data);
}