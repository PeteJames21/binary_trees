#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_height - find the height of a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: the height of the tree. 0 is returned if the tree is empty
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
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

	left_depth = binary_tree_height(tree->left);
	right_depth = binary_tree_height(tree->right);

	return (left_depth - right_depth);
}

/**
 * binary_tree_is_full - check if a binary tree is full
 * @tree: a pointer to the root node of the tree
 * Return: 1 if the tree is full, 0 otherwise
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

/**
 * is_perfect_recursive - check if all leaf nodes are at the same level
 * @tree: a pointer to the current node
 * @depth: the depth of the tree
 * @level: the current level being checked
 * Return: 1 if all leaf nodes are at the same level, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (depth == level);

	return (
		is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1)
	);
}


/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is perfect, 0 otherwise or if @tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;
	int is_full;

	if (!tree)
		return (0);

	depth = binary_tree_height(tree) - 1;
	is_full = binary_tree_is_full(tree);

	/* Check if all leaf nodes are at the same level */
	return (is_full && is_perfect_recursive(tree, depth, 0));
}
