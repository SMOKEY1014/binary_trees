#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Creates a binary tree node
 * @parent: Pointer  to the node to insert the left-child in
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new inserted left child node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL); /* Failed to allocate memory */

	new_node->right = NULL;
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = parent->left;

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
