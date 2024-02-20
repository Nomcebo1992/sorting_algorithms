#include "sort.h"

/**
 * swap_elements - exchanges the positions of two elements in an array
 * @array: the array to modify
 * @element1: index of the first element to swap
 * @element2: index of the second element to swaps
 */
void swap_elements(int *array, ssize_t element1, ssize_t element2)
{
	int temp_element = array[element1];

	array[element1] = array[element2];
	array[element2] = temp_element;
}

/**
 * hoare_partition - partitions an array using Hoare's partitioning scheme
 * @array: the array to partition
 * @first: index of the first element in the range to partition
 * @last: index of the last element in the range to partition
 * @size: size of the array (for printing purposes)
 * Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int pivot = array[last]; /* Choose last element as pivot */
	int current = first - 1;
	int finder = last + 1;

	while (1)
	{
		/* Find the first element greater than the pivot from the left */
		do {
			current++;
		} while (array[current] < pivot);

		/* Find the first element smaller than the pivot from the right */
		do {
			finder--;
		} while (array[finder] > pivot);

		/* If pointers cross, partition is complete */
		if (current >= finder)
		{
			return (current);
		}

		/* Swap elements and print the updated array */
		swap_elements(array, current, finder);
		print_array(array, size);
	}
}

/**
 * recursive_QS - recursive implementation of quicksort
 *			using Hoare's partitioning
 * @array: the array to sort
 * @first: index of the first element in the range to sort
 * @last: index of the last element in the range to sort
 * @size: size of the array (for printing purposes)
 */
void recursive_QS(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t partition_index = 0;

	if (first < last)
	{
		partition_index = hoare_partition(array, first, last, size);

		/* Sort the left subarray recursively */
		recursive_QS(array, first, partition_index - 1, size);

		/* Sort the right subarray recursively */
		recursive_QS(array, partition_index, last, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers
 *			using quicksort with Hoare's partitioning
 * @array: the array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	/* Sort the entire array recursively */
	recursive_QS(array, 0, size - 1, size);
}
