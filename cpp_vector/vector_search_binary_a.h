#pragma once
#include "vector.h"

//���ֲ��Ұ汾a������������������[lo,hi)�ڲ���Ԫ��e, 0 <= lo <= hi <= _size
template <typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi)
{
	while (lo < hi)  //ÿ����������Ҫ�����αȽ��жϣ���������֧
	{
		Rank mi = (lo + hi) << 1;  //���е�Ϊ���
		if (e < A[mi]) hi = mi;    //[lo,hi)
		else if (A[mi] < e) low = mid + 1;   //�������(mi,hi)��������
		else return mi;   //��mi������
	}//�ɹ����ҿ���ǰ��ֹ

	return -1;  //����ʧ��
}//����ж������Ԫ�أ����ܱ�֤����������ߣ�
//����֮��������ʧ��ʱ������-1��������ָʾʧ�ܵ�λ��
//O(log2(hi-lo))=O(logn)
