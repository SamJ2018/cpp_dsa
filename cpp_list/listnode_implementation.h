#pragma once
#include "ListNode.h"

//��e���뵱ǰ�ڵ�֮ǰ,��Ϊ���ڱ��ڵ㣬��ʹ��ǰ�ڵ�Ϊ�׽ڵ㣬ǰ��Ҳ����
template<typename T> ListNodePosi(T) ListNode<T>::insertAsPred(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, pred, this); //x��ǰ�����ӵ���ǰ�ڵ��ǰ����㣬x�ĺ�����ӵ���ǰ�ڵ�
	pred->succ = x;  
	pred = x;  //��ǰ�ڵ�ǰ�����ӵ�x
	return x;  //�����½ڵ�λ��
}

//��e���뵱ǰ�ڵ�֮��
template<typename T> ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, this, succ); //�����½ڵ�
	succ->pred = x;  //����
	succ = x; //����ڵ��λ

	return x; //�����½ڵ�λ��
}
//�����������������漰�ֲ�����ԭ�н�㣬��һ���½�� ���Ҳ����ݹ������������赱ǰ�ڵ��Ѿ���λ��������
//��ǰ���������ĵ�ʱ�䣬 ��������ڳ���ʱ�������

