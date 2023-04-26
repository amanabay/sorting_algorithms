#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending
 * order using the shell sort algorithm.
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t h = 1, i;

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			int temp = array[i], j = i;

			while (j > h - 1 && array[j - h] >= temp)
			{
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = temp;
		}
		print_array(array, size);
		h = (h - 1) / 3;
	}
}
