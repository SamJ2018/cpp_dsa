//����fibonacci���е�n��(���Եݹ��) :  �����ʽfib(n,prev)
_int64 fib(int n, _int64& prev)
{
	if (0 == n) //�ݹ�� ����
	{
		prev = 1;
		return 0;
	}
	else
	{
		_int64 prevPrev;
		prev = fib(n - 1, prevPrev);  //�ݹ����ǰ����
		return prevPrev + prev;  //ǰ�����Ϊ����
	}
}//��prevPrev��¼ǰһ��������еĵ�ǰ��, O(n)