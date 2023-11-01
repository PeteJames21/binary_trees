#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_leaves - find the number of leaves in a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: the number of leaves in the tree, or 0 if @tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	return (
		binary_tree_leaves(tree->left)
		+ binary_tree_leaves(tree->right)
	);
}
