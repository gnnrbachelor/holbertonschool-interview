#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>


#define max(a, b) (a > b ? a : b)

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s heap_t;


int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *);
void heapify(heap_t *node);
int get_height(heap_t *root, int height);
heap_t *get_last(heap_t *node, int height, int level);


#endif /* _BINARY_TREES_H_ */
