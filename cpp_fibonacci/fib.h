#pragma once

//fibonacci数列类
class Fib
{   
private:
	int f, g;    //f=fib(k-1),g=fib(k), 因为都是int型，很快数值就会溢出
public:
	Fib(int n)  //初始化为不小于n的最小fibonacci项
	{
		f = 1;
		g = 0;
		while (g < n) next();
	}//fib(-1),fib(0),O(log_phi(n))时间

	//fun get
	int get() 
	{ 
		return g; 
	}

	///转到下一个fibonacci项
	int next() 
	{ 
		g += f; 
		f = g - f; 
		return g;   
	}//O(1)时间

	/*转至上一个fabonacci项*/
	int prev()
	{
		f = g - f;
		g -= f;
		return g;
	}//O(1)时间
};