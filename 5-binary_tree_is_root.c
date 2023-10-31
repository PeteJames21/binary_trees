#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_root - check if a binary tree node is a root node
 * @node: a pointer to the node to be evaluated
 * Return: 1 if the node is a root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	else
		return (1);
}
