#pragma once
#include "vector.h"

template<typename T>
void Vector<T>::shrink()
{//装填因子过小，压缩空间
	if (_capacity < DEFAULT_CAPACITY << 1) return;  //不至于收缩到DEFAULT_CAPACITY以下
	if (_size << 2 > _capacity) return;   //装填因子超过25%就不必收缩
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];  //原数组容量减半
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];  //复制原向量内容
	delete[] oldElem;  //释放空间
}