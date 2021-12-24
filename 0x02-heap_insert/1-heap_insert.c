#include "binary_trees.h"

/**
 * tree_height - Returns height of BT
 * @root: Root
 * Return: Height
 */

size_t tree_height(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + tree_height(root->left) + tree_height(root->right));
}

/**
 * heapify - Heapify function
 * @node: Node
 * Return: Head
 *
 */

heap_t *heapify(heap_t *node)
{
	while (node && node->parent && node->n > node->parent->n)
	{
		node->parent->n -= node->n;
		node->n = node->parent->n + node->n;
		node->parent->n = node->n - node->parent->n;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts in heap
 * @root: Root
 * @value: Value
 * Return: Pointer to node
 */

heap_t *heap_insert(heap_t **root, int value)
{
	ssize_t height = tree_height(*root) + 1;
	int sc = 0;
	heap_t *node = *root;
	heap_t *n_node = NULL;

	n_node = binary_tree_node(node, value);

	if (!n_node)
		return (NULL);

	if (!*root)
		return (*root = n_node);

	for (; 1 << (sc + 1) <= height; sc++)
		;
	for (sc--; sc > 0; sc--)
	{
		if (height & (1 << sc))
			node = node->right;
		else
			node = node->left;
	}

	if (height & 1)
		node->right = n_node;
	else
		node->left = n_node;

	n_node->parent = node;

	return (heapify(n_node));
}

