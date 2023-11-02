#include "binary_trees.h"

/**
 * size_tracer - Gets the size of a tree.
 * @tree: the tree node to initiate tracing from
 * @cursor: a pointer to the currently traversed node.
 * @count: a pointer to the counter
 * Return: void.
 */
void size_tracer(const binary_tree_t *tree,
				  const binary_tree_t *cursor,
				  size_t *count)
{
	if (tree == NULL)
		return;
	if (cursor->left != NULL)
	{
		*count += 1;
		size_tracer(tree, cursor->left, count);
	}
	if (cursor->right != NULL)
	{
		*count += 1;
		size_tracer(tree, cursor->right, count);
	}
	if (cursor == tree)
	{
		*count += 1;
		return;
	}
	if (cursor->parent->left)
		return;
	else if (cursor->parent->right)
		return;
}

/**
 * binary_tree_size - function to return size of a tree
 * @tree: pointer to node
 *
 * Return: dept of node (size_t)
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	size_tracer(tree, tree, &count);
	return (count);
}
