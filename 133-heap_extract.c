#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height or 0 if the tree is NULL.
 */

size_t tree_height(const heap_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + tree_height(tree->left);

	if (tree->right)
		right_height = 1 + tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * tree_total_height - Measures the sum of heights of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Total height or 0 if the tree is NULL.
 */

size_t tree_total_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + tree_total_height(tree->left);

	if (tree->right)
		right_height = 1 + tree_total_height(tree->right);

	return (left_height + right_height);
}

/**
 * preorder_traversal - Goes through a binary tree using pre-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @last_node: Will be the last node in the traversal.
 * @height: Height of the tree.
 *
 * Return: No Return.
 */

void preorder_traversal(heap_t *tree, heap_t **last_node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*last_node = tree;
	height--;

	preorder_traversal(tree->left, last_node, height);
	preorder_traversal(tree->right, last_node, height);
}

/**
 * heapify - Heapifies a Max Binary Heap.
 * @root: Pointer to the root of the binary heap.
 */

void heapify(heap_t *root)
{
	int value;
	heap_t *current, *largestChild;

	if (!root)
		return;

	current = root;

	while (1)
	{
		if (!current->left)
			break;

		if (!current->right)
			largestChild = current->left;
		else
		{
			largestChild = (current->left->n >
							current->right->n)
							   ? current->left
							   : current->right;
		}

		if (current->n > largestChild->n)
			break;

		value = current->n;
		current->n = largestChild->n;
		largestChild->n = value;
		current = largestChild;
	}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: Value stored in the root node, or 0 if the function fails.
 */

int heap_extract(heap_t **root)
{
	int extractedValue;
	heap_t *heap_root, *extractedNode;

	if (!root || !*root)
		return (0);

	heap_root = *root;
	extractedValue = heap_root->n;

	if (!heap_root->left && !heap_root->right)
	{
		*root = NULL;
		free(heap_root);
		return (extractedValue);
	}

	preorder_traversal(heap_root, &extractedNode, tree_height(heap_root));

	heap_root->n = extractedNode->n;

	if (extractedNode->parent->right)
		extractedNode->parent->right = NULL;
	else
		extractedNode->parent->left = NULL;

	free(extractedNode);
	heapify(heap_root);
	*root = heap_root;

	return (extractedValue);
}
