#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *newRoot;

	if (!tree || !tree->right)
		return (tree);

	newRoot = tree->right;
	tree->right = newRoot->left;

	if (newRoot->left)
		newRoot->left->parent = tree;

	newRoot->parent = tree->parent;
	tree->parent = newRoot;
	newRoot->left = tree;

	return (newRoot);
}
