#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
* linear_skip - searches for a value in a skiplist
*
* @list: Pointer to the head of the list
* @value: value to search for
* Return: void
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *tmp, *prev;

if (!list)
return (NULL);

prev = list;
tmp = list->express;
while (tmp != NULL)
{
printf("Value checked at index [%li] = [%d]\n", tmp->index, tmp->n);
if (tmp->n >= value)
  break;
prev = tmp;
if (tmp->express == NULL)
{
while (tmp->next)
tmp = tmp->next;
break;
}
tmp = tmp->express;
}

printf("Value found between indexes [%lu] and [%i]\n", prev->index, prev->n);

while (prev && (prev->index <= tmp->index))
{
printf("Value checked at index [%lu] = [%i]\n", prev->index, prev->n);
if (prev->n == value)
return (prev);
prev = prev->next;
}
return (NULL);
}
