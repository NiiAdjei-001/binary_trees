#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse binary tree root-left-right
 * @tree: pointer to root node
 * @func: function pointer to process node n value
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
