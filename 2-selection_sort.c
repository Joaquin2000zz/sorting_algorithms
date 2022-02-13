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
	int tmp = 0;
	size_t i, j, minvalue = 0;

	if (!array || size < 2)
		return;
	for (j = 0; j < size; j++)
	{
		minvalue = 0;
		minvalue = j;
		for (i = j; i < size; i++)
		{
			if (array[minvalue] > array[i])
			{
				minvalue = i;
			}
		}
	if (minvalue != j)
	{
		tmp = array[minvalue];
		array[minvalue] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
	}
}
