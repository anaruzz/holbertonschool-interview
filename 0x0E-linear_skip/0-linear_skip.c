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
skiplist_t *tmp;
skiplist_t *prev;
char *p1 = "Value checked at index";
char *p2 = "Value found between indexes";

if (!list)
return (NULL);

prev = list;
tmp = list->express;
while (tmp)
{
printf("%s [%lu] = [%d]\n", p1, tmp->index, tmp->n);
if (tmp->n >= value)
break;
prev = tmp;
if (!tmp->express)
{
while (tmp->next)
tmp = tmp->next;
break;
}
tmp = tmp->express;
}
printf("%s [%lu] and [%lu]\n", p2, prev->index, tmp->index);
while (prev && prev->index <= tmp->index)
{
printf("%s [%lu] = [%d]\n", p1, prev->index, prev->n);
if (prev->n == value)
return (prev);
prev = prev->next;
}
return (NULL);
}
