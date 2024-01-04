#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *newRoot;

	if (!tree || !tree->left)
		return (tree);

	newRoot = tree->left;
	tree->left = newRoot->right;

	if (newRoot->right)
		newRoot->right->parent = tree;

	newRoot->parent = tree->parent;
	tree->parent = newRoot;
	newRoot->right = tree;

	return (newRoot);
}
