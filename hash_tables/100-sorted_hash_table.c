#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t sh_table;
    unsigned long int i;
    if (size == 0)
    {
        return (NULL);
    }
    sh_table = malloc(sizeof(shash_table_t));
    if (sh_table == NULL)
    {
        return (NULL);
    }
    sh_table->size = size;
    sh_table->array = malloc(sizeof(shash_node_t *) * size);
    if (sh_table == NULL)
    {
        free(sh_table);
        return (NULL);
    }
    for (i = 0; i < size; i++)
    {
        sh_table->array[i] = NULL;
    }
    sh_table->shead = NULL;
    sh_table->stail = NULL;
    return (sh_table);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *curr;
    shash_node_t *new_node;

    if (key == NULL || value == NULL || ht == NULL)
    {
        return (0);
    }
    slot = key_index((const unsigned char *)key, ht->size);
    /*curr = ht->array[slot];*/
    curr = ht->shead;
    while (curr)
    {
        /* update value of key */
        if (strcmp(key, curr->key) == 0)
        {
            free(curr->value);
            curr->value = strdup(value);
            return (1);
        }
        curr = curr->next;
    }
    /* create a new node */
    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
    {
        return (0);
    }
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    ht->array[slot] = new_node;
    /* the first insert */
    if (ht->head == NULL)
    {
        new_node->sprev = NULL;
        new_node->snext = NULL;
        new_node->next = NULL;
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else
    {
        
    }
}
