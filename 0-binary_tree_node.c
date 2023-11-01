#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: a pointer to the parent node
 * @value: value of node
 * Return: Returns a pointer to the created node.
 **/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	
	new = malloc(sizeof(binary_tree_t));
	/*If node creation fails*/
	if (new == NULL)
		return (NULL);
	/*If parent is NULL*/
	if (parent == NULL)
	{
		new->parent = NULL;
		new->n = value;
		new->left = NULL;
		new->right = NULL;
		return (new);
	}
	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);

}