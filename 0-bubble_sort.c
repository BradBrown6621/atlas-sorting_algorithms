#include "sort.h"

/**
 * swap - Swaps the position of two array indices
 *
 * @a: The left position
 * @b: The right position
 *
 * Return: NOTHING
 */

void swap(int a[], int b[])
{
	int tmp = a[0];

	a[0] = b[0];
	b[0] = tmp;
}

/**
 * bubble_sort - Sorts an integer array using bubble sort
 *
 * @array: The integer array to be sorted
 * @size: The size of "array"
 *
 * Return: NOTHING
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || !size)
	{
		return;
	}

	for (i = 1; i < size; i++) /** loop through each element in array */
	{
		j = i;
		while (j < size)
		{
			if (array[j - 1] > array[j])
			{
				swap(array + j - 1, array + j);
				print_array(array, size);
				i = 0;
			}
			j++;
		}
	}
}
