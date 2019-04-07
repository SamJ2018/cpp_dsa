#include "vector.h"

template <typename T>
void swap(T*, T, T);
/* Ë«ÏòÃ°ÅÝÅÅÐò */
template<typename T>
void sort_bothway(T* V,T n)
{
	int lo = 0, hi = n-1, pos;
	bool sorted = true;
	while (lo < hi && sorted)
	{
		sorted = false;
		for(pos = lo; pos < hi; pos++)
		{
			if (V[pos] > V[pos + 1])
			{
				sorted = true;
				swap(V, pos, pos + 1);
			}
		}//for

		--hi;

		for (pos = hi; pos > lo; --pos)
		{
			if (V[pos] < V[pos - 1])
			{
				sorted = true;
				swap(V, pos, pos - 1);
			}
		}
		++lo;
	}
}

template <typename T>
void swap(T* v, T pos1, T pos2)
{
	v[pos1] = v[pos1] ^ v[pos2];
	v[pos2] = v[pos1] ^ v[pos2];
	v[pos1] = v[pos1] ^ v[pos2];
}

