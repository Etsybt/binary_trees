#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *f = first;
	const binary_tree_t *s = second;

	while (f != NULL)
	{
		s = second;

		while (s != NULL)
		{
			if (f == s)
				return ((binary_tree_t *)f);

			s = s->parent;
		}
		f = f->parent;
	}
	return (NULL);
}
