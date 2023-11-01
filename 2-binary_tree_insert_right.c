#include "binary_trees.h"

/**
 * binary_tree_insert_right - func ins. note as righ child
 * @parent: pointer to parent node
 * @value: n value of new node
 *
 * Return: pointer to new node
*/


binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	binary_tree_t *temp;

	new = binary_tree_node(parent, value);
	if (parent->right != NULL)
	{
		temp = parent->right;
		parent->right = new;
		new->right = temp;
		return (new);
	}
	parent->right = new;
	return (new);
}
