#include "vector.h"
#include "algorithm_sort.h"

int main()
{
	int arr[20] = { 15,24,17,2,8,4,11,19,7,12,29,26,31,15,18,13,26,24,9,8 };
	sort_bothway(arr,20);
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	return 0;
}