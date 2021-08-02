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
 * add_node - add a node at the beginning of list
 * @head: the head of the first list
 * @str: string to copy
 * Return: a pointer to the new node
 */
list_t *add_node(list_t **head, const char *str)
{
	/* create new node */
	list_t *new_node;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->str = strdup(str);
	new_node->len = _strlen(str);
	new_node->next = *head;

	*head = new_node;
	return (new_node);
}
