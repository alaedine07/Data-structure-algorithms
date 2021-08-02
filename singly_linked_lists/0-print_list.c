#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
* print_list - print items in a list
* @h: pointer to the Head of the list
* Return: number of elements
*/
size_t print_list(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
			h = h->next;
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
			h = h->next;
		}
		n++;
	}
	return (n);
}
