#include "sort.h"

/**
 * selection_sort - sorts array in ascending order => Selection sort algorithm
 * @array: the array of integers
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t index;
	int temp;
	int flg = 0;
	int swap;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		temp = i;
		flg = 0;

		for (index = i + 1; index < size; index++)
		{
			if (array[temp] > array[index])
			{
				temp = index;
				flg += 1;
			}
		}
		swap = array[i];
		array[i] = array[temp];
		array[temp] = swap;

		if (flg != 0)
		{
			print_array(array, size);
		}
	}
}
