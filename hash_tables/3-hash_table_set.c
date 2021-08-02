#include "hash_tables.h"

/**
 * hash_table_set - add elements to hash table
 * @ht: hash table
 * @key: key
 * @value: value associeted to the key to add
 * Return: 0(Fails) 1(Succes)
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int slot, size;
	hash_node_t *node; 
	hash_node_t *curr;

	if (!key || !value || !ht)
		return (0);
	size = ht->size;
	slot = key_index((const unsigned char *)key, size);
	curr = ht->array[slot];
	/* navigate linked list */
	while (curr)
	{
		/* update value of a key */
		if (strcmp(key, curr->key) == 0)
		{
			free(curr->value);
			curr->value = strdup(value);
			return (1);
		}
		curr = curr->next;
	}
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		return (0);
	}
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = ht->array[slot];
	ht->array[slot] = node;
	return (1);
}