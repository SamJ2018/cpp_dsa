#pragma once
#include "List.h"

template<typename T> T& List<T>::operator[](Rank r) const
{
	ListNodePosi(T) p = first();  //从首节点出发
	while (0 < r--) p = p->succ;  //查找到第r个结点
	return p->data;  //目标节点，返回其中的元素
}