#include "binary_trees.h"

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


/**
 * binary_tree_balance - func measures balance factor of tree
 * @tree: pointer to root node of a tree
 * Return: (int) balance factor
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	int bin_tree_left;
	int bin_tree_right;

	bin_tree_left = binary_tree_height(tree->left);
	bin_tree_right = binary_tree_height(tree->right);
	return (bin_tree_left - bin_tree_right);
}
