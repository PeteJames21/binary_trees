#include "binary_trees.h"

/**
 * binary_tree_is_full - check if a binary tree is full
 * @tree: a pointer to the root node of the tree
 * Return: 1 if the tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int right_is_full;
	int left_is_full;

	if (!tree)
		return (0);

	if (tree->left && tree->right)
	{
		left_is_full = binary_tree_is_full(tree->left);
		right_is_full = binary_tree_is_full(tree->right);
		/* Result is 0 if not full, else 1 */
		return (left_is_full * right_is_full);
	}

	if (!tree->left && !tree->right)
		return (1);

	return (0);  /* The node has only one child */
}
