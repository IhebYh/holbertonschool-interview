#include "binary_trees.h"

/**
 * _sort - a function that sorts a binary tree
 *
 * @node : node
 * Return : void
 */
void _sort(heap_t *node)
{
	size_t tmp = 0;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->parent->n;
		node->parent->n = node->n;
		node->n = tmp;
		node = node->parent;
	}
}

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap
 *
 * @root : double pointer to the root node of the Heap
 * @value : a value to store in the node to be inserted
 * Return: heap_t* or null
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t level, i;
	heap_t *node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node((binary_tree_t *)*root, value);
		return (*root);
	}
	level = binary_tree_height(*root);
	for (i = 0; i <= level; i++)
	{
		node = (heap_t *)_insert((binary_tree_t *)*root, i, value);
		if (node != NULL)
			break;
	}
	_sort(*node);
	return (node);
}
