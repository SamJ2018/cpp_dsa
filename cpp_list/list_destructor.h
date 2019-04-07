#pragma once
#include "List.h"
/*�������������б���ռ�õ���Դ�黹������ϵͳ*/

template <typename T> List<T>::~List()
{
	clear();          //����б�
	delete header;    //�ͷ�ͷ��
	delete trailer;   //β�ڱ��ڵ�
}

//����б�
template<typename T> int List<T>::clear()
{
	int oldSize = _size;
	while (0 < _size)
		remove(header->succ);  //����ɾ���׽ڵ㣬ֱ���б���

	return oldSize;
}
//���ĵ�ʱ����Ҫ��clear()������ͨ��remove()�ӿڷ���ɾ���б���׽ڵ㣬���ʱ�临�Ӷ�ΪO(n)
