#pragma once
#include "vector.h"

/*�鲢��������ʹ�õ��͵ķֶ���֮���ԣ��ݹ���������*/
template<typename T> //�����Ĺ鲢����
void Vector<T>::mergeSort(Rank lo, Rank hi) //0<=lo<hi<=size
{
	if (hi - lo < 2) return; //�ݹ������Ԫ��������Ȼ����
	int mi = (hi - lo) >> 1;  //���е�Ϊ��
	mergeSort(lo, mi);  //��ǰ
	mergeSort(mi, hi);	//�������Ȼ��
	merge(lo, mi, hi);	//�ϲ�
}