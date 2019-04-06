_int64 fib(int n)
{ //计算fibonacci数列的第n项(二分递归版本) : O(2^n)
	return (2 > n) ? (_int64)n : fib(n - 1) + fib(n - 2);  //到达递归基直接取值，否则计算前两项和
}