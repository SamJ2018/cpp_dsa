#pragma once
#include "vector.h"

/*归并排序，主体使用典型的分而治之策略，递归描述如下*/
template<typename T> //向量的归并排序
void Vector<T>::mergeSort(Rank lo, Rank hi) //0<=lo<hi<=size
{
	if (hi - lo < 2) return; //递归基，单元素区间自然有序
	int mi = (hi - lo) >> 1;  //以中点为界
	mergeSort(lo, mi);  //对前
	mergeSort(mi, hi);	//后段排序，然后
	merge(lo, mi, hi);	//合并
}