#pragma once
#include "List.h"
/*析构函数，将列表所占用的资源归还给操作系统*/

template <typename T> List<T>::~List()
{
	clear();          //清空列表
	delete header;    //释放头、
	delete trailer;   //尾哨兵节点
}

//清空列表
template<typename T> int List<T>::clear()
{
	int oldSize = _size;
	while (0 < _size)
		remove(header->succ);  //反复删除首节点，直至列表变空

	return oldSize;
}
//消耗的时间主要是clear()操作，通过remove()接口反复删除列表的首节点，因此时间复杂度为O(n)
