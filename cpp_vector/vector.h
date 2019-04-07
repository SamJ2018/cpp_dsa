#pragma once
/*暂时先导入*/
#include <stdio.h>
#include <stdlib.h>

/*Vector类定义*/
typedef int Rank; //秩
#define DEFAULT_CAPACITY 3 //默认的初始容量（实际应用中可设置更大）

//向量模板类
template<typename T> class Vector {

protected:
	Rank _size;//规模、大小
	int _capacity; //容量
	T* _elem; //数据区

	void copyFrom(T const* A, Rank lo, Rank hi);//复制数组A[lo,hi]
	void expand();//空间不足时扩容
	void shrink();//装填因子过小时压缩
	bool bubble(Rank lo, Rank hi); //扫描交换
	Rank bubble_fast(Rank lo, Rank hi); //改良后的扫描交换
	void bubbleSort(Rank lo, Rank hi);//气泡排序算法
	Rank max(Rank lo, Rank hi); //选取最大元素
	void selectionSort(Rank lo, Rank hi); //选择排序算法
	void merge(Rank lo, Rank mi, Rank hi); //归并算法
	void mergeSort(Rank lo, Rank hi); //归并排序算法
	Rank partition(Rank lo, Rank hi); //轴点构造算法
	void quickSort(Rank lo, Rank hi); //快速排序算法
	void heapSort(Rank lo, Rank hi); //堆排序

public:
	//构造函数
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
	{	//容量为c，规模为s，所有元素初始为V
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v); //s<=c
	}
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); } //数组整体复制
	Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }//数组区间复制
	Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }//向量整体复制
	Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }//向量区间复制
//析构函数
	~Vector() { delete[] _elem; } //释放内部空间

//只读访问接口
	Rank size() const { return _size; } //求规模
	bool empty() const { return !_size; } //判空
	int disordered() const; //判断向量是否已排好序
	Rank find(T const& e) const { return find(e, 0, _size); }//无序向量整体查找
	Rank find(T const& e, Rank lo, Rank hi) const; //无序向量区间查找
	Rank search(T const& e) const { return (0 >= _size) ? -1 : search(e, 0, _size); }//有序向量整体查找
	Rank search(T const& e, Rank lo, Rank hi) const; //有序向量区间查找

//可写访问接口
	T& operator[](Rank r) const; //重载下标操作符，可用于类似数组形式引用个元素
	Vector<T>& operator= (Vector<T> const&); //重载赋值运算符，便于直接克隆向量
	T remove(Rank r); //删除秩为r的元素
	int remove(Rank lo, Rank hi); //删除秩在[lo,hi]之内的元素
	Rank insert(Rank r, T const& e); //插入元素
	Rank insert(T const& e) { return insert(_size, e); } //默认在末尾插入

	//排序
	void sort(Rank lo, Rank hi); //对[lo,hi] 排序
	void sort() { sort(0, _size); } //向量整体排序
	
	//乱序
	void unsort(Rank lo, Rank hi); //对[lo, hi]置乱
	void unsort() { unsort(0, _size); }//整体置乱

	//去重
	int deduplicate(); //无序去重
	int uniquify(); //有序去重

//遍历
	void traverse(void(*visit)(T&)); //使用函数指针，只读或局部性修改
	template<typename VST> void traverse(VST&); //遍历(使用函数对象，可全局性修改)
	
//遍历增加
	template<typename T>struct Increase  //函数对象，递增一个T类对象
	{ 
		virtual void operator()(T& e) { e++; }  //假设T可以直接递增或者已经重载++
	};
	//以Increase<T>()为基本操作进行遍历
	template<typename T> void increase(Vector<T>& V) //统一递增向量中的各元素
	{
		V.traverse(Increase<T>());
	}

//交换
	template<typename T> void Swap(T& t1, T& t2) { T temp = t1; t1 = t2; t2 = temp; }
	template<typename T> void Swap(T* t1, T* t2) { Swap(*t1, *t2); }

};//vector;

#include "vector_implementation.h"