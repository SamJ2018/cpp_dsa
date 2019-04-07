#pragma once
#include "List.h"

//剔除无序列表中的重复节点
template<typename T> int List<T>::deduplicate()
{	
	if (_size < 2) return 0;       //规模为1时为平凡情况，无重复
	int oldSize = _size;           //记录原规模，用于后续计算删除元素的个数
	ListNodePosi(T) p = header;    //p从首节点开始
	Rank r = 0;   

	while (trailer != (p = p->succ))    //依次遍历到末节点
	{
		ListNodePosi(T) q = find(p->data, r, p);  //在p的r个(真)前驱中查找雷同者
		q ? remove(q) : r++;     //存在相同的元素则删除，否则继续遍历
	}//assert:循环过程中的任意时刻，p的所有前驱互不相同
	return oldSize - _size;  //列表规模变化量，即被删除元素总数
}