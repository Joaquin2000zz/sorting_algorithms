#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *selection_sort - a function that applies the selection
 *sort to a given array and size
 *@array: given array
 *@size: given size for the array
 */

void selection_sort(int *array, size_t size)
{
	int minvalue = 0, tmp = 0;
	size_t i, j;

	for (j = 0; j < size; j++)
	{
		minvalue = j;
		for (i = j; i < size; i++)
		{
			if (array[minvalue] > array[i])
			{
				minvalue = i;
			}
		}
	tmp = array[minvalue];
	array[minvalue] = array[j];
	array[j] = tmp;
	}
