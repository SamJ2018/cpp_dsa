#pragma once
#include "List.h"

//�޳������б��е��ظ��ڵ�
template<typename T> int List<T>::deduplicate()
{	
	if (_size < 2) return 0;       //��ģΪ1ʱΪƽ����������ظ�
	int oldSize = _size;           //��¼ԭ��ģ�����ں�������ɾ��Ԫ�صĸ���
	ListNodePosi(T) p = header;    //p���׽ڵ㿪ʼ
	Rank r = 0;   

	while (trailer != (p = p->succ))    //���α�����ĩ�ڵ�
	{
		ListNodePosi(T) q = find(p->data, r, p);  //��p��r��(��)ǰ���в�����ͬ��
		q ? remove(q) : r++;     //������ͬ��Ԫ����ɾ���������������
	}//assert:ѭ�������е�����ʱ�̣�p������ǰ��������ͬ
	return oldSize - _size;  //�б��ģ�仯��������ɾ��Ԫ������
}