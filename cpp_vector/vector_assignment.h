#pragma once
#include "vector.h"

/*重载向量运算符*/
template <typename T> Vector<T>& Vector<T>::operator=(Vector<T> const& V)
{  //重载
	if (_elem) delete _elem;  //释放原有空间
	copyFrom(V._elem, V.size());
	return *this;
}
