#pragma once
#include "List.h"

/*在无序列表节点p的n个(真)前驱中(即不包含p)，找到等于e的最后者*/
template<typename T> ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p)const  
{
	//0<=n<=rank(p)<_size
	while (0 < n--)  //
		if (e == (p = p->pred)->data) return p;
	return NULL;  //越界即不含e,查找失败
}