#pragma once
#include "List.h"
//copyNodes()
/*  列表的内部结构需要动态创建，因此使用默认的构造方法不能完成新列表的复制创建
	需要专门编写相应的构造方法，通过复制某一已有列表来构造新列表
*/

template<typename T> //列表内部方法：复制列表中自位置p起的n项
void List<T>::copyNodes(ListNodePosi(T) p, int n)  //p合法，且至少有n-1个真后继节点
{
	init();  //创建头、尾哨兵节点并做初始化
	while (n--)
	{
		insertAsLast(p->data);
		p = p->succ;  //将起自p的n项依次作为末节点插入
	}
}//O(n+1)