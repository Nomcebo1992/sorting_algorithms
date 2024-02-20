#include "sort.h"
#include <stdio.h>

/**
 * swap_INTs - utility function to swap two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 **/
void swap_INTs(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * max_Heap - maintains the max-heap property for a subtree
 * @array: the array representing the heap
 * @size: size of the array for print
 * @IndeX: index of the root of the subtree
 * @n: size of the heap
 */
void max_Heap(int *array, size_t size, int IndeX, size_t n)
{
	int Largest = IndeX;	/* Initialize largest as root */
	int left = 2 * IndeX + 1;
	int right = 2 * IndeX + 2;

	/* check if left child of root exists && > root */
	if (left < (int)n && array[left] > array[Largest])
		Largest = left;

	/* check if right child of root exists && > the Largest so far */
	if (right < (int)n && array[right] > array[Largest])
		Largest = right;

	/* Change root -if needed- */
	if (Largest != IndeX)
	{
		swap_INTs(&array[IndeX], &array[Largest]);
		print_array(array, size);
		/* Heapify the root */
		max_Heap(array, size, Largest, n);
	}
}

/**
 * heap_sort -sorts an array in ascending order using the Radix sort algorithm.
 * @array: array of integers to be sorted
 * @size: he array length
 **/
void heap_sort(int *array, size_t size)
{
	int i;
	/* Validate input conditions */
	if (!array || size < 2)
		return;	/* Handle invalid input gracefully (e.g., log error) */

	/* Build a max-heap from the entire array in a bottom-up manner */
	for (i = (size - 2) / 2; i >= 0; --i)
		max_Heap(array, size, i, size);

	/* Extract elements one by one */
	for (i = (size - 1); i > 0; --i)
	{
		/* Move current root to end */
		swap_INTs(&array[0], &array[i]);
		print_array(array, size);

		/* call max heap on the reduced heap */
		max_Heap(array, size, 0, i);
	}
}
