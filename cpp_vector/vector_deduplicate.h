#pragma once
#include "vector.h"

template<typename T> 
int Vector<T>::deduplicate()
{ //删除无序向量中重复元素(高效版)
	int oldSize = _size; //记录原来规模
	Rank i = 1;  //从_elem[1]开始

	while (i < _size)  //自前向后逐一考查各元素_elem[i]
		(find(_elem[i], 0, i) < 0) ? i++ : remove(i); //在前缀中寻找雷同的(最多一个),找到删除

	return oldSize - _size;  //返回被删除元素的个数
}