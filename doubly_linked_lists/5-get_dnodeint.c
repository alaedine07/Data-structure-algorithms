#include "lists.h"
/**
 * get_dnodeint_at_index - function that returns the nth node
 * of a dlistint_t linked list.
 *@head: pointer to the first node of the list.
 *@index: the index of the node.
 * Return: pointer to the new node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i = 0;
	int found = 0;

	if (index == 0)
	{
		return (head);
	}
	current = head;
	while (current != NULL && !found)
	{
		if (i == index)
		{
			found = 1;
		}
		else
		{
			i++;
			current = current->next;
		}
	}
	if (found == 0)
	{
		return (NULL);
	}
	else
	{
		return (current);
	}
}
