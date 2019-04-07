#include <stdlib.h>
/*
	列表结点接口
	操作接口						  功能
	1、data()				当前结点所存数据对象
	2、pred()				当前结点前驱结点的位置
	3、succ()				当前结点后继结点的位置
	4、insertAsPred(e)		插入前驱结点，存入被引用对象e，返回新结点位置
	5、insertAsSucc(e)		插入后继结点，存入被引用对象e，返回新结点位置
*/

typedef int Rank;  //秩
#define ListNodePosi(T) ListNode<T>*  //列表结点位置

//列表结点模板类(以双向链表形式实现)
template <typename T> struct ListNode
{
	//成员
	T data;  //数据
	ListNodePosi(T) pred; //前驱
	ListNodePosi(T) succ; //后继

	//构造函数
	ListNode() {}  //针对header和trailer的构造
	//成员赋值，若未赋值，则为NULL
	ListNode(T e, ListNodePosi(T) p=NULL, ListNodePosi(T) s=NULL):data(e),pred(p),succ(s){}

	//接口操作
	ListNodePosi(T) insertAsPred(T const& e);  //紧靠当前节点之前插入新节点
	ListNodePosi(T) insertAsSucc(T const& e);  //紧靠当前节点之后插入新节点
};
