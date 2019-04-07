#pragma once
#include "vector.h"

/*二分查找(版本B)*/
//算法在每步迭代中(或递归层次上)，都只有两个分支方向，而不再是三个！ (基于减秩策略的有序向量的二分查找算法)
//注意：若目标元素小于A[mi]，则深入前端子项量A[lo,mi)继续查找，否则深入后端子向量[mi,hi)，而不再探讨mi
template <typename T>
static Rank binSearch(T* A, T const& e, Rank lo, Rank hi)
{
	//每步迭代仅需做一次比较判断，有两个分支；成功查找不能提前终止
	while (1 < hi - lo)
	{
		Rank mi = (lo + hi) >> 1;  //以中点为轴点
		(e < A[mi]) ? hi = mi : lo = mi;  //经过比较，确定深入[lo,mi)或[mi,hi)
	}//出口时hi=lo+1,查找区间仅剩下一个元素A[lo] ,注意范围[lo,hi)
	return(e == A[lo]) ? lo : -1;  //while循环结束后，A[lo]必为所找元素，否则不存在返回-1
}
//版本B仍然存在缺陷： 1、有多个命中的元素时，不能保证返回的是秩最大的元素。2、查找失败时只能简单返回-1，不能指示失败的位置

