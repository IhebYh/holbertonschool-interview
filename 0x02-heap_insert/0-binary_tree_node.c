#include "binary_trees.h"

/**
 * binary_tree_node -  a function that creates a binary tree node
 * @parent: a pointer to the parent node of thenode to create
 * @value: the value to put in the new node
 * Return: NULL or a pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = NULL;

	newNode = malloc(sizeof(binary_tree_t));
	if (newNode == NULL)
		return (NULL);
	newNode->parent = parent;
	newNode->n = value;
	newNode->right = NULL;
	newNode->left = NULL;
	return (newNode);
}
