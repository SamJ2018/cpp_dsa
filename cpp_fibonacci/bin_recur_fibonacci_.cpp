_int64 fib(int n)
{ //����fibonacci���еĵ�n��(���ֵݹ�汾) : O(2^n)
	return (2 > n) ? (_int64)n : fib(n - 1) + fib(n - 2);  //����ݹ��ֱ��ȡֵ���������ǰ�����
}