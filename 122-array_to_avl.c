#include "binary_trees.h"

/**
 * array_to_avl_recursive - Recursively inserts elements from array into AVL
 * tree.
 * @array: Pointer to the first element of the array.
 * @start: Start index of the current array segment.
 * @end: End index of the current array segment.
 *
 * Return: Pointer to the root of the created AVL tree, or NULL on failure.
 */

avl_t *array_to_avl_recursive(int *array, size_t start, size_t end)
{
	size_t mid;
	avl_t *newNode, *leftSubTree, *rightSubTree;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	newNode = NULL;
	leftSubTree = array_to_avl_recursive(array, start, mid - 1);
	rightSubTree = array_to_avl_recursive(array, mid + 1, end);

	newNode = avl_insert(&newNode, array[mid]);

	if (!newNode)
		return (NULL);

	newNode->left = leftSubTree;
	newNode->right = rightSubTree;

	return (newNode);
}

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to root node of the created AVL tree, or NULL otherwise.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; ++i)
		avl_insert(&root, array[i]);

	return (root);
}
