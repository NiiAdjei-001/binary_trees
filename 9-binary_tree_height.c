#include "binary_trees.h"

/**
 * height_tracer - Gets the height of a tree.
 * @tree: the tree node to initiate tracing from
 * @cursor: a pointer to the currently traversed node.
 * @count: a pointer to the counter
 * @height: a pointer to the height value
 * Return: void.
 */
void height_tracer(const binary_tree_t *tree,
				  const binary_tree_t *cursor,
				  size_t *count,
				  size_t *height)
{
	if (tree == NULL)
		return;
	if (cursor->left != NULL)
	{
		*count += 1;
		if (*count > *height)
			*height = *count;
		height_tracer(tree, cursor->left, count, height);
	}
	if (cursor->right != NULL)
	{
		*count += 1;
		if (*count > *height)
			*height = *count;
		height_tracer(tree, cursor->right, count, height);
	}
	if (cursor == tree)
		return;
	if (cursor->parent->left)
	{
		*count -= 1;
		return;
	}
	else if (cursor->parent->right)
	{
		*count -= 1;
		return;
	}
}

/**
 * binary_tree_height - function to return height of tree
 * @tree: pointer to node
 *
 * Return: dept of node (size_t)
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count = 0;
	size_t height = 0;

	height_tracer(tree, tree, &count, &height);
	return (height);
}
