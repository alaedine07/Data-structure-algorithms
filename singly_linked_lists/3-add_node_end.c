#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * _strlen - get the string length
 * @str: string
 * Return: length
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
/**
 * add_node_end - add a node at the end of list
 * @head: the head of the first list
 * @str: string to copy
 * Return: a pointer to the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode = malloc(sizeof(list_t));
	list_t *current_node = *head;

	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->str = strdup(str);
	newnode->len = _strlen(str);
	newnode->next = NULL;
	/* head is the last node */
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (current_node->next != NULL)
		{
			current_node = current_node->next;
		}
		current_node->next = newnode;
	}
	return (newnode);
}
