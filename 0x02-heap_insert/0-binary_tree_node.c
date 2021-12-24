#include "binary_trees.h"

/**
 * binary_tree_node - Makes node on bt
 * @parent: Parent
 * @value: value
 * Return: Pointer to new node
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
