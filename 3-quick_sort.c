#include <stdio.h>
#include "sort.h"

/**
 * quickR3ecursion - make the recursion using quick sort logic
 * @start: slice's starts
 * @end: slice's ends
 * @array: array to sort
 * Return: void function
 */
void quickR3cursion(size_t start, size_t end, size_t size, int *slice)
{
	size_t posToSwap = start -1, pivot, pos;
	int toSwap = 0;

	if (!slice || end < 2)
	{
		printf("sali de la recursion en if (!slice || end < 2)\n");
		return;
	}
	pivot = end - 1;
	if (slice[pivot] == slice[start])
	{
		printf("sali de la recursion en if (slice[pivot] == slice[start])\n");
		return;
	}

	for (pos = start; pos < end - 1; pos++)
	{
		if (slice[pos] < slice[pivot])
		{
			posToSwap++;
			if (slice[pos] < slice[posToSwap])
			{
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("entre al if del slice[pos] = %d < slice[posToSwap] = %d\n", slice[pos], slice[posToSwap]);
				toSwap = slice[posToSwap];
				printf("voy a cambiar slice[posToSwap] = %d < slice[pos] = %d\n", slice[posToSwap], slice[pos]);
				slice[posToSwap] = slice[pos];
				printf("cambie slice[posToSwap] = %d con slice[pos] = %d\n", slice[posToSwap], slice[pos]);
				printf("voy a cambiar slice[pos] = %d con toSwap = %d\n", slice[pos], toSwap);
				slice[pos] = toSwap;
				printf("cambié slice[pos] = %d con toSwap = %d\n", slice[pos], toSwap);
				print_array(slice, size);
				printf("-----------------------------------------++++++++++++++++++++++++++++++++++++++++++++++\n");
			}
		}
	}
	printf("sali del for\n");
	posToSwap++;
	if (slice[posToSwap] > slice[pivot])
	{
		printf("*******************************************************************************\n");
		toSwap = slice[posToSwap];
		printf("entre al if del slice[posToSwap] = %d > slice[pivot] = %d\n", slice[posToSwap], slice[pivot]);
		printf("voy a cmabiar slice[posToSwap] = %d con slice[pivot] = %d\n", slice[posToSwap], slice[pivot]);
		slice[posToSwap] = slice[pivot];
		printf("cambié slice[posToSwap] = %d con slice[pivot] = %d\n", slice[posToSwap], slice[pivot]);
		printf("voy a cambiar slice[pivot] = %d con toSwap = %d\n", slice[pivot], toSwap);
		slice[pivot] = toSwap;
		printf("cambié slice[pivot] = %d con toSwap = %d\n", slice[pivot], toSwap);
		print_array(slice, size);
		printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°**************************************************\n");
	}
	else
	{
		posToSwap--;
		printf("entre al else de  slice[posToSwap] = %d > slice[pivot] = %d\n", slice[posToSwap], slice[pivot]);
	}
	/**if (start >= posToSwap - 1)
	{
		printf("sali de la recursion en if  (start >= posToSwap - 1)\n");
		return;
	}
	*/
	if (start < posToSwap - 1)
	{
		printf("entre a la recursion de la izquierda\n");
		quickR3cursion(start, posToSwap, size, slice);
	}
	/*if (posToSwap + 1 >= end - 1)
	{
		printf("sali de la recursion en if  (posToSwap + 1 >= end - 1)\n");
		return;
	}*/
	if (posToSwap + 1 < end - 1)
	{
		printf("entre a la recursion de la derecha\n");
		quickR3cursion(posToSwap + 1, end, size, slice);
	}
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
