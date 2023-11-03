#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds uncle of a node
 * @node: pointer to a node of a tree
 * Return: Return uncle node. NULL if no uncle present.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
    if (node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left != node->parent && 
        node->parent->parent->left != NULL)
		return (node->parent->parent->left);
	if (node->parent->parent->right != node->parent && 
        node->parent->parent->right != NULL)
		return (node->parent->parent->right);
	return (NULL);
}
