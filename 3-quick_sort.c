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
 * lomuto_partition - partition an array using lomuto partition
 * scheme
 *
 * @array: array to be partitioned
 * @size: size of array
 * @high: end of the array
 * @low: starting comparison point
 *
 * Return: finaal partition index
 */

int lomuto_partition(int array[], size_t size, int low, int high)
{
	int pivot = array[high], i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * lomuto_sort - sorts the array rcursively
 *
 * @array: array to be sorted
 * @high: end of the array
 * @size: size of array
 * @low: starting comparison point
 *
 */

void lomuto_sort(int array[], size_t size, int low, int high)
{
	if (low < high)
	{
		int part_idx = lomuto_partition(array, size, low, high);

		lomuto_sort(array, size, low, part_idx - 1);
		lomuto_sort(array, size, part_idx + 1, high);
	}
}

/**
 * quick_sort - Sorts array using quick_sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
