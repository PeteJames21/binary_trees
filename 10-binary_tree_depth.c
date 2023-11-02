#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_depth - find the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 * Return: the depth of the node. 0 is returned if the tree is NULL
 *
 * Description - the root node is considered to be at depth 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = -1;

	/* Tree is NULL or the node is the root node. */
	if (!tree || !tree->parent)
		return (0);

	while (tree)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}
