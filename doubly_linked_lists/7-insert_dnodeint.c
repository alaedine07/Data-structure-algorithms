#include "lists.h"
/**
 * insert_dnodeint_at_index - function that inserts a new node
 * at a given position.
 * @h: pointer to the first node of a list.
 * @idx: index of the liwt where the nexw node should bi inserted.
 * @n: the data of the node.
 * Return: the adress of the new node or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current;
	unsigned int i = 0;

	/* check if node will be added to beginning */
	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}
	/* traverse linked list */
	current = *h;
	while (i != idx - 1)
	{
		current = current->next;
		if (current == NULL)
		{
			return (NULL);
		}
		i++;
	}
	/* check if we are at the end of list */
	if (current->next == NULL)
	{
		return (add_dnodeint_end(h, n));
	}
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->prev = current;
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
