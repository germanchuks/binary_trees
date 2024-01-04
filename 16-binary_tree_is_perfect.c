#include "binary_trees.h"

/**
 * check_perfect_tree - Helper function to check if a tree is perfect.
 *
 * @tree: Tree to check.
 *
 * Return: Height of the tree if perfect, -1 otherwise.
 */

int check_perfect_tree(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree->left && tree->right)
	{
		left_height = 1 + check_perfect_tree(tree->left);
		right_height = 1 + check_perfect_tree(tree->right);

		if (right_height == left_height && right_height != -1 &&
			left_height != -1)
			return (right_height);
		return (-1);
	}
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (-1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_perfect_tree(tree) != -1);
}
