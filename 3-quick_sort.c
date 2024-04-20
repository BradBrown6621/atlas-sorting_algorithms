#include "sort.h"

void swap(int *a, int *b)
{
	int tmp = a[0];

	a[0] = b[0];
	b[0] = tmp;
}

int quick_sort_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left - 1;
	int j;
	int sorted = 1;

	for (j = left; j < right; j++)
	{
		if (array[j] > array[j + 1])
		{
			sorted = 0;
			break;
		}
	}
	if (sorted)
	{
		return (right);
	}

	for (j = left; j < right; j++)
	{
		if (array[j] <= pivot && array[j] != array[i + 1])
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	if (array[i + 1] != array[right])
	{
		swap(array + i + 1, array + right);
		print_array(array, size);
	}

	return i + 1;
}

void quick_sort_recursive_step(
		int *array,
		int start,
		int end,
		size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = quick_sort_partition(array, start, end, size);
		quick_sort_recursive_step(array, start, pivot - 1, size);
		quick_sort_recursive_step(array, pivot + 1, end, size);
	}
}

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	quick_sort_recursive_step(array, 0, (int)(size - 1), size);
}
