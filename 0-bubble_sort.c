#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending orderusing
 * the Bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
