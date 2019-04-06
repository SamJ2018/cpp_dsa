#pragma once
#include "vector.h"

//有序向量重复元素剔除算法(低效版)
template<typename T>
int uniquify_slow()
{
	int oldSize = _size;
	int i = 1;  //当前元素的秩，起始于首元素
	while (i < _size)
		_elem[i - 1] == _elem[i] ? remove(i) : i++;  //若相同删除后者，否者继续遍历
	return oldSize - _size; //返回被删除元素总数
}//性能分析：如果存在大量重复元素，则时间复杂度取决于后续的元素个数，与未排序时的时间复杂度相同O(n^2)

