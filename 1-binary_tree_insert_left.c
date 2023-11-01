#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child.
 * @parent: a pointer to the parent node
 * @value: value of node
 * Return: Returns a pointer to the created node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = binary_tree_node(parent, value);
	binary_tree_t *temp;

	if (new == NULL)
		return (NULL);
	if (parent == NULL)
	{
		free(new);
		return (NULL);
	}
	if (parent->left == NULL)
	{
		parent->left = new;
		return (new);
	}
	temp = parent->left;
	parent->left = new;
	new->left = temp;
	temp->parent = new;
	return (new);
}
