#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * using the 'Bubble sort' algorithm
 * @array: the array!
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int swapped = 1;
	int tmp = 0;


	while (swapped == 1)
	{
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
