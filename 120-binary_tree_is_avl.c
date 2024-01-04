#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 * Return: Height of the tree, 0 if tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Pointer to the minimum value a node can take.
 * @max: Pointer to the maximum value a node can take.
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */

int is_bst(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (!tree)
		return (1);

	if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
		return (0);

	return (is_bst(tree->left, min, tree) && is_bst(tree->right, tree, max));
}

/**
 * is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Pointer to the minimum value a node can take.
 * @max: Pointer to the maximum value a node can take.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */

int is_avl(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	int left_height, right_height, balance_factor;

	if (!tree)
		return (1);

	if (!is_bst(tree, min, max))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	balance_factor = left_height - right_height;

	if (balance_factor > 1 || balance_factor < -1)
		return (0);

	return (is_avl(tree->left, min, tree) && is_avl(tree->right, tree, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!is_bst(tree, NULL, NULL) || !is_avl(tree, NULL, NULL))
		return (0);

	return (1);
}
