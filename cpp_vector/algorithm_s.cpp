
/*1、统计整数n的二进制展开中位数为1的总数 版本1*/
int countOnes(unsigned int n)
{
	int ones = 0; //计数器
	while (0 < n)
	{
		ones += (1 & n);  //检查最低位，若为1则计数
		n >> 1;  //n/2
	}
	return ones;
}//O(logn)

/*2、计算2的n次幂 迭代版本*/
_int64 power2BF(int n)
{
	_int64 pow = 1;
	while (0 < n--)
	{
		pow << 1;
	}
	return pow;
}

/*3、数组求和，递归版*/
int sum(int n, int A[])
{
	return n > 0 ? sum(n - 1, A) + A[n - 1] : 0;  //：0是递归基，平凡情况，？后是一般情况
}//O(1)*递归深度O(1)*(n+1)=O(n)


//4、reverse 递归版本  逆置数组
void reverse(int*, int, int);//重载的倒置算法
void reverse(int* A,int n)//数组倒置的初始入口，可能调用迭代或递归版本
{reverse(A, 0, n - 1);}
/*数组倒置，多递归基版本*/
void reverse(int* A, int lo, int hi)
{
	if (lo < hi)
	{
		//swap(A[lo],A[hi]) //交换A[lo]和A[hi]
		reverse(A, lo + 1, hi - 1);
	}//隐含了两种递归基
}//O(hi-lo+1)
//迭代版本
#if 0
void reverse(int* A, int lo, int hi)
{
	while (lo < hi) 
	{
		swap(A[lo++],A[hi--]);
	}
}
#endif

//5、优化的幂函数(线性递归版本)
inline _int64 sqr(int a) { return a * a; }
_int64 power2(int n) //幂函数2^n算法，递归优化版,n>=0
{
	if (0 == n) return 1;
	return (0 & 1) ? sqr(power2(n >> 1)) << 1 : sqr(power2(n >> 1));
	//递归调用，如果为奇数最后需要乘2
}//O(logn)=O(r),r为输入指数n的比特位数

//6、计算Fibonacci数列的第n项(二分递归版本):O(2^n)
_int64 fib(int n)
{
	return (2 > n) ? (_int64)n : fib(n - 1) + fib(n - 2); //否则，递归计算钱两项，其和即为正解
}
//线性递归版本  入口：fib(n,prev)
_int64 fib(int n,_int64& prev)
{
	if (0 == n) //达到递归基
	{
		prev = 1; 
		return 0;
	}  //取：fib(-1)=1,fib(0)=0
	else
	{
		_int64 prevPrev;
		prev = fib(n - 1, prevPrev);  //递归计算前两项
		return prevPrev + prev;
	}
}
//动态规划版本 迭代版本 O(n)
_int64 fibI(int n)
{
	_int64 f = 0, g = 1;
	while (0 < n--)  //通过n次加减法计算fib(n) 
	{ 
		g += f; 
		f = g - f; 
	}
	return f;  
}

int main()
{
	return 0;
}