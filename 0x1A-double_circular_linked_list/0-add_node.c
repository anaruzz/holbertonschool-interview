#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
* add_node_end - Add a node to the end of a double circular linked list
*
* @list: A pointer to the head of the linked list
* @str: A pointer to the srting to copy into the new node
* Return:  Address of the new node, or NULL on failure
*/
List *add_node_end(List **list, char *str)
{
List *new;
if (!list)
return (NULL);
new = malloc(sizeof(List));
if (!new)
return (NULL);
new->str = strdup(str);
if (new->str == NULL)
return (NULL);

if ((*list) != NULL)
{
new->next = (*list);
new->prev = (*list)->prev;
(*list)->prev = new;
new->prev->next = new;
}
if (*list == NULL)
{
new->prev = new;
new->next = new;
(*list) = new;
}
return (new);
}

/**
* add_node_begin - Add node to the beginning of a double circular linked list
*
* @list: A pointer to the head of the linked list
* @str: A pointer to the srting to copy into the new node
* Return:  Address of the new node, or NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
List *new;
if (!list)
return (NULL);

new = malloc(sizeof(List));
if (!new)
return (NULL);

new->str = strdup(str);
if (new->str == NULL)
return (NULL);

if ((*list) != NULL)
{
new->prev = (*list)->prev;
new->next = *list;
(*list)->prev = new;
new->prev->next = new;
}
if (*list == NULL)
{
new->prev = new;
new->next = new;
(*list) = new;
}
*list = new;
return (new);
}
