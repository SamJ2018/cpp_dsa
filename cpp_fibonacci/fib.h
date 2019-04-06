#pragma once

//fibonacci������
class Fib
{   
private:
	int f, g;    //f=fib(k-1),g=fib(k), ��Ϊ����int�ͣ��ܿ���ֵ�ͻ����
public:
	Fib(int n)  //��ʼ��Ϊ��С��n����Сfibonacci��
	{
		f = 1;
		g = 0;
		while (g < n) next();
	}//fib(-1),fib(0),O(log_phi(n))ʱ��

	//fun get
	int get() 
	{ 
		return g; 
	}

	///ת����һ��fibonacci��
	int next() 
	{ 
		g += f; 
		f = g - f; 
		return g;   
	}//O(1)ʱ��

	/*ת����һ��fabonacci��*/
	int prev()
	{
		f = g - f;
		g -= f;
		return g;
	}//O(1)ʱ��
};