
/*1��ͳ������n�Ķ�����չ����λ��Ϊ1������ �汾1*/
int countOnes(unsigned int n)
{
	int ones = 0; //������
	while (0 < n)
	{
		ones += (1 & n);  //������λ����Ϊ1�����
		n >> 1;  //n/2
	}
	return ones;
}//O(logn)

/*2������2��n���� �����汾*/
_int64 power2BF(int n)
{
	_int64 pow = 1;
	while (0 < n--)
	{
		pow << 1;
	}
	return pow;
}

/*3��������ͣ��ݹ��*/
int sum(int n, int A[])
{
	return n > 0 ? sum(n - 1, A) + A[n - 1] : 0;  //��0�ǵݹ����ƽ�������������һ�����
}//O(1)*�ݹ����O(1)*(n+1)=O(n)


//4��reverse �ݹ�汾  ��������
void reverse(int*, int, int);//���صĵ����㷨
void reverse(int* A,int n)//���鵹�õĳ�ʼ��ڣ����ܵ��õ�����ݹ�汾
{reverse(A, 0, n - 1);}
/*���鵹�ã���ݹ���汾*/
void reverse(int* A, int lo, int hi)
{
	if (lo < hi)
	{
		//swap(A[lo],A[hi]) //����A[lo]��A[hi]
		reverse(A, lo + 1, hi - 1);
	}//���������ֵݹ��
}//O(hi-lo+1)
//�����汾
#if 0
void reverse(int* A, int lo, int hi)
{
	while (lo < hi) 
	{
		swap(A[lo++],A[hi--]);
	}
}
#endif

//5���Ż����ݺ���(���Եݹ�汾)
inline _int64 sqr(int a) { return a * a; }
_int64 power2(int n) //�ݺ���2^n�㷨���ݹ��Ż���,n>=0
{
	if (0 == n) return 1;
	return (0 & 1) ? sqr(power2(n >> 1)) << 1 : sqr(power2(n >> 1));
	//�ݹ���ã����Ϊ���������Ҫ��2
}//O(logn)=O(r),rΪ����ָ��n�ı���λ��

//6������Fibonacci���еĵ�n��(���ֵݹ�汾):O(2^n)
_int64 fib(int n)
{
	return (2 > n) ? (_int64)n : fib(n - 1) + fib(n - 2); //���򣬵ݹ����Ǯ�����ͼ�Ϊ����
}
//���Եݹ�汾  ��ڣ�fib(n,prev)
_int64 fib(int n,_int64& prev)
{
	if (0 == n) //�ﵽ�ݹ��
	{
		prev = 1; 
		return 0;
	}  //ȡ��fib(-1)=1,fib(0)=0
	else
	{
		_int64 prevPrev;
		prev = fib(n - 1, prevPrev);  //�ݹ����ǰ����
		return prevPrev + prev;
	}
}
//��̬�滮�汾 �����汾 O(n)
_int64 fibI(int n)
{
	_int64 f = 0, g = 1;
	while (0 < n--)  //ͨ��n�μӼ�������fib(n) 
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