#pragma once
#include "vector.h"
/*ɾ�������������ظ�Ԫ��(������)*/
template <typename T> 
int Vector<T>::deduplicate()
{	
	int oldSize = _size;  //��¼ԭ��ģ
	int i = -1; //����ǰ�˿�ʼ

	while (++i < _size - 1)
	{ //��ǰ���ע��ɨ��
		int j = i + 1;  //assert:_elem[0,i]�в����ظ�Ԫ��
		while (j < _size)
			if (_elem[i] == _elem[j])
				remove(j);  //����ͬ��ɾ��
			else
				j++;  //����ɨ��
	}//while
	return oldSize - size;  //������ģ�仯��������ɾ��Ԫ������
}