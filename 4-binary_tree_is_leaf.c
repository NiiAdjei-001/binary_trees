#include "binary_trees.h"

/**
 * binary_tree_is_leaf - func checks if node is leaf
 * @node: node pointer
 * Return: 1 if leaf / 0 if not
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
		else
		return (0);
}
