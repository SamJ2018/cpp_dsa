#pragma once
#include "List.h"

template<typename T> T& List<T>::operator[](Rank r) const
{
	ListNodePosi(T) p = first();  //���׽ڵ����
	while (0 < r--) p = p->succ;  //���ҵ���r�����
	return p->data;  //Ŀ��ڵ㣬�������е�Ԫ��
}