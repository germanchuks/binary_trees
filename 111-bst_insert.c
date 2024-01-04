#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = (bst_t *)binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			return (bst_insert(&(*tree)->left, value));

		(*tree)->left = (bst_t *)binary_tree_node(
			(binary_tree_t *)(*tree), value);
		return ((*tree)->left);

	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (bst_insert(&(*tree)->right, value));

		(*tree)->right = (bst_t *)binary_tree_node(
			(binary_tree_t *)(*tree), value);
		return ((*tree)->right);

	}
	return (NULL);
}
