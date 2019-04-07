#pragma once
#include "List.h"

/*在列表中删除指定节点p的算法*/
template <typename T> T List<T>::remove(ListNodePosi(T) p)  //删除合法位置p处节点，返回其数值
{
	T e = p->data;  //假设T类型可以直接赋值，备份下来
	p->pred->succ = p->succ; //分别改变后继
	p->succ->pred = p->pred; //前驱节点

	delete p;    //释放节点，并
	_size--;     //更新规模
	return e;    //返回删除的数
} //得益于哨兵节点，删除任何节点均不会出现上溢或下溢  O(1)

