#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - Extracts from heap
 * @root: Root
 * Return: value stored at root
 */

int heap_extract(heap_t **root)
{
	int num, height;
	heap_t *last;

	if (!root || !*root)
		return (0);

	num = (*root)->n;
	height = get_height(*root, 1);

	if (height == 1)
	{
		last = *root;
		*root = NULL;
	}
	else
	{
		last = get_last(*root, height, 1);
		(*root)->n = last->n;
		if (last->parent->right == last)
			last->parent->right = NULL;
		else
			last->parent->left = NULL;
	}
	free(last);
	heapify(*root);
	return (num);

}

/**
 * heapify - Corrects Heap
 * @node: Root node
 * Return: Void
 */

void heapify(heap_t *node)
{
	heap_t *largest;
	int n;

	if (!node)
		return;

	largest = node;

	if (node->left && node->left->n >= largest->n)
		largest = node->left;

	if (node->right)
	{
		if (largest == node->left && node->right->n > largest->n)
			largest = node->right;
		else if (node->right->n >= largest->n)
			largest = node->right;
	}

	if (largest != node)
	{
		n = node->n;
		node->n = largest->n;
		largest->n = n;
		heapify(largest);
	}

}

/**
 * get_height - Gets height
 * @root: Root
 * @height: Height
 * Return: height
 */

int get_height(heap_t *root, int height)
{
	int left, right;

	if (root == NULL)
		return (height - 1);

	left = get_height(root->left, height + 1);
	right = get_height(root->right, height + 1);

	return (max(left, right));
}

/**
 * get_last - Gets last
 * @node: Node
 * @height: Height
 * @level: Level
 * Return: Pointer to last node
 */


heap_t *get_last(heap_t *node, int height, int level)
{
	heap_t *temp;

	if (!node)
		return (NULL);

	if (level >= height - 1)
		return (node->right ? node->right : node->left);

	temp = get_last(node->right, height, level + 1);

	if (temp)
		return (temp);

	return (get_last(node->left, height, level + 1));
}

