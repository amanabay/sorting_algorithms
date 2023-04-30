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
 * hoare_partition - array partition method 
 * @array: array to be partitioned
 * @first: inital position
 * @last: last position
 * @size: size of the array
 *
 * Return: final pivot index
 */
int hoare_partiton(int array[], int first, int last, size_t size)
{
	int pivot = array[last], i = first - 1, j = last + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (j < i)
			return (j);
		if (array[i] > array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}

/**
 * hoare_sort - sorts an array of integers recursively
 * using hoare partition scheme
 *
 * @array: array to be sorted
 * @first: initial position
 * @last: last position
 * @size: array size
 */
void hoare_sort(int array[], int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = hoare_partiton(array, first, last, size);
		hoare_sort(array, first, pivot, size);
		hoare_sort(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending
 * using the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, 0, size - 1, size);
}
