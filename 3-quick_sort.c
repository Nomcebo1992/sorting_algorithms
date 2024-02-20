#include "sort.h"
/**
 * swap_int - Swap two integer in array.
 * @a: first integer using to swap.
 * @b: second integer using also to swap.
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a to set array in integer according to
 *                    lomuto partition scheme (last element pivot).
 * @array: array the integer.
 * @size: size of array.
 * @left: starting index of set to order.
 * @right: ending index of set to order.
 *
 * Return: to the final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_int(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_int(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implementation of quick sort algorithm through iteration.
 * @array: array of integer to the sort.
 * @size: size of array.
 * @left: starting index of array partition to make a order.
 * @right: ending index of array partition to make a order.
 *
 * Description: it uses the lomuto split system.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort array of integer in ascend
 *              order the quicksort algorithm.
 * @array: array integer.
 * @size:  size of array.
 *
 * Description: uses the Lomuto to split the system
 *              array after every two-element swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
