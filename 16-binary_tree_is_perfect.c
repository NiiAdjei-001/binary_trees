#include "binary_trees.h"

/**
 * height_tracer - Gets the height of a tree.
 * @tree: the tree node to initiate tracing from
 * @cursor: a pointer to the currently traversed node.
 * @count: a pointer to the counter
 * @height: a pointer to the height value
 * Return: void.
 */
void height_tracer(const binary_tree_t *tree,
				   const binary_tree_t *cursor,
				   size_t *count,
				   size_t *height)
{
	if (tree == NULL)
		return;
	if (cursor->left != NULL)
	{
		*count += 1;
		if (*count > *height)
			*height = *count;
		height_tracer(tree, cursor->left, count, height);
	}
	if (cursor->right != NULL)
	{
		*count += 1;
		if (*count > *height)
			*height = *count;
		height_tracer(tree, cursor->right, count, height);
	}
	if (cursor == tree)
		return;
	if (cursor->parent->left)
	{
		*count -= 1;
		return;
	}
	else if (cursor->parent->right)
	{
		*count -= 1;
		return;
	}
}

/**
 * full_state_tracer - Traverse binary tree and check state (is_full)
 * @tree: the tree node to initiate tracing from
 * @cursor: a pointer to the currently traversed node.
 * @state: a pointer to the state
 * Return: void.
 */
void full_state_tracer(const binary_tree_t *tree,
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
		full_state_tracer(tree, cursor->left, state);
	}
	if (cursor->right != NULL)
	{
		/* Right Traverse*/
		full_state_tracer(tree, cursor->right, state);
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
 * leaves_state_tracer - Traverse binary tree and check if leaves are same gen
 * @tree: the tree node to initiate tracing from
 * @cursor: a pointer to the currently traversed node.
 * @count: a pointer to the counter
 * @height: a pointer to the height value
 * @state: a pointer to the state
 * Return: void.
 */
void leaves_state_tracer(const binary_tree_t *tree,
						 const binary_tree_t *cursor,
						 size_t *count,
						 size_t *height,
						 size_t *state)
{
	if (tree == NULL)
	{
		*state *= 0;
		return;
	}
	if (cursor->left != NULL)
	{
		/* Left Traverse*/
		*count += 1;
		/*printf("before left traverse state: %ld\n", *state);*/
		leaves_state_tracer(tree, cursor->left, count, height, state);
	}
	if (cursor->right != NULL)
	{
		/* Right Traverse*/
		*count += 1;
		/*printf("before right traverse state: %ld\n", *state);*/
		leaves_state_tracer(tree, cursor->right, count, height, state);
	}
	if (cursor->left == NULL && cursor->right == NULL && *count == *height)
	{
		/*Checks if node is a leaf and if leaf is at height level*/
		*state *= 1; /* maintains state as valid*/
	}
	else if (cursor->left == NULL && cursor->right == NULL && *count != *height)
	{
		*state *= 0; /* toggle off state if condition fails*/
	}
	if (cursor == tree)
		return; /* Terminate at root node*/
	if (cursor->parent->left)
	{
		*count -= 1;
		return; /* Escape left child node*/
	}
	else if (cursor->parent->right)
	{
		*count -= 1;
		return; /* Escape right child node*/
	}
}

/**
 * binary_tree_is_perfect - Checks if binary tree is perfect
 * @tree: pointer to a node of a tree
 * Return: Return 1 if perfect else 0 .
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/**
	 * Condition for perfect tree is
	 * - Tree must be full
	 * - Tree leaves must be at the same height
	 */

	size_t count = 0;		 /* Use to generate height*/
	size_t height = 0;		 /* Height of tree */
	size_t leaves_state = 1; /* State of leaves being in same gen*/
	size_t full_state = 1;	 /*State of tree being full*/

	height_tracer(tree, tree, &count, &height);
	count = 0;
	leaves_state_tracer(tree, tree, &count, &height, &leaves_state);
	full_state_tracer(tree, tree, &full_state);
	/* printf("leaves_state_tracer %ld\n", leaves_state);*/
	/* printf("full_state_tracer %ld\n", full_state);*/
	return (leaves_state * full_state);
}
