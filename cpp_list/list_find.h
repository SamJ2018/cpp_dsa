#pragma once
#include "List.h"

/*�������б�ڵ�p��n��(��)ǰ����(��������p)���ҵ�����e�������*/
template<typename T> ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p)const  
{
	//0<=n<=rank(p)<_size
	while (0 < n--)  //
		if (e == (p = p->pred)->data) return p;
	return NULL;  //Խ�缴����e,����ʧ��
}