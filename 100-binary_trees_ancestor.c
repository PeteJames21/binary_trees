#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_trees_ancestor - find the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor or NULL if none exists
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second
)
{
	const binary_tree_t *tmp;

	if (!first || !second)
		return (NULL);

	while (first)
	{
		tmp = second;
		while (tmp)
		{
			if (tmp == first)
				return ((binary_tree_t *)first);
			tmp = tmp->parent;
		}
		first = first->parent;
	}

	return (NULL);
}
