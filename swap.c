#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @x: first integer
 * @y: second integer
 */

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
