#pragma once
#include "vector.h"

//���������ظ�Ԫ���޳��㷨(��Ч��)
template<typename T>
int uniquify_slow()
{
	int oldSize = _size;
	int i = 1;  //��ǰԪ�ص��ȣ���ʼ����Ԫ��
	while (i < _size)
		_elem[i - 1] == _elem[i] ? remove(i) : i++;  //����ͬɾ�����ߣ����߼�������
	return oldSize - _size; //���ر�ɾ��Ԫ������
}//���ܷ�����������ڴ����ظ�Ԫ�أ���ʱ�临�Ӷ�ȡ���ں�����Ԫ�ظ�������δ����ʱ��ʱ�临�Ӷ���ͬO(n^2)

