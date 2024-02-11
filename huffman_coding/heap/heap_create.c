#include "heap.h"
#include <stdlib.h>

/**
 * heap_create - create a heap data structure
 *
 * @data_cmp: pointer to a comparison function
 * Return: pointer to the created heap or null if it fails.
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
    heap_t *heap;
    heap = malloc(sizeof(heap_t));
    if (heap == NULL)
    {
        return (NULL);
    }
    heap->size = 0;
    heap->root = NULL;
    heap->data_cmp = data_cmp;
    return heap;
}
