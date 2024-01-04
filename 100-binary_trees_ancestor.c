#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *f_parent, *s_parent;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	f_parent = first->parent;
	s_parent = second->parent;

	if (!f_parent || first == s_parent || (!f_parent->parent && s_parent))
		return (binary_trees_ancestor(first, s_parent));
	else if (!s_parent || f_parent == second ||
			 (!s_parent->parent && f_parent))
		return (binary_trees_ancestor(f_parent, second));

	return (binary_trees_ancestor(f_parent, s_parent));
}
