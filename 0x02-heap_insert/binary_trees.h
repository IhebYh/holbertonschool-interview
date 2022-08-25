#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>


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

void binary_tree_print(const binary_tree_t *s);
heap_t *heap_insert(heap_t **root, int value);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *_insert(binary_tree_t *tree, size_t level, int value);
int binary_tree_is_none(const binary_tree_t *node);
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
void _sort(heap_t *node);

#endif /* _BINARY_TREES_H_ */
