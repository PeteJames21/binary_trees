#include "binary_trees.h"

/**
 * binary_tree_inorder - apply a function to all nodes of a binary tree
 * @tree: a pointer to the root node of the binary tree
 * @func: a pointer to the function to be applied to each node
 *
 * Description - the tree is traversed in in-order fashion. No error occurs
 * if the @tree or @func is NULL
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
