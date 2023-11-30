#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	 binary_tree_t *root;
	 size_t i = 0;

	 if (array == NULL || size == 0)
		 return (NULL);

	 root = NULL;

	 for (; i < size; i++)
		 bst_insert(&root, array[i]);

	 return (root);
}
