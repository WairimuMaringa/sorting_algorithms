#include "sort.h"
/**
 * counting_sort - sort array of integers in ascending
 * order using the counting sort algo
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int n, i;
	int *buff, *arr;

	if (size < 2)
		return;

	for (n = i = 0; i < (int)size; i++)
		if (array[i] > n)
			n = array[i];

	buff = malloc(sizeof(int) * (n + 1));
	if (!buff)
		return;

	for (i = 0; i <= n; i++)
		buff[i] = 0;
	for (i = 0; i < (int)size; i++)
		buff[array[i]] += 1;
	for (i = 1; i <= n; i++)
		buff[i] += buff[i - 1];

	print_array(buff, (n + 1));
	arr = malloc(sizeof(int) * (size + 1));

	if (!arr)
	{
		free(buff);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		arr[buff[array[i]] - 1] = array[i];
		buff[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = arr[i];

	free(buff);
	free(arr);
}
