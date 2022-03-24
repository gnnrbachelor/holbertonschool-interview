#include "binary_trees.h"

/**
 * create_node - Creates node
 * @parent: Parent
 * @n: data
 * Return: pointer to node
 */

avl_t *create_node(avl_t *parent, size_t n)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (node == NULL && parent == NULL)
		return (NULL);

	node->n = n;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * insert_node - Inserts node
 * @array: Array
 * @start: Start
 * @end: End
 * @root: Root
 * Return: root
 */

avl_t *insert_node(int *array, size_t start, size_t end, avl_t *parent)
{

	size_t mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_node(parent, array[mid]);

	if (!root)
		return (NULL);

	if (start != mid)
		root->left = insert_node(array, start, mid - 1, root);

	if (mid != end)
		root->right = insert_node(array, mid + 1, end, root);

	return (root);

}

/**
 * sorted_array_to_avl - Creates avl from array
 * @array: Array
 * @size: Size
 * Return: root
 *
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	root = insert_node(array, 0, size - 1, NULL);

	return (root);
}

