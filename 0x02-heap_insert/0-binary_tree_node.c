#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_node - Create a binary tree node
* @parent: parent of the node
* @value: value of the node
* Return: Always 0 (Success)
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node;
node = malloc(sizeof(binary_tree_t));
if (!node)
return (NULL);
node->n = value;
node->parent = parent;
node->right = NULL;
node->left = NULL;
return (node);
}
