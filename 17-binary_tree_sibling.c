#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds sibling of a node
 * @node: pointer to a node of a tree
 * Return: Return sibling node. NULL if no sibling present.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node->parent->left != node && node->parent->left != NULL)
		return (node->parent->left);
	if (node->parent->right != node && node->parent->right != NULL)
		return (node->parent->right);
	return (NULL);
}
