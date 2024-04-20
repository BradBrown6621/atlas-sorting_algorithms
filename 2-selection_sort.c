#include "sort.h"

/**
 * swap - Swaps two elements of an integer array
 *
 * @a: The left element to be swapped
 * @b: The right element to be swapped
 *
 * Return: NOTHING
 */

void swap(int a[], int b[])
{
	int temp = a[0];

	a[0] = b[0];
	b[0] = temp;
}

/**
 * selection_sort - Sorts an integer array using selection sort
 *
 * @array: The array to be sorted
 * @size: The size of "array"
 *
 * Return: NOTHING
 */

void selection_sort(int *array, size_t size)
{
	size_t i, unsorted, smallest;

	if (!array)
	{
		return;
	}

	for (unsorted = 0; unsorted < size; unsorted++)
	{
		smallest = unsorted;
		for (i = unsorted + 1; i < size; i++)
		{
			if (array[i] < array[smallest])
			{
				smallest = i;
			}
		}
		if (smallest != unsorted)
		{
			swap(array + smallest, array + unsorted);
			print_array(array, size);
		}
	}
}
