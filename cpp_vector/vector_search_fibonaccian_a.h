#pragma once
#include "vector.h"
#include "../cpp_fibonacci/fib.h"  //fibonacci������

//fibonacci�����㷨(version A):����������������[lo,hi)�ڲ���Ԫ��e, 0<=lo<=hi<=_size;
template<typename T>
static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi)
{
	Fib fib(hi - lo);   //��O(log_phi(n=hi-lo)) ʱ�䴴��Fib����
	while (lo < hi)
	{  //ÿ�ε�����Ҫ�����αȽ��жϣ���������֧
		while (hi - lo < fib.get())  
			fib.prev();  //��ǰ˳�����

		Rank mi = lo + fib.get() - 1;   //ȷ��fib(k)-1����㣬��"�ƽ�ָ��"
		if (e < A[mi]) hi = mi;   //����[lo,mi)
		else if (A[mi] < e) lo = mi + 1;   //��������(mi,hi)
		else return mi;   //����
	}//�ɹ����ҿ���ǰ��ֹ
	return -1;  //����ʧ��
}//�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�
//ȱ�㣺ʧ��ʱ���򵥷���-1������ָʾʧ�ܵ�λ��