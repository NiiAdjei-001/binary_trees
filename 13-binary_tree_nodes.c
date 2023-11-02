#include "binary_trees.h"

/**
 * nodes_tracer - Gets the count of nodes in a tree with atleast 1 child.
 * @tree: the tree node to initiate tracing from
 * @cursor: a pointer to the currently traversed node.
 * @count: a pointer to the counter
 * Return: void.
 */
void nodes_tracer(const binary_tree_t *tree,
				  const binary_tree_t *cursor,
				  size_t *count)
{
	if (tree == NULL)
		return;
	if (cursor->left != NULL)
	{
		/* Left Traverse*/
		nodes_tracer(tree, cursor->left, count);
	}
	if (cursor->right != NULL)
	{
		/* Right Traverse*/
		nodes_tracer(tree, cursor->right, count);
	}
	if (cursor == tree)
	{
		/* Count root as a none leaf if it has branches*/
		if (!(cursor->left == NULL && cursor->right == NULL))
			*count += 1;
		return;
	}
	if (!(cursor->left == NULL && cursor->right == NULL))
	{
		/* Check if cursor is a none leaf node then increment*/
		*count += 1;
	}
	if (cursor->parent->left)
	{
		/* Check if current node has a left sibling*/
		return;
	}
	else if (cursor->parent->right)
	{
		/* Check if current node has a right sibling*/
		return;
	}
}

/**
 * binary_tree_nodes - Gets the number of nodes that have atleast 1 child
 * @tree: pointer to root of tree
 * Return: No of none leaf nodes in a tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	nodes_tracer(tree, tree, &count);
	return (count);
}
