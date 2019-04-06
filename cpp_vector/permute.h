#pragma once
#include "vector.h"
template<typename T> void permute(Vector<T>& V)
{ //随机置乱向量，使各元素等概率出现在每一位置
	for (int i = V.size(); i > 0; i--) {}//自后向前
		//swap(V[i-1],V[rand()%i];)  //V[i-1]与V[0,i)中某一随机元素交换
		//这里的swap隐含了基于三次重载[]的操作
}