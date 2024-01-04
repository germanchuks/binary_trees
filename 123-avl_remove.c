#include "binary_trees.h"

/**
 * find_min_value_node - Finds the node with the minimum value in an AVL tree.
 * @node: The root node to start the search.
 *
 * Return: Pointer to the node with the minimum value.
 */

avl_t *find_min_value_node(avl_t *node)
{
	while (node && node->left)
		node = node->left;

	return (node);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @value: The value to remove from the tree.
 *
 * Return: Pointer to the new root node of the tree after removal and
 * rebalancing.
 */

avl_t *avl_remove(avl_t *root, int value)
{
	int balance;
	avl_t *temp;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (!temp)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			temp = find_min_value_node(root->right);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	if (!root)
		return (NULL);
	balance = binary_tree_balance(root);
	if (balance > 1)
	{
		if (binary_tree_balance(root->left) >= 0)
			return (binary_tree_rotate_right(root));
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1)
	{
		if (binary_tree_balance(root->right) <= 0)
			return (binary_tree_rotate_left(root));
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
