#include <stdio.h>
#include "sort.h"

/**
 * quickR3cursion - make the recursion using quick sort logic
 * @start: slice's starts
 * @end: slice's ends
 * @size: size of array
 * @slice: array to sort
 * Return: void function
 */
void quickR3cursion(size_t start, size_t end, size_t size, int *slice)
{
	size_t posToSwap = start - 1, pivot, pos;
	int toSwap = 0;

	if (!slice || end < 2)
		return;
	pivot = end - 1;
	if (slice[pivot] == slice[start])
		return;

	for (pos = start; pos < end - 1; pos++)
	{
		if (slice[pos] < slice[pivot])
		{
			posToSwap++;
			if (slice[pos] < slice[posToSwap])
			{
				toSwap = slice[posToSwap];
				slice[posToSwap] = slice[pos];
				slice[pos] = toSwap;
				print_array(slice, size);
			}
		}
	}
	posToSwap++;
	if (slice[posToSwap] > slice[pivot])
	{
		toSwap = slice[posToSwap];
		slice[posToSwap] = slice[pivot];
		slice[pivot] = toSwap;
		print_array(slice, size);
	}
	if (start < posToSwap - 1)
		quickR3cursion(start, posToSwap, size, slice);
	if (posToSwap + 1 < end - 1)
		quickR3cursion(posToSwap + 1, end, size, slice);
}


/**
 * quick_sort - sorts arrays of integers using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void function
 */
void quick_sort(int *array, size_t size)
{
	quickR3cursion(0, size, size, array);
}
