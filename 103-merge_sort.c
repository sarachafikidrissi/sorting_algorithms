#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, int lb, int mid, int ub, int *output_array)
{
	int i = lb, j = mid + 1, k = lb;

	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
		{
			output_array[k] = array[i];
			i++;
		}
		else
		{
			output_array[k] = array[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= ub)
		{

			output_array[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			output_array[k] = array[i];
			i++;
			k++;
		}
	}

	for (k = lb; k <= ub; k++)
		array[k] = output_array[k];

}

void merge_sort_(int *array, int lb, int ub, int *output_array)
{
	int mid;

	if (lb < ub)
	{
		mid = ((lb + ub) / 2);

		merge_sort_(array, lb, mid, output_array);
		merge_sort_(array, mid + 1, ub, output_array);
		merge(array, lb, mid, ub, output_array);
	}
}


void merge_sort(int *array, size_t size)
{
	int lb, ub;
	int *output_array;

	output_array = malloc(sizeof(int) * size);
	lb = 0;
	ub = size - 1;

	merge_sort_(array, lb, ub, output_array);
	free(output_array);
}
