#include "hash_tables.h"
/**
 * hash_table_get - retrieve a value and key from hash table
 * @ht: The hash table you want to add or update the key/value to.
 * @key: The key
 * Return: value if found or NULL
**/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int slot;
	hash_node_t *curr;

	if (ht == NULL || key == NULL)
	{
		return (NULL);
	}
	slot = key_index((const unsigned char *)key, ht->size);
	/* navigate linked list */
	curr = ht->array[slot];
	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
		{
			return (curr->value);
		}
		curr = curr->next;
	}
	/* didn't find any match */
	return (NULL);
}
