#include "sort.h"
/**
 * partition - finds the partition for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
*/
size_t partition(int *array, size_t lo, size_t hi, size_t size)
{
	int tmp;
	size_t i, j;
	int pivot;

	pivot = array[hi];
	/**
	 * move j from beginning of the array to the number before pivot
	 * i need to points to the last number less than the pivot
	 * all the numbers between i and j not including i are greather than the pivot
	 * if the last condition is not satisfied increment i
	 * and swap the values pointed by i and j
	 * if j is hi - 1 swap the values between i + 1 and the pivot
	**/
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (++i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}

		}
	}
	/**
	 * now j is pointing to the last element before the pivot
	 * and i is pointing to the last element < pivot
	**/
	if (array[i + 1] > array[hi])
	{
		tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
*/
void quicksort(int *array, int lo, int hi, size_t size)
{
	size_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);

	}
}
/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * @array: array of integers.
 * @size: the size of the array.
 * Return: nothing.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
