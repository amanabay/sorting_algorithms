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
 * heapify - turns a binary tree into a complete binary heap
 * @array: array of integers representing a binary tree
 * @size: size of the tree
 * @base: base row of the tree
 * @root: root node of the binary tree
 */

void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, max;

	left = 2 * root + 1;
	right = 2 * root + 2;
	max = root;

	if (left < base && array[left] > array[max])
		max = left;
	if (right < base && array[right] > array[max])
		max = right;

	if (max != root)
	{
		swap(array + root, array + max);
		print_array(array, size);
		heapify(array, size, base, max);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 * order using the heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
