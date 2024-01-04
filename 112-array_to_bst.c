#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *bst_root = NULL;
	size_t idx;

	if (!array || size == 0)
		return (NULL);

	for (idx = 0; idx < size; idx++)
		if (bst_insert(&bst_root, array[idx]) == NULL)
			return (NULL);

	return (bst_root);
}
