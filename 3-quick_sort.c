#include "sort.h"
static void swap(int *a, int *b);
static int lomuto_partition(int *array, size_t size, int low, int high);
static void quick_sort_rec(int *array, size_t size, int low, int high);

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto scheme)
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, size, 0, (int)size - 1);
}

/**
 * quick_sort_rec - recursive quick sort helper
 * @array: array to be sorted
 * @size: size of the array
 * @low: starting index
 * @high: ending index
 */
static void quick_sort_rec(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, size, low, high);
		quick_sort_rec(array, size, low, p - 1);
		quick_sort_rec(array, size, p + 1, high);
	}
}

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array to partition
 * @size: size of the array
 * @low: starting index
 * @high: ending index (pivot)
 *
 * Return: pivot final position
 */
static int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j && array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high && array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}
/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
static void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
