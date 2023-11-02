#include "binary_trees.h"

/**
 * binary_tree_delete - Delete a tree.
 * @tree: a pointer to the parent node
 * Return: void.
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		binary_tree_delete(tree->left);
	if (tree->right != NULL)
		binary_tree_delete(tree->right);
	if (tree->left == NULL)
	{
		if (tree->right == NULL)
		{
			tree->parent->left = NULL;
			tree->parent = NULL;
			free(tree);
			return;
		}
	}
	if (tree->right == NULL)
	{
		if (tree->left == NULL)
		{
			tree->parent->right = NULL;
			tree->parent = NULL;
			free(tree);
			return;
		}
	}
	free(tree);
}
