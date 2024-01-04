#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise. If tree is NULL, return 0.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	const binary_tree_t *queue[1024];
	int front = 0, rear = 0;
	int flag = 0;

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		if (!current->left)
			flag = 1;
		else if (flag)
			return (0);
		queue[rear++] = current->left;

		if (!current->right)
			flag = 1;
		else if (flag)
			return (0);
		queue[rear++] = current->right;
	}

	return (1);
}
