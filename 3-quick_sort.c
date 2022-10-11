#include "sort.h"

/**
 * quick_sort - sort an array of integers in ascending order
 * using the quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}

/**
 * _qsort - function for the quick_sort
 *
 * @array: array of integers
 * @head: beginning of array
 * @tail: end of the array
 * @size: size of the array
 */
void _qsort(int *array, int head, int tail, size_t size)
{
	int i, idx, tmp;

	if (tail <= head)
		return;

	idx = head;
	for (i = head; i < tail; i++)
	{
		if (array[i] < array[tail])
		{
			tmp = array[i];
			array[i] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
		}
	}
	_qsort(array, head, idx - 1, size);
	_qsort(array, idx + 1, tail, size);
}
