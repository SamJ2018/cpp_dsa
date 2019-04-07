#pragma once
#include "vector.h"

/*�汾A ����ɨ�轻��*/
template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi)
{  //һ��ɨ�轻��
	bool sorted = true;  //���������־
	while (++lo < hi) //�������ң���һ����������Ԫ��
	{
		if (_elem[lo - 1] > _elem[lo])//��������ԣ�����
		{
			sorted = false;//��ζ����δ��������
			Swap(_elem[lo - 1], _elem[lo]);  //ͨ������ʹ�þֲ�����
		}
	}
	return sorted;  //���ر�־λ
}