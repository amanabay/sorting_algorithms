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
 * @size: size of the array
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
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort - Sorts array using quick_sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int low = 0;
    int high = size - 1;

    if (low < high) {
        int pivot = lomuto_partition(array, size, low, high);
        quick_sort(array, pivot);
        quick_sort(array + pivot + 1, size - pivot - 1);
    }
}
