#include "sort.h"
#include <stdio.h>

/**
 * M_alloc - allocates memory for an array, initializes it with zero
 * @elemN: number of elements
 * @size: size of each element
 * Return: pointer to the allocated memory, or NULL if allocation fails
 */
void *M_alloc(unsigned int elemN, unsigned int size)
{
	unsigned int i = 0;
	char *Buffer;

	if (elemN == 0 || size == 0)
		return ('\0');

	Buffer = malloc(elemN * size);
	if (Buffer == NULL)
		return ('\0');
	for (i = 0; i < (elemN * size); i++)
		Buffer[i] = '\0';
	return (Buffer);
}

/**
 * counting_sort - sorts an array of integers using Counting Sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int index, maxNUM = 0;
	int *counter = '\0', *temp = '\0';
	size_t i;

	if (!array || size < 2)
		return;

	/* Find the maximum number in the array */
	for (i = 0; i < size; i++)
		if (array[i] > maxNUM)
			maxNUM = array[i];

	/* Allocate memory for counter and temporary arrays */
	counter = M_alloc(maxNUM + 1, sizeof(int));
	temp = M_alloc(size + 1, sizeof(int));

	/* Count occurrences of each element in the array */
	for (i = 0; i < size; i++)
		counter[array[i]]++;

	/* Get the cumulative count of each element */
	for (index = 1; index <= maxNUM; index++)
		counter[index] += counter[index - 1];

	/* Print the count array */
	print_array(counter, maxNUM + 1);

	/* Place elements in their correct position in the temporary array */
	for (i = 0; i < size; ++i)
	{
		temp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
	free(counter);
}
