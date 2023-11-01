#include "binary_trees.h"

/**
 * depth - find the depth of a binary tree
 * @tree: a pointer to the root node
 * Return: the balance factor of the tree. 0 if the @tree is NULL
 */
int depth(const binary_tree_t *tree)
{
	int left_depth;
	int right_depth;

	if (!tree)
		return (0);

	left_depth = depth(tree->left);
	right_depth = depth(tree->right);

	if (left_depth > right_depth)
		return (left_depth + 1);
	else
		return (right_depth + 1);
}

/**
 * binary_tree_balance - find the balance factor of a binary tree
 * @tree: a pointer to the root node
 * Return: the balance factor of the tree. 0 if the @tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_depth;
	int right_depth;

	if (!tree)
		return (0);

	left_depth = depth(tree->left);
	right_depth = depth(tree->right);

	return (left_depth - right_depth);
}
