#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: The height of the tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (tree)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);

		if (tree)
		{
			l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}

		return ((l_height > r_height) ? l_height : r_height);
	}

	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: The balance factor.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0, balance_factor = 0;

	if (tree)
	{
		l_height = (int)binary_tree_height(tree->left);
		r_height = (int)binary_tree_height(tree->right);
		balance_factor = l_height - r_height;
	}

	return (balance_factor);
}

/**
 * tree_is_perfect - Helper function to check if a tree is perfect or not.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 0 if it is not perfect, otherwise the level of height
 */

int tree_is_perfect(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;

	if (tree->left && tree->right)
	{
		l_height = 1 + tree_is_perfect(tree->left);
		r_height = 1 + tree_is_perfect(tree->right);

		if (r_height == l_height && r_height != 0 && l_height != 0)
			return (r_height);

		return (0);
	}
	else if (!tree->left && !tree->right)
		return (1);
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if it is perfect, 0 otherwise.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree)
	{
		result = tree_is_perfect(tree);
		if (result != 0)
			return (1);
		return (0);
	}
	return (0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if it is a valid Max Binary Heap, and 0 otherwise. If tree is
 * NULL, return 0.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int balance_value;

	if (tree == NULL)
		return (0);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	if (binary_tree_is_perfect(tree))
		return (1);

	balance_value = binary_tree_balance(tree);

	if (balance_value == 0)
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_heap(tree->right));

	else if (balance_value == 1)
		return (binary_tree_is_heap(tree->left) &&
				binary_tree_is_perfect(tree->right));

	return (0);
}
