#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order using inertion sort algo
 *
 * @list: doubly linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current, *swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	head = (*list)->next;
	while (head != NULL)
	{
		current = head;
		swap = head->prev;

		while (swap != NULL && (current->n < swap->n))
		{
			swap->next = current->next;

			if (current->next != NULL)
				current->next->prev = swap;

			current->prev = swap->prev;
			current->next = swap;

			if (swap->prev != NULL)
				swap->prev->next = current;
			else
				*list = current;

			swap->prev = current;

			swap = current->prev;

			print_list(*list);
		}
		head = head->next;
	}
}
