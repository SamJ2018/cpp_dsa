#pragma once
#include "vector.h"
#include "vector_search_binary_c.h"
#include "vector_search_fibonaccian_b.h"
//区别于无序向量,使用search接口
template<typename T> //在有序向量的区间[lo,hi)内，确定不大于e的最后一个结点的秩
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const
{//assert: 0<= lo <hi <= _size
	//按概率随机使用二分查找或斐波那契查找
	return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}