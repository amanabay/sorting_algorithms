#include "sort.h"

/**
 * max_num - maximum value in an array of integers
 * @array: array of integers
 * @size: size of the array
 *
 * Return: maximum integer in the array
 */
int max_num(int *array, int size)
{
	int max = array[0], i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the counting sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted_array, max, i;

	if (array == NULL || size < 2)
		return;

	max = max_num(array, size);

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted_array);
		return;
	}

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_array[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(count);
}

