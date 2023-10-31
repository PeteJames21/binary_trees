#include "binary_trees.h"

/**
 * binary_tree_preorder - apply a function to all nodes of a binary tree
 * @tree: a pointer to the root node of the binary tree
 * @func: a pointer to the function to be applied to each node
 *
 * Description - the tree is traversed in preorder fashion. No error occurs
 * if the @tree or @func is NULL
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
