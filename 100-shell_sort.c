#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array of integers using the Shell sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void function
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size < 2)
		return;
	while (gap < size - 1)
		if ((gap * 3) + 1 < size - 1)
			gap = (gap * 3) + 1;
		else
			break;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}

}
