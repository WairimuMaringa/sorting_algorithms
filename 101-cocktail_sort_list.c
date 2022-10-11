#include "sort.h"
/**
 * swap_list - swap elements of the list
 *
 * @ptr1: the first pointer
 * @ptr2: the second pointer
 * @n: represents increase as 0, decrease 1
 */
void swap_list(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *aux, *tmp;

	aux = *ptr1;
	tmp = *ptr2;

	aux->next = tmp->next;
	tmp->prev = aux->prev;

	if (tmp->next)
		tmp->next->prev = aux;

	if (aux->prev)
		aux->prev->next = tmp;

	aux->prev = tmp;
	tmp->next = aux;

	if (n == 0)
		*ptr1 = tmp;
	else
		*ptr2 = aux;
}
/**
 * increase_sort - take largest num to the end
 *
 * @ptr: pointer to the largest num
 * @limit: list limits
 * @list: list of integers
 */
void increase_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->next != *limit)
	{
		if (aux->n > aux->next->n)
		{
			swap_list(&aux, &(aux->next), 0);
			if (aux->prev == NULL)
				*list = aux;
			print_list(*list);
		}
		aux = aux->next;
	}
	*limit = aux;
	*ptr = aux;
}
/**
 * decrease_sort - take smallest num to beginning
 *
 * @ptr: pointer to the smallest num
 * @limit: list limits
 * @list: list of integers
 */
void decrease_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->prev != *limit)
	{
		if (aux->n < aux->prev->n)
		{
			swap_list(&(aux->prev), &aux, 1);
			if (aux->prev->prev == NULL)
				*list = aux->prev;
			print_list(*list);
		}
		aux = aux->prev;
	}
	*limit = aux;
	*ptr = aux;
}
/**
 * cocktail_sort_list - sort a doubly linked list of integers
 * in ascending order using cocktail shaker sort algorithm
 *
 * @list: head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *ptr;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit1 = limit2 = NULL;
	ptr = *list;

	do {
		increase_sort(&ptr, &limit1, list);
		decrease_sort(&ptr, &limit2, list);
	} while (limit1 != limit2);
}
