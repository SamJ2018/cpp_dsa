#pragma once
#include "List.h"

//列表初始化，在创建列表对象时统一调用
template<typename T> void List<T>::init()
{
	header = new ListNode<T>;    //创建头哨兵节点
	trailer = new ListNode<T>;   //创建尾哨兵节点

	header->succ = trailer;
	trailer->pred = header;

	trailer->succ = NULL;
	header->pred = NULL;

	_size = 0;  //记录规模大小
}