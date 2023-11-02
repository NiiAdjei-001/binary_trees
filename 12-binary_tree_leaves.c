#include "binary_trees.h"

/**
 * binary_tree_leaves - Function counts no. of leaf nodes in tree
 * @tree: pointer to root of tree
 * Return: No of leaf nodes in tree
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
		++count;
	count += binary_tree_leaves(tree->left);
	count += binary_tree_leaves(tree->right);

	return (count);
}

