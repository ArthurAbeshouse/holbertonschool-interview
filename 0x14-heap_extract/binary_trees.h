#ifndef BINARY_TREES
#define BINARY_TREES

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

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
size_t binary_height_recursion(heap_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
heap_t *push_to_top(heap_t *node);
void binary_tree_print(const binary_tree_t *root);
void heapify_down(heap_t *node);
size_t binary_tree_height(heap_t *tree);

#endif
