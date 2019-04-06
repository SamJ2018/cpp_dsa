#pragma once
#include "vector.h"

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) //删除区间[lo,hi)
{
	if (lo == hi) return 0;  //单独处理退化情况，如remove(0,0)
	while (hi < size)
		_elem[lo++] = _elem[hi++];  //[hi,_size)顺次前移hi-lo个单元
	_size = lo; //更新规模
	shrink(); //若装填因子过小，缩容
	return hi - lo;  //返回被删除元素的数目

}