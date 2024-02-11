#include "heap.h"
#include <stdlib.h>

/**
 * @brief: create a generic binary tree node
 *
 * @param parent: pointer to the parent node of the node to be created
 * @param data: data to be stored in the node
 * @return pointer to the created node or null if it fails
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
    binary_tree_node_t *new_node;
    new_node = malloc(sizeof(binary_tree_node_t));
    if (new_node == NULL)
    {
        return (NULL);
    }
    new_node->data = data;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
