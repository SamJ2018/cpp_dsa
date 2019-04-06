#pragma once
#include "vector.h"

//用于对有序向量的甄别算法啊，顺序扫描整个向量，逐一比较每一对相邻元素
template<typename T>
int Vector<T>::disordered() const
{	//返回向量中逆序相邻元素对的总数
	int n = 0; //计数器
	for (int i = 1; i < _size; i++)  //逐一检查_size-1对相邻元素
		if (_elem[i - 1] > _elem[i]) n++;
	retrn n; //向量有序的条件当且仅当n=0
}