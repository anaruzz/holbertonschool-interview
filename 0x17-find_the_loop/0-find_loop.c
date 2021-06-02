#include "lists.h"

/**
* find_listint_loop - finds cycle in a linked list
* @head: head of the list
* Return: node of cycle or NULL on failure
*/

listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow, *fast;

if (!head)
return (NULL);

fast = head;
slow = head;
while (slow && fast && fast->next)
{
if (slow->next)
slow = slow->next;
if (fast->next && fast->next->next)
fast = fast->next->next;
else
return (NULL);
if (slow == fast)
{
slow = head;
while (slow && fast && fast->next)
{
if (slow == fast)
return (slow);
slow = slow->next;
fast = fast->next;
}
}
}
return (NULL);
}
