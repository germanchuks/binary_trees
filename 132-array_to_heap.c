#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created Binary Heap,
 * NULL on failure.
 */

heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *heapRoot = NULL;
	unsigned int i;

	for (i = 0; i < size; i++)
		heap_insert(&heapRoot, array[i]);

	return (heapRoot);
}
