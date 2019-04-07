/*列表(list)结构尽管也要求各元素在逻辑上具有线性次序，但对物理地址却未作任何限制--动态存储策略*/

/*列表ADT  支持接口*/
/*************************************************************************************
操作接口							功能                                   使用对象
size()						获得列表当前的规模(即为节点总数)				列表
fist()						返回首节点位置								列表
last()						返回尾节点位置								列表
insertAsFirst(e)			将e当作首节点插入                            列表
insertAsLast(e)             将e当作尾节点插入                            列表
insertBefore(p,e)           将e当作节点p的直接前驱                        列表
insertAfter(p,e)            将e当作节点p的直接后继	                    列表
remove(p)	                删除位置p处的节点，并返回其数值                列表
disordered()                判断所有节点是否已按非降序排列                 列表
sort()                      调整各节点位置，使之按非降序排列               列表
find(e)		                查找目标元素e,失败时返回NULL                  列表
search(e)                   查找目标元素e,返回不大于e且秩最大的节点       有序列表
deduplicate()               删除重复节点                                 列表
uniquify()                  删除重复结点                                有序列表
traverse()                  遍历并统一处理所有节点，处理方法由函数对象指定   列表
**********************************************************************************/

#include "ListNode.h"  //引入列表结点类

template<typename T> class List
{
	//列表模板类

private:
	int _size; //节点规模
	ListNodePosi(T) header;   //头哨兵，并非头节点
	ListNodePosi(T) trailer;  //尾哨兵

protected:
	void init();  //列表创建时的初始化
	int clear();  //清除所有节点
	void copyNodes(ListNodePosi(T) p, int n);  //复制列表中自位置p起的n项
	void merge(ListNodePosi(T)&, int); //从对p开始连续的n个节点归并排序
	void mergeSort(ListNodePosi(T)&, int); //对从p开始连续的n个节点归并排序
	void selectionSort(ListNodePosi(T), int); //对从p开始连续n个节点选择排序
	void insertionSort(ListNodePosi(T), int); //从对p开始连续的n个节点插入排序

public:
//构造函数
	List() { init(); } //默认构造
	List(List<T> const& L); //整体赋值列表L
	List(List<T> const& L, Rank r, int n); //复制列表L中自第r项起的n项
	List(ListNodePosi(T) p, int n); //复制列表中自位置p起的n项

//析构函数
	~List();  //释放，包含头、尾哨兵在内的 所有节点

//只读访问接口
	Rank size()const { return _size; } //求规模
	bool empty()const { return _size <= 0; } //判空
	T& operator[](Rank r) const;  //重载，支持循秩访问，但效率低
	ListNodePosi(T) first() const { return header->succ; }  //返回首节点位置
	ListNodePosi(T) last() const { return trailer->pred; } //返回尾节点位置

	bool valid(ListNodePosi(T) p) //判断位置p是否对外合法
	{
		return p && (trailer != p) && (header != p);  //将头、尾节点等同于NULL，均不可访问
	}

	int disordered() const; //判断列表是否已经有序
	//无序区间查找
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const; 
	ListNodePosi(T) find(T const& e)const //无序列表查找，从后往前找
	{
		return find(e, _size, trailer);
	}

	//有序区间查找
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; 

	//有序列表查找
	ListNodePosi(T) search(T const& e) const
	{
		return search(e, _size, trailer);
	}

	//在p及其前n-1个后继中选出最大者
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
	//整体最大者
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); } 

//可写访问接口
	/*插入操作*/
	ListNodePosi(T) insertAsFirst(T const& e); //将e当作首节点插入
	ListNodePosi(T) insertAsLast(T const& e); //将e当作尾节点插入
	ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const& e); //将e当作p的前驱插入
	ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const& e);  //将e当作p的后继插入

	/*删除操作*/
	T remove(ListNodePosi(T) p); //删除合法位置p处的节点，返回被删除节点

	void merge(List<T>& L) { merge(first(), _size, L, L.first, L._size); } //全列表归并
	void sort(ListNodePosi(T) p, int n); //列表区间排序
	void sort() { sort(first(), _size); } //列表整体排序

	int deduplicate();  //无序去重
	int uniquify(); //有序去重
	void reverse(); //前后倒置

	//遍历
	void traverse(void(*visit)(T&)); //遍历，依次实施visit操作（函数指针，只读或局部性修改）
	template<typename VST> void traverse(VST&); //遍历，依次实施visit操作（函数对象，可全局修改）
}; //List列表

