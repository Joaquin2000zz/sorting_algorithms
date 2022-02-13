#include "sort.h"
#include <stdio.h>

/**
 * sorting_backwards - sort going in backwards method
 * @list: pointer to the head pointer
 * @aux2: position which sorting gonna sort
 * Return: void function
 */
void sorting_backwards(listint_t **list, listint_t *aux2)
{
	listint_t *swap = NULL;
	int flag = 0;

	while (aux2->prev)
	{
		if (aux2->n < aux2->prev->n)
		{
			flag = 1;
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
	if (flag)
		sorting_front(list, aux2);
	else
		return;
}

/**
 * sorting_front - sort to the front
 * @list: pointer to the head pointer
 * @aux2: position which sorting gonna sort
 * Return: void function
 */
void sorting_front(listint_t **list, listint_t *aux2)
{
	listint_t *swap = NULL;
	int flag = 0;

	while (aux2->next)
	{
		if (aux2->n > aux2->next->n)
		{
			flag = 1;
			/*swaping nodes:*/
			swap = aux2->next;
			/*1) swaping aux2->next conections*/
			if (swap->next)

			{
				swap->next->prev = aux2;
				aux2->next = swap->next;
			}
			else
			{
				aux2->next = NULL;
			}
			/*2) swaping aux->prev conections*/
			if (aux2->prev)
			{
				aux2->prev->next = swap;
				swap->prev = aux2->prev;
			}
			else
				swap->prev = NULL, *list = swap;
			/*3) swaping aux2->prev and swap->prev conections*/
			aux2->prev = swap;
			swap->next = aux2;
			print_list(*list);
		}
		if (aux2->next)
		{
			if (aux2->n < aux2->next->n)
			aux2 = aux2->next;
		}
	}
	if (flag)
		sorting_backwards(list, aux2);
	else
		return;
}

/**
 * insertion_sort_list - sorts using the Insertion sort algorithm
 * @list: the doubly linked list
 * Return: void function
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *aux = NULL;

	if (!list)
		return;
	aux = *list;
	sorting_front(list, aux);
}
