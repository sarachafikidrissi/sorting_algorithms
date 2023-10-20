#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * partition - A function that partion an array
 * @array: the array to be partioned
 * @lb: lower bound
 * @ub: upper bound
 * @size: the size of array
 * Return: i
*/
size_t partition(int array[], size_t lb, size_t ub, size_t size)
{
	int pivot = array[lb];
	size_t start = lb;
	size_t end = ub;
	int temp;

	while (start < end)
	{
		while (array[start] <= pivot)
			start++;

		while (array[end] > pivot)
			end--;

		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			print_array(array, size);
		}

	}
	array[lb] = array[end];
	array[end] = pivot;
	print_array(array, size);

	return (end);

}
/**
 * start_quick_sort - A function function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array to be partioned
 * @lb: lower bound
 * @ub: upper bound
 * @size: the size of array
 * Return: Nothing
*/
void start_quick_sort(int array[], size_t lb, size_t ub, size_t size)
{
	if (lb < ub)
	{
		size_t location = partition(array, lb, ub, size);

		start_quick_sort(array, lb, location - 1, size);
		start_quick_sort(array, location + 1, ub, size);
	}
}

/**
 * quick_sort - A function that sort an array
 * @array: the array to be partioned
 * @lb: lower bound
 * @ub: upper bound
 * @size: the size of array
 * Return: Nothing
*/
void quick_sort(int array[], size_t size)
{
	start_quick_sort(array, 0, size - 1, size);
}
