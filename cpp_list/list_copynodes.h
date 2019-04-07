#pragma once
#include "List.h"
//copyNodes()
/*  �б���ڲ��ṹ��Ҫ��̬���������ʹ��Ĭ�ϵĹ��췽������������б�ĸ��ƴ���
	��Ҫר�ű�д��Ӧ�Ĺ��췽����ͨ������ĳһ�����б����������б�
*/

template<typename T> //�б��ڲ������������б�����λ��p���n��
void List<T>::copyNodes(ListNodePosi(T) p, int n)  //p�Ϸ�����������n-1�����̽ڵ�
{
	init();  //����ͷ��β�ڱ��ڵ㲢����ʼ��
	while (n--)
	{
		insertAsLast(p->data);
		p = p->succ;  //������p��n��������Ϊĩ�ڵ����
	}
}//O(n+1)