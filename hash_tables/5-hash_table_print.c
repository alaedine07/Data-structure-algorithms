#include "hash_tables.h"
/**
* hash_table_print - prints a hash table
* @ht: the hash table
* Return: void
*/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;
	int  occ = 0;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current)
		{
			if (occ)
			{
				printf(", ");
			}
			printf("'%s': '%s'", current->key, current->value);
			occ = 1;
			current = current->next;
		}
	}
	printf("}\n");
}
