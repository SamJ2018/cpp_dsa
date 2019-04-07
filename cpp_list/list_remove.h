#pragma once
#include "List.h"

/*���б���ɾ��ָ���ڵ�p���㷨*/
template <typename T> T List<T>::remove(ListNodePosi(T) p)  //ɾ���Ϸ�λ��p���ڵ㣬��������ֵ
{
	T e = p->data;  //����T���Ϳ���ֱ�Ӹ�ֵ����������
	p->pred->succ = p->succ; //�ֱ�ı���
	p->succ->pred = p->pred; //ǰ���ڵ�

	delete p;    //�ͷŽڵ㣬��
	_size--;     //���¹�ģ
	return e;    //����ɾ������
} //�������ڱ��ڵ㣬ɾ���κνڵ������������������  O(1)

