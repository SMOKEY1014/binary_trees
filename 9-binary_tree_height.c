#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* If tree is NULL, return height 0 */
	if (tree == NULL)
		return (0);

	/* Recursively calculate the height of the left and right subtrees */
	size_t height_left = binary_tree_height(tree->left);
	size_t height_right = binary_tree_height(tree->right);

	/*
    * Return the maximum height of the left and right subtrees,
    * plus 1 for the current node
    */
	return (height_left > height_right ? height_left + 1 : height_right + 1);
}
