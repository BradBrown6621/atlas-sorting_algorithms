#include "sort.h"

/**
 * swap - Swaps two doubly linked list nodes in their list
 *
 * @a: The left node to be swapped
 * @b: The right node to be swapped
 *
 * Return: NOTHING
 */

void swap(listint_t *a, listint_t *b)
{
	a->next = b->next;
	b->prev = a->prev;
	if (a->prev)
	{
		a->prev->next = b;
	}
	if (b->next)
	{
		b->next->prev = a;
	}
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 *
 * @list: The list to be sorted
 *
 * Return: NOTHING
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *sorted_end;

	if (!list || !*list)
	{
		return;
	}

	current = *list;
	sorted_end = *list;

	while (sorted_end && sorted_end->next)
	{
		current = sorted_end->next;
		if (current->n < sorted_end->n)
		{
			swap(sorted_end, current);
			while (*list && (*list)->prev)
			{
				*list = (*list)->prev;
			}
			print_list(*list);
			while (current->prev && current->n < current->prev->n)
			{
				swap(current->prev, current);
				while (*list && (*list)->prev)
				{
					*list = (*list)->prev;
				}
				print_list(*list);
			}
		} else
		{
			sorted_end = sorted_end->next;
		}
	}
}
