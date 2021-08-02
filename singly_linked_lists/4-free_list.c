#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * free_list - frees a list
 * @head: the head of the given list
 * Return: void
 */
void free_list(list_t *head)
{
	while (head)
	{
		list_t *aux = head;

		head = head->next;
		free(aux->str);
		free(aux);
	}
}
