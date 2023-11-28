#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);

	right = binary_tree_height(tree->right);

	return (1 + ((left > right) ? left : right));

}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);

	right = binary_tree_height(tree->right);

	return ((int)(left - right));
}
