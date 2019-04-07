#pragma once
#include "vector.h"

/*版本A 单趟扫描交换*/
template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi)
{  //一趟扫描交换
	bool sorted = true;  //整体有序标志
	while (++lo < hi) //自左向右，逐一检查各对相邻元素
	{
		if (_elem[lo - 1] > _elem[lo])//发现逆序对，交换
		{
			sorted = false;//意味着尚未整体有序，
			Swap(_elem[lo - 1], _elem[lo]);  //通过交换使得局部有序
		}
	}
	return sorted;  //返回标志位
}