#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* insert_node - insert number into a sorted signly linked list
* @head: head of list
* @number: number to be inserted
* Return: Always 0.
*/

listint_t *insert_node(listint_t **head, int number)
{
listint_t *new, *temp;

if (head == NULL)
return (NULL);

new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);

new->n = number;

if (*head == NULL)
{
new->next = NULL;
*head = new;
return (*head);
}

temp = *head;
if (new->n < temp->n)
{
new->next = *head;
*head = new;
return (*head);
}

while (temp->next != NULL && (new->n > temp->next->n))
{
temp = temp->next;
}
new->next = temp->next;
temp->next = new;

return (*head);
}
