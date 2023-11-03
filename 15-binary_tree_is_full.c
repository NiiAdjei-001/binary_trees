#include "binary_trees.h"

/**
 * state_tracer - Traverse binary tree and check state (is_full)
 * @tree: the tree node to initiate tracing from
 * @cursor: a pointer to the currently traversed node.
 * @state: a pointer to the state
 * Return: void.
 */
void state_tracer(const binary_tree_t *tree,
				  const binary_tree_t *cursor,
				  size_t *state)
{
	if (tree == NULL)
	{
		*state = 0;
		return;
	}
	if (cursor->left != NULL)
	{
		/* Left Traverse*/
		state_tracer(tree, cursor->left, state);
	}
	if (cursor->right != NULL)
	{
		/* Right Traverse*/
		state_tracer(tree, cursor->right, state);
	}
	if ((cursor->left == NULL && cursor->right == NULL) ||
		(cursor->left != NULL && cursor->right != NULL))
	{
		/* if current node has 0 or 2 child nodes keep state on*/
		*state *= 1;
	}
	else
	{
		/* if current node has 1 child nodes toggles state to off*/
		*state *= 0;
	}
	if (cursor == tree)
	{
		/* Terminate at root node*/
		return;
	}
	if (cursor->parent->left)
		return; /* Escape left child node*/
	else if (cursor->parent->right)
		return; /* Escape left child node*/
}

/**
 * binary_tree_is_full - Checks if binary tree is full
 * @tree: pointer to a node of a tree
 * Return: Return 1 if full else 0 .
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t state = 1;

	state_tracer(tree, tree, &state);
	return (state);
}
