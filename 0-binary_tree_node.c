#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Create a new binary tree node
 * @parent: a pointer to the parent of the node or NULL if creating the root
 * @value: the value of the node
 * Return: a pointer to the newly created node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
