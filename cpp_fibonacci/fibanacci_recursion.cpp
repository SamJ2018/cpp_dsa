#pragma once
//����fibonacci���еĵ�n��(������)  O(n)
_int64 fib_recur(int n)
{
	_int64 f = 1, g = 0;   //��ʼ����fib(-1)��fib(0)
	while (0 < n--)
	{
		g += f;
		f = g - f;
	}//ͨ��n�μӷ��ͼ�������fib(n)

	return g;
}