#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - A functio that sorts an array of integers in ascending order
 * @array: the the array to be sorted
 * @size: the size of array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, flag;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				flag = 1;
			}

		}
		if (flag == 0)
			break;
	}
}

