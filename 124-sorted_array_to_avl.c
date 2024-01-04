#include "binary_trees.h"

/**
 * sorted_array_to_avl_rec - Builds an AVL tree from a sorted array
 * recursively.
 * @parent: Pointer to the parent.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the current subtree.
 * @end: Ending index of the current subtree.
 *
 * Return: Pointer to the root node of the created AVL tree.
 */

avl_t *sorted_array_to_avl_rec(avl_t *parent, int *array, int start, int end)
{
	binary_tree_t *newNode;
	avl_t *root;
	int mid = 0;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	newNode = binary_tree_node((binary_tree_t *)parent, array[mid]);

	if (!newNode)
		return (NULL);

	root = (avl_t *)newNode;
	root->left = sorted_array_to_avl_rec(root, array, start, mid - 1);
	root->right = sorted_array_to_avl_rec(root, array, mid + 1, end);
	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to root node of the created AVL tree, or NULL on failure.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_rec(NULL, array, 0, size - 1));
}
