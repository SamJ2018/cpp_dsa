#pragma once
#include "vector.h"

/*冒泡排序版本B*/
template<typename T>
Rank Vector<T>::bubble_fast(Rank lo, Rank hi)//一趟扫描交换
{
	Rank last = lo;  //最右侧的逆序对初始为[lo-1,lo]
	while(++lo<hi) //自左向右，逐一检查各对相邻元素
		if (_elem[lo - 1] > _elem[lo]) //存在逆序对
		{
			last = lo; //更新最右侧逆序对位置记录，并且
			Swap(_elem[lo - 1], _elem[lo]); //通过交换使得局部有序
		}
	return last; //直接从[lo,last)找起
}

