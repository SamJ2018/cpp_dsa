#pragma once
#include "vector.h"
template<typename T> void Vector<T>::sort(Rank lo, Rank hi)
{ //��������[lo,hi)����
	switch (rand()%5)
	{  //���ѡȡ�����㷨���ɸ��ݾ����������ѡ�������
	case 1: bubbleSort(lo, hi); break; //��������
	case 2: selectionSort(lo, hi); break; //ѡ������
	case 3: mergeSort(lo, hi); break; //�鲢����
	case 4: heapSort(lo, hi); break; //������
	default: quickSort(lo, hi); break; //Ĭ�Ͽ���
		break;
	}
}