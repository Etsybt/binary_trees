#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *        The value in the node is passed as a parameter to this function
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, *temp;
	int x = 0, m = 0;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
		return;

	temp = (binary_tree_t *)tree;

	queue[m++] = temp;

	while (x < m)
	{
		temp = queue[x++];
		func(temp->n);

		if (temp->left != NULL)
			queue[m++] = temp->left;

		if (temp->right != NULL)
			queue[m++] = temp->right;
	}
	free(queue);
}

