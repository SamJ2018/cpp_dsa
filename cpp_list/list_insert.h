#pragma once
#include "List.h"

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{
	_size++;
	return header->insertAsSucc(e);  //e�����׽ڵ����
}

template <typename T> ListNodePosi(T) List<T>::insertAsLast(T const& e)
{
	_size++;
	return trailer->insertAsPred(e);  //e����ĩ�ڵ����
}

template<typename T> ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T const& e)
{
	//e����p��ǰ������
	_size++;
	return p->insertAsPred(e);
}

template<typename T> ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const& e)
{
	_size++;  //e����p�ĺ�̲���
	return p->insertAsSucc(e); 
}