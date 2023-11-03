#include "binary_trees.h"

/**
 * binary_tree_delete - Delete a tree.
 * @tree: a pointer to the parent node
 * Return: void.
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{

		if (tree->left != NULL)
		{
			binary_tree_delete(tree->left);
		}
		if (tree->right != NULL)
		{
			binary_tree_delete(tree->right);
		}
		if (tree->parent == NULL)
		{
			free(tree);
			return;
		}
		if (tree->parent->left)
		{
			tree->parent->left = NULL;
			free(tree);
			return;
		}
		else if (tree->parent->right)
		{
			tree->parent->right = NULL;
			free(tree);
			return;
		}
	}
}
