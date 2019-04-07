#pragma once
#include "List.h"

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{
	_size++;
	return header->insertAsSucc(e);  //e当作首节点插入
}

template <typename T> ListNodePosi(T) List<T>::insertAsLast(T const& e)
{
	_size++;
	return trailer->insertAsPred(e);  //e当作末节点插入
}

template<typename T> ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T const& e)
{
	//e当作p的前驱插入
	_size++;
	return p->insertAsPred(e);
}

template<typename T> ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const& e)
{
	_size++;  //e当作p的后继插入
	return p->insertAsSucc(e); 
}