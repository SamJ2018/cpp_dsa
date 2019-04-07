#pragma once
#include "List.h"

/*基于复制的列表构造方法*/

template <typename T> //assert:p为合法位置，且至少有n-1个后继节点
List<T>::List(ListNodePosi(T) p, int n) { copyNodes(p, n); } //复制列表中自位置p起的n项


template <typename T>
List<T>::List(List<T> const& L) { copyNodes(L.first(), L._size); } //整体复制列表L


template <typename T>
List<T>::List(List<T> const& L, int r, int n) { copyNodes(L[r], n); }  //复制L中第r项到n项元素
