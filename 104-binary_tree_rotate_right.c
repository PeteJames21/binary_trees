#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_rotate_right - rotate a binary tree to the right
 * @tree: a pointer to the root node
 * Return: a pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *old_root, *old_left;

	if (!tree || !tree->left)
		return (NULL);

	old_root = tree;
	old_left = tree->left;

	/* Make old_left the new root */
	old_left->parent = NULL;
	/* Make the right node of old_left the left node of old_root */
	old_root->left = old_left->right;
	if (old_left->right)
		old_left->right->parent = old_root;
	/* Make old_root the right node of the new root (old_left) */
	old_left->right = old_root;
	old_root->parent = old_left;

	return (old_left);
}

