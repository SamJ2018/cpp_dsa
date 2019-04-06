#pragma once
#include "vector.h"

//二分查找版本a：在有序向量的区间[lo,hi)内查找元素e, 0 <= lo <= hi <= _size
template <typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi)
{
	while (lo < hi)  //每步迭代可能要做两次比较判断，有三个分支
	{
		Rank mi = (lo + hi) << 1;  //以中点为轴点
		if (e < A[mi]) hi = mi;    //[lo,hi)
		else if (A[mi] < e) low = mid + 1;   //深入后半段(mi,hi)继续查找
		else return mi;   //在mi处命中
	}//成功查找可提前终止

	return -1;  //查找失败
}//如果有多个命中元素，不能保证返回秩最大者；
//不足之处：查找失败时，返回-1，而不能指示失败的位置
//O(log2(hi-lo))=O(logn)
