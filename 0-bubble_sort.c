#include "sort.h"

/**
 * bubble_sort - sort array of integers in ascending
 * order using the bubble sort algorithm
 *
 * @array: array of integers to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, tmp = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
