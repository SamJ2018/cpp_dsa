#pragma once
#include "List.h"

/*���ڸ��Ƶ��б��췽��*/

template <typename T> //assert:pΪ�Ϸ�λ�ã���������n-1����̽ڵ�
List<T>::List(ListNodePosi(T) p, int n) { copyNodes(p, n); } //�����б�����λ��p���n��


template <typename T>
List<T>::List(List<T> const& L) { copyNodes(L.first(), L._size); } //���帴���б�L


template <typename T>
List<T>::List(List<T> const& L, int r, int n) { copyNodes(L[r], n); }  //����L�е�r�n��Ԫ��
