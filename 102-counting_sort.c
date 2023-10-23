#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * counting_sort - A function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: Inputed array
 * @size: size of array
 * Return: Nothing
*/
void counting_sort(int *array, size_t size)
{
	size_t i, max;
	int *count_array, *output_array;

	if (size < 2)
		return;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}

	count_array = (int *)malloc(sizeof(int) * (max + 1));

	for (i = 0; i <= max; i++)
	{
		count_array[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}
	for (i = 1; i <= max; i++)
	{
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	print_array(count_array, max + 1);

	output_array = malloc(sizeof(int) * size);

	for (i = size - 1; i < size; i--)
	{
		output_array[--count_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = output_array[i];
	}
	free(count_array);
}
