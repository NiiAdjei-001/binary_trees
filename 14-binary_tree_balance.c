#include "binary_trees.h"

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

	bin_tree_left = bt_height(tree->left);
	bin_tree_right = bt_height(tree->right);
	return (bin_tree_left - bin_tree_right);
}

/**
 * bt_height - custom binary tree heigh function
 * @tree: pointer to root
 * Return: height of tree
*/
size_t bt_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = bt_height(tree->left);
	size_t right_height = bt_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
