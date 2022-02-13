#include "sort.h"
#include <stdio.h>

/**
 * sorting_backwards - sort going in backwards method
 * @list: pointer to the head pointer
 * @aux: position which sorting gonna sort
 * Return: void function
 */
void sorting_backwards(listint_t **list, listint_t *aux)
{
	listint_t *swap = NULL;
	int flag = 0;

	while (aux->prev)
	{
		if (aux->n < aux->prev->n)
		{
			flag = 1;
			/*swaping nodes:*/
			swap = aux->prev;
			/*1) swaping aux->prev conections*/
			if (swap->prev)
				aux->prev = swap->prev, swap->prev->next = aux;
			else
				aux->prev = NULL, *list = aux;
			/*2) swaping swap->next conections*/
			if (aux->next)
				swap->next = aux->next, aux->next->prev = swap;
			else
				swap->next = NULL;
			/*3) swaping aux->next and swap->prev conections*/
			aux->next = swap, swap->prev = aux;
			print_list(*list);
		}
		if (aux->prev)
			if (aux->n > aux->prev->n)
				aux = aux->prev;
	}
	if (flag)
		sorting_front(list, aux);
	else
		return;
}

/**
 * sorting_front - sort to the front
 * @list: pointer to the head pointer
 * @aux: position which sorting gonna sort
 * Return: void function
 */
void sorting_front(listint_t **list, listint_t *aux)
{
	listint_t *swap = NULL;
	int flag = 0;

	while (aux->next)
	{
		if (aux->n > aux->next->n)
		{
			flag = 1;
			/*swaping nodes:*/
			swap = aux->next;
			/*1) swaping aux->next conections*/
			if (swap->next)
				swap->next->prev = aux, aux->next = swap->next;
			else
				aux->next = NULL;
			/*2) swaping aux->prev conections*/
			if (aux->prev)
				aux->prev->next = swap, swap->prev = aux->prev;
			else
				swap->prev = NULL, *list = swap;
			/*3) swaping aux->prev and swap->prev conections*/
			aux->prev = swap, swap->next = aux;
			print_list(*list);
		}
		if (aux->next)
			if (aux->n < aux->next->n)
			aux = aux->next;
	}
	if (flag)
		sorting_backwards(list, aux);
	else
		return;
}

/**
 * cocktail_sort_list - sorts using the Cocktail shaker sort algorithm
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
