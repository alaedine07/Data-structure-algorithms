#include "rb_trees.h"

/**
	* rb_tree_is_valid - check if red black tree is valid
	* @tree: head node of the tree
	* Return: 1 if tree is RB 0 if not
*/
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (tree == NULL || !tree->color)
	{
		return (0);
	}
	if (tree->color)
	{
		if ((tree->parent && tree->parent->color == tree->color) \
			|| (tree->left && tree->left->color == tree->color) \
			|| (tree->right && tree->right->color == tree->color))
		{
			return (0);
		}
	}
	if (tree->left && !tree->right)
		return (0);
	if (!tree->left && tree->right)
		return (0);

	return (rb_tree_is_valid(tree->right) && rb_tree_is_valid(tree->left));
}
