#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_nodes - count the nodes with at least one child
 * @tree: a pointer to the root node
 * Return: the number of nodes with at least one child, or 0 if @tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->right && !tree->left)  /* Don't count the leaves */
		return (0);

	return (
		binary_tree_nodes(tree->left) + 1 +
		binary_tree_nodes(tree->right)
	);
}
