#pragma once
#include "ListNode.h"

//将e插入当前节点之前,因为有哨兵节点，即使当前节点为首节点，前驱也存在
template<typename T> ListNodePosi(T) ListNode<T>::insertAsPred(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, pred, this); //x的前驱链接到当前节点的前驱结点，x的后继链接到当前节点
	pred->succ = x;  
	pred = x;  //当前节点前驱链接到x
	return x;  //返回新节点位置
}

//将e插入当前节点之后
template<typename T> ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, this, succ); //创建新节点
	succ->pred = x;  //插入
	succ = x; //插入节点归位

	return x; //返回新节点位置
}
//上述两个操作，仅涉及局部两个原有结点，和一个新结点 。且不含递归或迭代，若假设当前节点已经定位，不计入
//此前查找所消耗的时间， 则均可以在常数时间内完成

