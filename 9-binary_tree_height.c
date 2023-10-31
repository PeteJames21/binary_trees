#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_height_rec - find the height of a binary tree
 * @tree: a pointer to the root node of the tree
 * @d: the current depth of the tree
 * @h: a pointer to an integer representing the height of the tree
 */
void binary_tree_height_rec(const binary_tree_t *tree, size_t d, size_t *h)
{

	if (!tree->left && !tree->right)
	{
		if (d > *h)
			*h = d;
		return;
	}

	if (tree->left)
		binary_tree_height_rec(tree->left, d + 1, h);
	if (tree->right)
		binary_tree_height_rec(tree->right, d + 1, h);
}

/**
 * binary_tree_height - find the height of a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: the height of the tree. 0 is returned if the tree is empty
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h = 0;

	if (!tree)
		return (0);

	binary_tree_height_rec(tree, 0, &h);

	return (h);
}
