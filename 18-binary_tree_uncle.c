#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a node
 * @node: a pointer to the node whose sibling is to be found
 * Return: a pointer to the sibling of the node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->right != node)
		return (node->parent->right);

	else
		return (node->parent->left);
}


/**
 * binary_tree_uncle - find the uncle of a node
 * @node: a pointer to the node whose uncle is to be found
 * Return: a pointer to the uncle of the node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
