#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - insert node as the left-child
 * @parent: a pointer to the parent node
 * @value: the value of the new child
 * Return: a pointer to the newly added child node
 *
 * Description: If @parent already has a right-child, the new node takes
 * its place, and the old right-child must be set as the right-child of
 * the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
