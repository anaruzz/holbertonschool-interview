#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* check_cycle - prints all elements of a listint_t list
* @list: pointer to head of list
* Return: 0 or 1
*/
int check_cycle(listint_t *list)
{
const listint_t *first;

if (!list)
return (0);

first = list;
while (list->next->next)
{
if (list->next != first)
{
list = list->next->next;
}
else
return (1);
}
return (0);
}
