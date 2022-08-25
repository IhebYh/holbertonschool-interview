#include "binary_trees.h"
/**
 * binary_tree_is_leaf - check node leaf or not
 * @node: node to check
 * Return: 1 if node if leaf 0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
/**
 * binary_tree_depth - a function that measures
 * the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 * Return:size_t
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);
	if (tree->parent == NULL)
		return (0);
	depth = binary_tree_depth(tree->parent);

	return (depth + 1);
}
/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: is pointer to the root node of the tree to measure the height
 * Return: size_t
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_height, left_height;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
/**
* binary_tree_is_none - checks if a node is a leaf
* @node: parent node
* Return: pointer to the new node
*/

int binary_tree_is_none(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
/**
* _insert - function to insert node
* @tree: pointer to tree
* @level: level to insert node
* @value: value of the new node
* Return: the node inserted
*/

binary_tree_t *_insert(binary_tree_t *tree, size_t level, int value)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (NULL);
	if (binary_tree_depth(tree) == level)
	{
		if (binary_tree_is_none(tree))
			return (tree->left = binary_tree_node(tree, value));
		if (tree->left != NULL && tree->right == NULL)
			return (tree->right = binary_tree_node(tree, value));
		return (NULL);
	}
	left = _insert(tree->left, level, value);
	if (left == NULL)
		right = _insert(tree->right, level, value);
	else
		return (left);
	return (right);
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
	size_t level, i, tmp = 0;
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
	//_sort(node);
	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->parent->n;
		node->parent->n = node->n;
		node->n = tmp;
		node = node->parent;
	}
	return (node);
}
