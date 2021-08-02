#include "lists.h"
/**
* add_dnodeint - function that adds a new node at the beginning
* @head: pointer to the head node
* @n: new integer node
* Return: pointer to the new element
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	/* if allocation fail */
	if (new_node == NULL)
	{
		return (NULL);
	}
	/* initialise the new node */
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	/* change the head to the new node */
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}
