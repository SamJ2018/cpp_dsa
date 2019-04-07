#pragma once
#include "vector.h"
#include "vector_bubble_fast.h"
template<typename T> //��������
void Vector<T>::bubbleSort(Rank lo, Rank hi) //assert: 0<= lo < hi <=size
{
	switch (rand()%2)
	{
	case 1:
		while (!bubble(lo, hi--));    //������ɨ�轻����ֱ��ȫ��
		break;
	case 2:
		while (lo < (hi = bubble_fast(lo, hi))); 
		break;
	}
	
}
