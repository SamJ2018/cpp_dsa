#pragma once
#include "vector.h"
/*删除无序向量中重复元素(繁琐版)*/
template <typename T> 
int Vector<T>::deduplicate()
{	
	int oldSize = _size;  //记录原规模
	int i = -1; //从最前端开始

	while (++i < _size - 1)
	{ //从前向后，注意扫描
		int j = i + 1;  //assert:_elem[0,i]中不含重复元素
		while (j < _size)
			if (_elem[i] == _elem[j])
				remove(j);  //若相同，删除
			else
				j++;  //继续扫描
	}//while
	return oldSize - size;  //向量规模变化量，即被删除元素总数
}