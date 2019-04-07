#pragma once
#include "vector.h"
//������������Ķ�·�鲢�㷨
template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{  //��miΪ�硢���������������[lo,mi)��[mi,hi)
	T* A = _elem + lo;  //�ϲ��������A[0,hi-lo)=_elem[lo,hi)
	int lb = mi - lo;  //ǰ������B[0,lb)=_elem[lo,mi)
	T* B = new T[lb]; 
	for (Rank i = 0; i < lb; B[i] = A[i++]);  //����ǰ������
	
	//��������
	int lc = hi - mi;
	T* C = _elem + mi;  //��������C[0,lc)=_elem[mi,hi)
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
	{//��B[j]��C[k]�н�С�����ӵ�Aĩβ
		if ((j < lb) && (!(k < lc) || B[j] <= C[k])) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || C[k] < B[j]))  A[i++] = C[k++];
	}
	delete[] B; //�ͷ���ʱ�ռ�B
}//�鲢��ĵ���������������[lo,hi)