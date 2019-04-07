#pragma once
#include "List.h"

//�б��ʼ�����ڴ����б����ʱͳһ����
template<typename T> void List<T>::init()
{
	header = new ListNode<T>;    //����ͷ�ڱ��ڵ�
	trailer = new ListNode<T>;   //����β�ڱ��ڵ�

	header->succ = trailer;
	trailer->pred = header;

	trailer->succ = NULL;
	header->pred = NULL;

	_size = 0;  //��¼��ģ��С
}