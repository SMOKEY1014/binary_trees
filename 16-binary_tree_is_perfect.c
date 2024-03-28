#include "binary_trees.h"
#include "14-binary_tree_balance.c"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect = 0;

	if (tree)
	{
		is_perfect = 1;
		if (binary_tree_balance(tree) != 0)
			return (0);
		if (tree->left)
			is_perfect *= binary_tree_is_perfect(tree->left);
		if (tree->right)
			is_perfect *= binary_tree_is_perfect(tree->right);
	}
	return (is_perfect);
}
