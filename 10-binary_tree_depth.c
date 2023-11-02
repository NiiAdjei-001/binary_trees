#include "binary_trees.h"

/**
 * binary_tree_depth - function to return depth of node
 * @tree: pointer to node
 *
 * Return: dept of node (size_t)
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *temp;
	size_t count = 0;

	if (!tree)
		return (0);

	temp = tree;

	while (temp->parent != NULL)
	{
		temp = temp->parent;
		count++;
	}
	return (count);
}
