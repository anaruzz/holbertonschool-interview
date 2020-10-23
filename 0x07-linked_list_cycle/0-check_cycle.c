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
const listint_t *fast, *slow, *first;

if (!list)
return (0);

if (!list->next)
return (0);

first = list;
slow = list->next;
fast = list->next->next;
while (fast && slow && fast->next)
{
if (slow == fast || first == slow)
return (1);
else
{
slow = slow->next;
fast = fast->next->next;
}
}
return (0);
}
