#include "graphs.h"

size_t depth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *v, size_t depth));
size_t traversal(vertex_t *vertex, size_t *visited, void (*action)(const vertex_t *v, size_t depth), size_t depth);

size_t traversal(vertex_t *vertex, size_t *visited, void (*action)(const vertex_t *v, size_t depth), size_t depth)
{
    edge_t *e = vertex->edges;
    size_t max_depth = depth;

    // check if the vertex is already visited
    if (visited[vertex->index] == 0)
    {
        visited[vertex->index] = 1;
        action(vertex, depth);
        while (e != NULL)
        {
            size_t new_depth = traversal(e->dest, visited, action, depth + 1);
            if (new_depth > depth)
                max_depth = new_depth;
            e = e->next;
        }
    }
    return max_depth;
}

size_t depth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *v, size_t depth))
{
    size_t *visited = calloc(graph->nb_vertices, sizeof(size_t));
    if (graph == NULL || graph->vertices == NULL)
    {
        return 0;
    }

    size_t max_depth = traversal(graph->vertices, visited, action, 0);
    free(visited);
    return max_depth;
}
