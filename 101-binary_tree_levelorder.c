#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary
 * tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses the binary tree rooted at @tree using
 * level-order traversal and calls the function @func for each visited node.
 * The value in each node is passed as a parameter to the function @func.
 * If @tree or @func is NULL, the function does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Create a queue to store nodes */
	int size_tree = sizeof(binary_tree_t *) * binary_tree_height(tree);
	binary_tree_t **queue = malloc(size_tree);

	if (queue == NULL)
		return;

	int front = 0, rear = 0;

	queue[rear++] = (binary_tree_t *)tree;

	/* Loop until the queue is empty */
	while (front < rear)
	{
		/* Dequeue a node */
		const binary_tree_t *current = queue[front++];

		/* Call the function for the current node */
		func(current->n);

		/* Enqueue the left child if exists */
		if (current->left != NULL)
			queue[rear++] = current->left;

		/* Enqueue the right child if exists */
		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}
