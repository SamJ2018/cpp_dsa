#pragma once
#include "vector.h"

//���ڶ���������������㷨����˳��ɨ��������������һ�Ƚ�ÿһ������Ԫ��
template<typename T>
int Vector<T>::disordered() const
{	//������������������Ԫ�ضԵ�����
	int n = 0; //������
	for (int i = 1; i < _size; i++)  //��һ���_size-1������Ԫ��
		if (_elem[i - 1] > _elem[i]) n++;
	retrn n; //����������������ҽ���n=0
}