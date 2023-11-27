#include <stddef.h>
#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree)
{
    // Check if the tree is NULL
    if (tree == NULL)
        return 0;

    // Calculate the height of the tree
    size_t height = binary_tree_height(tree);

    // Check if the tree is perfect
    return is_perfect_recursive(tree, height, 0);
}

/**
 * binary_tree_height - Calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * is_perfect_recursive - Helper function to check if a tree is perfect recursively
 * @tree: Pointer to the node being checked
 * @height: Height of the tree
 * @level: Current level of the node
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t height, size_t level)
{
    // Check if the tree is NULL
    if (tree == NULL)
        return 1;

    // Check if the current node is a leaf node
    if (tree->left == NULL && tree->right == NULL)
        return (height == level + 1);

    // Check if the current node has both left and right children
    if (tree->left == NULL || tree->right == NULL)
        return 0;

    // Recursively check the left and right subtrees
    return is_perfect_recursive(tree->left, height, level + 1) &&
           is_perfect_recursive(tree->right, height, level + 1);
}
