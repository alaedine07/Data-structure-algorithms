#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
* list_len - count len of items in a list
* @h: pointer to the Head of the list
* Return: number of elements
*/
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			h = h->next;
		}
		else
		{
			h = h->next;
			n++;
		}
	}
	return (n);
}
