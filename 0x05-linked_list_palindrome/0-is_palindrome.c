#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* is_palindrome - check the code for Holberton School students.
* @head: head of linked list
* Return: 0 or 1.
*/
int is_palindrome(listint_t **head)
{
listint_t *first, *last;

if (!(*head))
return (1);

if (!(*head)->next)
return (1);

last = *head;
while (last->next)
{
last = last->next;
}
first = *head;
while (last >= first)
{
if (first->n == last->n)
{
first = first->next;
last -= 2;
}
else
return (0);
}
return (1);
}
