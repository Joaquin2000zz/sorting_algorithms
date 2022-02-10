#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * bubble_sort - a function that sorts an array using the bubble sort method
 * @array: given array
 * @size: size of the given array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, aux, flag = 0;

	if (!array)
		exit(0);
	for (j = 0; array && j < size;)
	{
		flag = 0;
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1] && array[i + 1])
			{
				aux = array[i + 1];
				array[i + 1] = array[i];
				array[i] = aux;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
