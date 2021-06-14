#include <stdlib.h>
#include "binary_trees.h"

/**
* swap_nodes - swap two nodes
* node1 - node 1
* node 2 - node 1
* Return: void
*/
// void swap_nodes(int a, int b)
// {
//   int temp;
//   temp = a;
//   a = b;
//   b = temp;
// }

/**
* heap_insert - insert value into a Max Binary Heap
* @root: root node of the heap
* @value: value of the node
* Return: Pointer to the inserted node or NULL
*/
heap_t* heap_insert(heap_t **root, int value)
{

  if (*root == NULL)
  {
    *root = binary_tree_node(NULL, value);
  }
  else if (value < (*root)->n)
  {
    (*root)->left = heap_insert(&((*root)->left), value);
  }
  else
  {
  (*root)->right = heap_insert(&((*root)->right), value);
  }
  return (*root) ;
}
