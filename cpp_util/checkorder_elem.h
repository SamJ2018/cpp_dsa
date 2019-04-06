#pragma once

/*判断一个T类是否局部有序*/
template<typename T> struct CheckOrder 
{
	T pred;  
	int& u;
	CheckOrder(int& unsorted, T& first):pred(first),u(unsorted){}
	virtual void operator()(T& e)
	{
		if (pred > e) u++;
		pred = e;
	}
};