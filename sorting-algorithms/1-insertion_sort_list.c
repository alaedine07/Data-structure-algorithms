#include "sort.h"
/**
* swap_nodes - swap nodes in diffirent conditions
* @list : dobly linked list
* @head: head of doubly linked list
* @curr: current node in linked list
*/
void swap_nodes(listint_t *curr, listint_t **list, listint_t *head)
{
    listint_t *tmp = NULL;

    if (curr->prev->prev == NULL)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev->prev = curr;
        curr->next = curr->prev;
        curr->prev = NULL;
        *list = head;
        print_list(*list);

    }
    else if (curr->next == NULL)
    {
        /* swap at end of linked list */
        tmp = curr;
        curr->prev->prev->next = curr;
        curr->prev->next = NULL;
        curr->next = curr->prev;
        curr->prev = curr->prev->prev;
        curr->next->prev = curr;
        print_list(*list);

    }
    else
    {
        /* permute the 2 nodes */
        tmp = curr->prev;
        curr->next->prev = curr->prev;
        tmp = curr->next;
        curr->prev->prev->next = curr;
        curr->next = curr->prev;
        curr->prev = curr->prev->prev;
        curr->next->next = tmp;
        curr->next->prev = curr;
        print_list(*list);
    }
}
/**
* insertion_sort_list - sorting in an ascending manner
* @list : doubly linked list
*/
void insertion_sort_list(listint_t **list)
{

    listint_t *curr = NULL;
    listint_t *next_node = NULL;

    listint_t *head = *list;

    if (list == NULL || *list == NULL || head->next == NULL)
        return;
    /* traverse the linked list */
    while (head)
    {
        curr = head;
        if (curr->prev && (curr->prev->n > curr->n))
        {
            next_node = curr;
            /* find where to insert the node in the previous nodes */
            while (next_node->prev && (next_node->prev->n > next_node->n))
            {
                /* if prev node is the head */
                swap_nodes(curr, list, head);
            }
        }
        head = head->next;
    }
}