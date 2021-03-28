#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
* *binary_tree_node - builds an AVL tree from an array
*
* @parent: The array to be printed
* @value: value to insert in node
*
* Return: binary tree on success, NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_node = NULL;

new_node = malloc(sizeof(binary_tree_t));
if (!new_node)
return (NULL);

new_node->parent = parent;
new_node->left = new_node->right = NULL;
new_node->n = value;

return (new_node);
}

/**
* node_insert - insert nodes recursively
* @parent: parent of the node to be inserted
* @array: The array to take data from
* @start: start index
* @end: end index
* Return: node on success, NULL on failure
*/
avl_t *node_insert(avl_t *parent, int *array, int start, int end)
{
int mid;
avl_t *node;

if (start > end)
return (NULL);
mid = (start + end) / 2;
node = binary_tree_node(parent, array[mid]);

node->left = node_insert(node, array, start, mid - 1);
node->right = node_insert(node, array, mid + 1, end);

return (node);
}

/**
* sorted_array_to_avl - buils AVL tree from an array
*
* @array: The array to take data from
* @size: Size of the array
* Return: avl tree on success, NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
size_t end = size - 1, mid;
avl_t *root;

if (!array)
return (NULL);
mid = end / 2;

root = binary_tree_node(NULL, array[mid]);
if (!root)
return (NULL);

root->left = node_insert(root, array, 0, mid - 1);
root->right = node_insert(root, array, mid + 1, end);

return (root);
}
