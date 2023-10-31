#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - insert node as the left-child
 * @parent: a pointer to the parent node
 * @value: the value of the new child
 * Return: a pointer to the newly added child node, or NULL on error
 *
 * Description: If @parent already has a left-child, the new node takes
 * its place, and the old left-child must be set as the left-child of
 * the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->n = value;

	if (parent->left)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
