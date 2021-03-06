#pragma once
#include "vector.h"
//针对有序向量的二路归并算法
template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{  //以mi为界、各自有序的子向量[lo,mi)和[mi,hi)
	T* A = _elem + lo;  //合并后的向量A[0,hi-lo)=_elem[lo,hi)
	int lb = mi - lo;  //前子向量B[0,lb)=_elem[lo,mi)
	T* B = new T[lb]; 
	for (Rank i = 0; i < lb; B[i] = A[i++]);  //复制前子向量
	
	//后子向量
	int lc = hi - mi;
	T* C = _elem + mi;  //后子向量C[0,lc)=_elem[mi,hi)
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
	{//将B[j]和C[k]中较小者续接到A末尾
		if ((j < lb) && (!(k < lc) || B[j] <= C[k])) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || C[k] < B[j]))  A[i++] = C[k++];
	}
	delete[] B; //释放临时空间B
}//归并后的到完整的有序向量[lo,hi)