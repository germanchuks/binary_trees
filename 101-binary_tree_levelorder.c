#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Description: This function traverses the binary tree in level order
 * and applies the provided function to each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	const binary_tree_t *current, *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left)
			queue[rear++] = current->left;

		if (current->right)
			queue[rear++] = current->right;
	}
}
