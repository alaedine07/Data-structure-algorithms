#include "lists.h"
/**
* add_dnodeint_end - function that adds a new node
* at the end of a dlistint_t list.
* @head: pointer to the head node
* @n: new integer node
* Return: pointer to the new element
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *current;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	/* initialize new node */
	new_node->n = n;
	new_node->next = NULL;
	/* first add */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	/* traverse the linked list */
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
	new_node->prev = current;
	return (new_node);
}
