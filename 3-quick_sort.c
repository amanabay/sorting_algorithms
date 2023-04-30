#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @x: first integer
 * @y: second integer
 *
 */

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - split array around pivot using lomuto scheme
 * @arr: array of integers
 * @first: first element of the array
 * @last: last element of the array 
 * @size: size of the array 
 *
 * Return: the last  partition index
 */

int lomuto_partition(int array[], int first, int last, size_t size)
{
	int pivot = array[last];
	int i = first;
	int j;

	for (j = first; j < last; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}

	swap(&array[i], &array[last]);
	if (i != j)
		print_array(array, size);
	return (i);
}

/**
 * lomuto_sort - Ssorts porton of the array
 *
 * @array: array to be sorted
 * @first: first element of the array
 * @last: last element of the array 
 * @size: size of the array 
 *
 * Return: the last  partition index
 */


void lomuto_sort(int array[], int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = lomuto_partition(array, first, last, size);
		lomuto_sort(array, first, pivot - 1, size);
		lomuto_sort(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}
