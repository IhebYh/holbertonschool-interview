#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

void binary_tree_print(const binary_tree_t *);
int heap_extract(binary_tree_t **root);
size_t binary_tree_height(binary_tree_t *root);
void find_replacement(binary_tree_t *root, size_t level, binary_tree_t **last);
void free_and_replace(binary_tree_t **root, binary_tree_t **left,
		      binary_tree_t **right, binary_tree_t **last);
void heapify(binary_tree_t **root, binary_tree_t *current, int *check);

#endif /* _BINARY_TREES_H_ */
