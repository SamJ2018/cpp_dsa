#pragma once
#include "vector.h"

template<typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi)const //无序向量顺序查找:返回最后一个元素e的位置，失败返回lo-1;
{	//assert: 0 <= lo< hi <= _size
	while ((lo < hi--) && (e != _elem[hi])); //从后向前，顺序查找。短路特性，不会越界
	return hi;  //hi<lo 查找失败，否则hi即为所求
}//因为希望多个元素匹配时返回最大者，因此从后向前遍历
//O(n)  --输入敏感

