#pragma once
#include "vector.h"

template<typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi)const //��������˳�����:�������һ��Ԫ��e��λ�ã�ʧ�ܷ���lo-1;
{	//assert: 0 <= lo< hi <= _size
	while ((lo < hi--) && (e != _elem[hi])); //�Ӻ���ǰ��˳����ҡ���·���ԣ�����Խ��
	return hi;  //hi<lo ����ʧ�ܣ�����hi��Ϊ����
}//��Ϊϣ�����Ԫ��ƥ��ʱ��������ߣ���˴Ӻ���ǰ����
//O(n)  --��������

