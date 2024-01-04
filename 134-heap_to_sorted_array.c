#include "binary_trees.h"

/**
 * tree_size - Helper function to measure the total height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Total height, or 0 if tree is NULL
 */

size_t tree_size(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + tree_size(tree->left);

	if (tree->right)
		right_height = 1 + tree_size(tree->right);

	return (left_height + right_height);
}


/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of
 * integers.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 *
 * Return: Pointer to the array sorted in descending order.
 **/

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int index, *sortedArray = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	sortedArray = malloc(sizeof(int) * (*size));

	if (!sortedArray)
		return (NULL);

	for (index = 0; heap; index++)
		sortedArray[index] = heap_extract(&heap);

	return (sortedArray);
}
