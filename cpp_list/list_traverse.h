#pragma once
#include "List.h"

template <typename T> void List<T>::traverse(void(*visit)(T&))
{   //���ú���ָ����Ƶı���
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
		visit(p->data);
}

template<typename T> template<typename VST> //Ԫ�����͡�������
void List<T>::traverse(VST& visit) //���ú���������Ƶı���
{
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
		visit(p->data);
}