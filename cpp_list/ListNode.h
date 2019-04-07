#include <stdlib.h>
/*
	�б���ӿ�
	�����ӿ�						  ����
	1��data()				��ǰ����������ݶ���
	2��pred()				��ǰ���ǰ������λ��
	3��succ()				��ǰ����̽���λ��
	4��insertAsPred(e)		����ǰ����㣬���뱻���ö���e�������½��λ��
	5��insertAsSucc(e)		�����̽�㣬���뱻���ö���e�������½��λ��
*/

typedef int Rank;  //��
#define ListNodePosi(T) ListNode<T>*  //�б���λ��

//�б���ģ����(��˫��������ʽʵ��)
template <typename T> struct ListNode
{
	//��Ա
	T data;  //����
	ListNodePosi(T) pred; //ǰ��
	ListNodePosi(T) succ; //���

	//���캯��
	ListNode() {}  //���header��trailer�Ĺ���
	//��Ա��ֵ����δ��ֵ����ΪNULL
	ListNode(T e, ListNodePosi(T) p=NULL, ListNodePosi(T) s=NULL):data(e),pred(p),succ(s){}

	//�ӿڲ���
	ListNodePosi(T) insertAsPred(T const& e);  //������ǰ�ڵ�֮ǰ�����½ڵ�
	ListNodePosi(T) insertAsSucc(T const& e);  //������ǰ�ڵ�֮������½ڵ�
};
