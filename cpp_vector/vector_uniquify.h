#pragma once
#include "vector.h"

//有序向量重复元素剔除算法(高效版)
template <typename T>int Vector<T>::uniquify()
{
	Rank i = 0, j = 0;  //"相邻"元素的秩
	while (++j < _size)  //如果_size=1,则不需要去除重复元素
		if (_elem[i] != _elem[j]) //跳过雷同的
			_elem[++i] = _elem[j];  //若发现不同元素，向前移至相邻于前者的右侧
	_size = ++i;
	shrink();  //截取尾部多余元素
	return j - i;  //返回被删除元素总数
}//O(n) j最多需要迭代n次