#include "graphs.h"

int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type);
vertex_t *find_vertex(graph_t *graph, const char *content);
edge_t *create_edge(vertex_t *destination_vertex);
void insert_edge(vertex_t *source_vertex, vertex_t *destination_vertex, edge_type_t type);

vertex_t *find_vertex(graph_t *graph, const char *content)
{
    vertex_t *current = graph->vertices;
    while (current)
    {
        if (strcmp(current->content, content) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

edge_t *create_edge(vertex_t *destination_vertex)
{
    edge_t *new_edge = malloc(sizeof(edge_t));
    if (new_edge)
    {
        new_edge->dest = destination_vertex;
        new_edge->next = NULL;
    }
    return new_edge;
}

void insert_edge(vertex_t *source_vertex, vertex_t *destination_vertex, edge_type_t type)
{
    edge_t *new_edge = create_edge(destination_vertex);

    if (!new_edge)
    {
        return; // Allocation failed
    }

    if (source_vertex->edges == NULL)
    {
        source_vertex->edges = new_edge;
        source_vertex->nb_edges = 1;
    }
    else
    {
        edge_t *current_edge = source_vertex->edges;
        while (current_edge->next != NULL)
        {
            current_edge = current_edge->next;
        }
        current_edge->next = new_edge;
        source_vertex->nb_edges++;
    }

    if (type == BIDIRECTIONAL)
    {
        insert_edge(destination_vertex, source_vertex, UNIDIRECTIONAL);
    }
}

int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
    vertex_t *src_vertex = find_vertex(graph, src);
    vertex_t *dest_vertex = find_vertex(graph, dest);

    if (!src_vertex || !dest_vertex)
    {
        return 0; // Either source or destination vertex not found
    }

    if (type == UNIDIRECTIONAL)
    {
        insert_edge(src_vertex, dest_vertex, UNIDIRECTIONAL);
    }
    else
    {
        insert_edge(src_vertex, dest_vertex, BIDIRECTIONAL);
    }

    return 1; // Edge added successfully
}
