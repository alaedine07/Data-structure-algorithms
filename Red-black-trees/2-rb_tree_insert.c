#include "rb_trees.h"

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
void left_rotate(rb_tree_t **tree, rb_tree_t *node);
void right_rotate(rb_tree_t **tree, rb_tree_t *node);
void fix_insertion(rb_tree_t **tree, rb_tree_t *node);

/**
 *left_rotate - rotates subtree left
 * @tree: pointer to root node
 * @node: pointer to inserted node.
 */
void left_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *new = node->right;

	if (new == NULL)
		return;
	node->right = new->left;
	if (new->left)
		new->left->parent = node;
	new->left = node;
	new->parent = node->parent;
	if (node->parent == NULL)
		*tree = new;
	else if (node->parent->left == node)
		node->parent->left = new;
	else
		node->parent->right = new;

	node->parent = new;
}

/**
 * right_rotate - rotates subtree right
 * @tree: pointer to root node
 * @node: pointer to inserted node.
 */
void right_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *new = node->left;

	if (new == NULL)
		return;
	node->left = new->right;
	if (new->right)
		new->right->parent = node;
	new->right = node;
	new->parent = node->parent;
	if (node->parent == NULL)
		*tree = new;
	else if (node->parent->left == node)
		node->parent->left = new;
	else
		node->parent->right = new;

	node->parent = new;
}

void fix_insertion(rb_tree_t **tree, rb_tree_t *node)
{
    while (node != NULL && node->parent != NULL && node->parent->color == RED)
    {
        if (node->parent == node->parent->parent->left)
        {
            rb_tree_t* uncle = node->parent->parent->right;

            if (uncle != NULL && uncle->color == RED)
            {
                // Case 1: Uncle is red
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->right)
                {
                    // Case 2: Uncle is black and node is a right child
                    node = node->parent;
                    left_rotate(tree, node);
                }
                // Case 3: Uncle is black and node is a left child
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(tree, node->parent->parent);
            }
        }
        else
        {
            rb_tree_t* uncle = node->parent->parent->left;

            if (uncle != NULL && uncle->color == RED)
            {
                // Case 1: Uncle is red
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    // Case 2: Uncle is black and node is a left child
                    node = node->parent;
                    right_rotate(tree, node);
                }
                // Case 3: Uncle is black and node is a right child
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(tree, node->parent->parent);
            }
        }
    }
    // Ensure that the parent is always black
    (*tree)->color = BLACK;
}

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
    rb_tree_t *current;

    if (!(*tree))
    {
        *tree = rb_tree_node(NULL, value, BLACK);
        return *tree;
    }
    current = *tree;
    while (current)
    {
        if (current->n == value)
        {
            break;
        }
        if (current->n < value)
        {
            if (current->right == NULL)
            {
                current->right = rb_tree_node(current, value, RED);
                fix_insertion(tree, current->right);
                return (current);
            }
            current = current->right;
        }
        else if (current->n > value)
        {
            if (current->left == NULL)
            {
                current->left = rb_tree_node(current, value, RED);
                fix_insertion(tree, current->left);
                return (current);
            }
            current = current->left;
        }
    }
    return (NULL);
}
