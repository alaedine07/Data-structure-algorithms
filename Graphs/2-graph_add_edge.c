#include "graphs.h"

int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type);
void insert_bidirectional_edge(vertex_t *source_vertex, vertex_t *destination_vertex);
void insert_unidirectional_edge(vertex_t *source_vertex, vertex_t *destination_vertex);

void insert_bidirectional_edge(vertex_t *source_vertex, vertex_t *destination_vertex)
{
    edge_t *new_edge_src = malloc(sizeof(edge_t));
    edge_t *new_edge_dest = malloc(sizeof(edge_t));
    new_edge_src->dest = destination_vertex;
    new_edge_src->next = NULL;
    if (source_vertex->edges == NULL)
    {
        source_vertex->edges = new_edge_src;
        source_vertex->nb_edges = 1;
    }
    else
    {
        edge_t *current_edge = malloc(sizeof(edge_t));
        current_edge = source_vertex->edges;
        while (current_edge->next != NULL)
            current_edge = current_edge->next;
        current_edge->next = new_edge_src;
        source_vertex->nb_edges = source_vertex->nb_edges + 1;
    }
    new_edge_dest->dest = source_vertex;
    new_edge_dest->next = NULL;
    if (destination_vertex->edges == NULL)
    {
        destination_vertex->edges = new_edge_dest;
        destination_vertex->nb_edges = 1;
    }
    else
    {
        edge_t *current_edge = malloc(sizeof(edge_t));
        current_edge = destination_vertex->edges;
        while (current_edge->next != NULL)
            current_edge = current_edge->next;
        current_edge->next = new_edge_dest;
        destination_vertex->nb_edges = destination_vertex->nb_edges + 1;
    }
}

void insert_unidirectional_edge(vertex_t *source_vertex, vertex_t *destination_vertex)
{
    edge_t *new_edge = malloc(sizeof(edge_t));
    new_edge->dest = destination_vertex;
    new_edge->next = NULL;
    if (source_vertex->edges == NULL)
    {
        source_vertex->edges = new_edge;
        source_vertex->nb_edges = 1;
        return;
    }
    edge_t *current_edge = malloc(sizeof(edge_t));
    current_edge = source_vertex->edges;
    while (current_edge->next != NULL)
        current_edge = current_edge->next;
    current_edge->next = new_edge;
    source_vertex->nb_edges = source_vertex->nb_edges + 1;
}

int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
    vertex_t *current = malloc(sizeof(vertex_t));
    vertex_t *src_or_dest = malloc(sizeof(vertex_t));
    current = graph->vertices;
    while (current->next != NULL)
    {
        // in case we found the source first
        if (strcmp(current->content, src) == 0)
        {
            src_or_dest = current;
            while (current)
            {
                if (strcmp(current->content, dest) == 0)
                {
                    if (type == UNIDIRECTIONAL)
                    {
                        insert_unidirectional_edge(src_or_dest, current);
                        return (1);
                    }
                    insert_bidirectional_edge(src_or_dest, current);
                    return (1);
                }
                current = current->next;
            }
            // source found but destination not found
            return (1);
        }
        // in case we found the destination first
        if (strcmp(current->content, dest) == 0)
        {
            src_or_dest = current;
            while (current)
            {
                if (strcmp(current->content, src) == 0)
                {
                    if (type == UNIDIRECTIONAL)
                    {
                        insert_unidirectional_edge(current, src_or_dest);
                        return (1);
                    }
                    insert_bidirectional_edge(current, src_or_dest);
                    return (1);
                }
                current = current->next;
            }
            // destination found but source not found
            return (1);
        }
        current = current->next;
    }
    return (0);
}
