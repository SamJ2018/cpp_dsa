#pragma once
#include "vector.h"

/*ð������汾B*/
template<typename T>
Rank Vector<T>::bubble_fast(Rank lo, Rank hi)//һ��ɨ�轻��
{
	Rank last = lo;  //���Ҳ������Գ�ʼΪ[lo-1,lo]
	while(++lo<hi) //�������ң���һ����������Ԫ��
		if (_elem[lo - 1] > _elem[lo]) //���������
		{
			last = lo; //�������Ҳ������λ�ü�¼������
			Swap(_elem[lo - 1], _elem[lo]); //ͨ������ʹ�þֲ�����
		}
	return last; //ֱ�Ӵ�[lo,last)����
}

