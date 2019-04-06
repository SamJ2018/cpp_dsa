//计算fibonacci数列第n项(线性递归版) :  入口形式fib(n,prev)
_int64 fib(int n, _int64& prev)
{
	if (0 == n) //递归基 ，则
	{
		prev = 1;
		return 0;
	}
	else
	{
		_int64 prevPrev;
		prev = fib(n - 1, prevPrev);  //递归计算前两项
		return prevPrev + prev;  //前两项和为正解
	}
}//用prevPrev记录前一项，返回数列的当前项, O(n)