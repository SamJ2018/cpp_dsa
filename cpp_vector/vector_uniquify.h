#pragma once
#include "vector.h"

//���������ظ�Ԫ���޳��㷨(��Ч��)
template <typename T>int Vector<T>::uniquify()
{
	Rank i = 0, j = 0;  //"����"Ԫ�ص���
	while (++j < _size)  //���_size=1,����Ҫȥ���ظ�Ԫ��
		if (_elem[i] != _elem[j]) //������ͬ��
			_elem[++i] = _elem[j];  //�����ֲ�ͬԪ�أ���ǰ����������ǰ�ߵ��Ҳ�
	_size = ++i;
	shrink();  //��ȡβ������Ԫ��
	return j - i;  //���ر�ɾ��Ԫ������
}//O(n) j�����Ҫ����n��