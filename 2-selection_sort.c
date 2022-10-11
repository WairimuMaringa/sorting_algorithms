#include "sort.h"

/**
 * selection_sort - sort an array of integers in ascending
 * order using the selection sort algorithm
 *
 * @array: array of integers to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp = 0, sort_swap = 0;

	for (i = 0; i < size; i++)
	{
		sort_swap = 0;
		tmp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < tmp)
			{
				sort_swap = j;
				tmp = array[j];
			}
		}
		if (sort_swap)
		{
			array[sort_swap] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
