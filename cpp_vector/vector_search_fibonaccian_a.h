#pragma once
#include "vector.h"
#include "../cpp_fibonacci/fib.h"  //fibonacci数列类

//fibonacci查找算法(version A):在有序向量的区间[lo,hi)内查找元素e, 0<=lo<=hi<=_size;
template<typename T>
static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi)
{
	Fib fib(hi - lo);   //用O(log_phi(n=hi-lo)) 时间创建Fib数列
	while (lo < hi)
	{  //每次迭代需要做两次比较判断，有三个分支
		while (hi - lo < fib.get())  
			fib.prev();  //向前顺序查找

		Rank mi = lo + fib.get() - 1;   //确定fib(k)-1的轴点，即"黄金分割的"
		if (e < A[mi]) hi = mi;   //查找[lo,mi)
		else if (A[mi] < e) lo = mi + 1;   //继续查找(mi,hi)
		else return mi;   //命中
	}//成功查找可提前终止
	return -1;  //查找失败
}//有多个命中元素时，不能保证返回秩最大者；
//缺点：失败时，简单返回-1，不能指示失败的位置