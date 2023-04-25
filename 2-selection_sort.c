#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending orderusing
 * the selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size == 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		size_t last = size - i - 1;
		int pos = 0;

		for (j = i; j <= last; j++)
			if (array[j] > array[pos])
				pos = j;

		swap(&array[pos], &array[last]);
		print_array(array, size);
	}
}
