#include "sort.h"

/**
 * sorting - sort with insertion method
 * @list: pointer to the head pointer
 * @aux2: position which sorting gonna sort
 * Return: void function
 */
void sorting(listint_t **list, listint_t *aux2)
{
	listint_t *swap = NULL;

	while (aux2->prev)
	{
		if (aux2->n < aux2->prev->n)
		{
			/*swaping nodes:*/
			swap = aux2->prev;
			/*1) swaping aux2->prev conections*/
			if (swap->prev)
			{
				aux2->prev = swap->prev;
				swap->prev->next = aux2;
			}
			else
			{
				aux2->prev = NULL, *list = aux2;
			}
			/*2) swaping swap->next conections*/
			if (aux2->next)
			{
				swap->next = aux2->next;
				aux2->next->prev = swap;
			}
			else
				swap->next = NULL;
			/*3) swaping aux2->next and swap->prev conections*/
			aux2->next = swap;
			swap->prev = aux2;
			print_list(*list);
		}
		if (aux2->prev)
		{
			if (aux2->n > aux2->prev->n)
			aux2 = aux2->prev;
		}
	}
}

/**
 * insertion_sort_list - sorts using the Insertion sort algorithm
 * @list: the doubly linked list
 * Return: void function
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL, *aux2 = NULL;

	if (!list)
		return;
	aux = *list;
	while (aux->next)
	{
		if (aux->n > aux->next->n)
		{
			aux2 = aux->next;
			sorting(list, aux2);
		}
		if (!aux->next)
			break;
		if (aux->n < aux->next->n)
			aux = aux->next;
	}
}
