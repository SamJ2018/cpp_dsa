#pragma once
/*���ֲ��Ұ汾C*/
//����������������[lo,hi)�ڲ���Ԫ��e�� 0<=lo <=hi <=_size
template<typename T>static Rank binSearch(T* A, T const& e, Rank lo, Rank hi)
{
	while (lo < hi)
	{
		Rank mi = (lo + hi) >> 1;  //���е�Ϊ���
		(e < A[mi]) ? hi = mi : lo = mi + 1;  //���ȽϺ�ȷ������[lo,mi)��(mi,hi)
	}//�ɹ����Ҳ�����ǰ��ֹ
	return --lo; //ѭ������ʱ��loΪ����e��Ԫ�ص���С�ȣ�lo-1Ϊ������e��Ԫ�ص������
}//�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ����ʧ��λ��