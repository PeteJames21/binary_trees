#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_rotate_left - rotate a binary tree to the left
 * @tree: a pointer to the root node
 * Return: a pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root, *old_right;

	if (!tree || !tree->right)
		return (NULL);



	old_root = tree;
	old_right = tree->right;

	/* Make old_right the new root */
	old_right->parent = NULL;
	/* Make the left node of old_right the right node of old_root */
	old_root->right = old_right->left;
	if (old_right->left)
		old_right->left->parent = old_root;
	/* Make old_root the left node of the new root (old_right) */
	old_right->left = old_root;
	old_root->parent = old_right;

	return (old_right);
}

