#pragma once
#include "vector.h"
#include "vector_search_binary_c.h"
#include "vector_search_fibonaccian_b.h"
//��������������,ʹ��search�ӿ�
template<typename T> //����������������[lo,hi)�ڣ�ȷ��������e�����һ��������
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const
{//assert: 0<= lo <hi <= _size
	//���������ʹ�ö��ֲ��һ�쳲���������
	return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}