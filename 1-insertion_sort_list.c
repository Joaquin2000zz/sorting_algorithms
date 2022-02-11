#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts using the Insertion sort algorithm
 * @list: the doubly linked list
 * Return: void function
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL, *aux2 = NULL;
	listint_t *swap1 = NULL, *swap2 = NULL, *swap3 = NULL;
	int flag;
	if (!list)
		return;
	aux = *list;
	while (aux->next)
	{
		if (aux->n > aux->next->n)
		{
			printf("-----------------------------\n");
			printf("encontre numero para swapear en el primer if\n");

			swap1 = aux, swap2 = aux->next, swap3 = aux->prev;
			swap1->prev = swap2, swap1->next = swap2->next;
			if (swap2->next)
				swap1->next->prev = swap1;
			swap2->prev = swap3, swap3->next = swap2;
			swap2->next = swap1;
			aux2 = aux;
			printf("ya hice la marincoche de las primeras flechitas\n");
			print_list(*list);
			printf("ya use funcion print list pa mostrar la lista en primer while\n");
			while (aux2->prev)
			{
				flag = 0;
				printf("*************************************************\n");
				printf("entre al segundo while\n");
				if (aux2->n < aux2->prev->n)
				{
					flag = 1;
					printf("encontré numero para swapear en el segundo if\n");
					swap1 = aux2, swap2 = aux2->next;
					swap3 = aux2->prev;
					swap1->prev = swap3->prev;
					swap1->next = swap3;
					if (swap3->prev)
						swap3->prev->next = swap1;
					swap3->next = swap2;
					swap3->prev = swap1;
					swap2->prev = swap3;
					printf("ya hice la marincoche con las segundas flechitas\n");
					print_list(*list);
					printf("termine de printear la lista en el segudno while\n");
					printf("*************************************\n");
				}
				if (flag == 0)
					break;
				aux2 = aux2->prev;
			}
			printf("sali del segundo while\n");
			printf("---------------------------------------------------\n");
		}
		printf("antes de aux->next n = %d\n", aux->n);
		if (!aux->next)
			break;
		if (aux->n < aux->next->n)
			aux = aux->next;
		printf("en aux->next n = %d\n", aux->n);
	}
}
