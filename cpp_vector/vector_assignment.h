#pragma once
#include "vector.h"

/*�������������*/
template <typename T> Vector<T>& Vector<T>::operator=(Vector<T> const& V)
{  //����
	if (_elem) delete _elem;  //�ͷ�ԭ�пռ�
	copyFrom(V._elem, V.size());
	return *this;
}
