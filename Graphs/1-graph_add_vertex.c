#include "graphs.h"

vertex_t *graph_add_vertex(graph_t *graph, const char *str);

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
    /* if graph has no vertex then create adjacency linked list */
    char *new_string = malloc(sizeof(strlen(str)));
    if (graph->nb_vertices == 0)
    {
        /* create node which will be the head of linked list */
        vertex_t *node = malloc(sizeof(vertex_t));
        node->index = 0;
        node->content = strcpy(new_string, str);
        node->nb_edges = 0;
        node->edges = NULL;
        node->next = NULL;
        graph->vertices = node;
        graph->nb_vertices = 1;
        return node;
    }
    /* traverse the adjacency linked list and insert another vertex that holds the str */
    else
    {
        vertex_t *current = malloc(sizeof(vertex_t));
        current = graph->vertices;
        while (current->next != NULL)
        {
            current = current->next;
        }
        vertex_t *node = malloc(sizeof(vertex_t));
        node->index = current->index + 1;
        node->content = strcpy(new_string, str);
        node->nb_edges = 0;
        node->edges = NULL;
        node->next = NULL;
        current->next = node;
        graph->nb_vertices = node->index + 1;
        return node;
    }
}
