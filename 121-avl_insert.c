#include "binary_trees.h"

/**
 * avl_insert_recursive - Recursively inserts a value into an AVL tree.
 * @root: Double pointer to the root node of the AVL tree.
 * @parent: Parent node of the AVL tree.
 * @newNode: Double pointer to the newly inserted node.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the root node after insertion, or NULL if fails.
 */

avl_t *avl_insert_recursive(avl_t **root, avl_t *parent, avl_t **newNode,
							int value)
{
	int balance_factor;

	if (*root == NULL)
		return (*newNode = binary_tree_node(parent, value));

	if ((*root)->n > value)
	{
		(*root)->left = avl_insert_recursive(&(*root)->left, *root, newNode,
											 value);
		if ((*root)->left == NULL)
			return (NULL);
	}
	else if ((*root)->n < value)
	{
		(*root)->right = avl_insert_recursive(&(*root)->right, *root, newNode,
											  value);
		if ((*root)->right == NULL)
			return (NULL);
	}
	else
		return (*root);

	balance_factor = binary_tree_balance(*root);
	if (balance_factor > 1 && (*root)->left->n > value)
		*root = binary_tree_rotate_right(*root);
	else if (balance_factor > 1 && (*root)->left->n < value)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor < -1 && (*root)->right->n < value)
		*root = binary_tree_rotate_left(*root);
	else if (balance_factor < -1 && (*root)->right->n > value)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}

	return (*root);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the newly inserted node, or NULL if fails.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newNode = NULL;

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &newNode, value);
	return (newNode);
}
