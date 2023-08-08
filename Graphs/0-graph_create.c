#include "graphs.h"

graph_t *graph_create(void);


graph_t *graph_create(void)
{
    graph_t *graph = malloc(sizeof(graph_t));
    if (graph == NULL)
    {
        exit(EXIT_FAILURE);
    }
    /* init graph */
    graph->nb_vertices = 0;
    graph->vertices = NULL;
    return graph;
}
