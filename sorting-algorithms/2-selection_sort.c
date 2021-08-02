#include "sort.h"
/**
 * selection_sort - sort array with selection sort algorithm
 * @array: array to sort
 * @size: size of the array
**/
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t idx;
	int tmp;

	for (i = 0; i < size; i++)
	{
		idx = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[idx])
			{
				idx = j;
			}
		}
		if (idx != i)
		{
			tmp = array[i];
			array[i] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
