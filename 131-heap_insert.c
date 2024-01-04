#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary heap.
 * @heap: The heap to measure the size.
 *
 * Return: Size of the heap, 0 if the heap is NULL.
 */

size_t binary_tree_size(const binary_tree_t *heap)
{
	if (!heap)
		return (0);

	return (binary_tree_size(heap->left) + binary_tree_size(heap->right) + 1);
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, NULL on failure.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *heap, *newNode, *currentNode;
	int heapSize, subTreeSize, tempVal, bitPos, leaves, currLevel;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	heap = *root;
	heapSize = binary_tree_size(heap);
	leaves = heapSize;

	for (currLevel = 0, subTreeSize = 1; leaves >= subTreeSize;
		 subTreeSize *= 2, currLevel++)
		leaves -= subTreeSize;

	for (bitPos = 1 << (currLevel - 1); bitPos != 1; bitPos >>= 1)
		heap = leaves & bitPos ? heap->right : heap->left;

	newNode = binary_tree_node(heap, value);
	leaves & 1 ? (heap->right = newNode) : (heap->left = newNode);

	currentNode = newNode;
	for (; currentNode->parent && (currentNode->n > currentNode->parent->n);
		 currentNode = currentNode->parent)
	{
		tempVal = currentNode->n;
		currentNode->n = currentNode->parent->n;
		currentNode->parent->n = tempVal;
		newNode = newNode->parent;
	}

	return (newNode);
}
