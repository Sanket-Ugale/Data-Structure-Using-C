#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

struct Edge {
    int source;
    int destination;
    int weight;
};

struct Graph {
    int num_nodes;
    int num_edges;
    struct Edge edges[MAX_EDGES];
};

void bellman_ford(struct Graph *graph, int source) {
    int distances[MAX_NODES];
    int predecessors[MAX_NODES];

    // Initialize distances and predecessors
    for (int i = 0; i < graph->num_nodes; i++) {
        distances[i] = INT_MAX;
        predecessors[i] = -1;
    }
    distances[source] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < graph->num_nodes - 1; i++) {
        for (int j = 0; j < graph->num_edges; j++) {
            int u = graph->edges[j].source;
            int v = graph->edges[j].destination;
            int w = graph->edges[j].weight;
            if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                predecessors[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < graph->num_edges; i++) {
        int u = graph->edges[i].source;
        int v = graph->edges[i].destination;
        int w = graph->edges[i].weight;
        if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Print shortest paths and predecessors
    printf("Shortest paths from source %d:\n", source);
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: distance %d, predecessor %d\n", i, distances[i], predecessors[i]);
    }
}

int main() {
    struct Graph graph;
    int source;

    // Read input
    printf("Enter number of nodes: ");
    scanf("%d", &graph.num_nodes);
    printf("Enter number of edges: ");
    scanf("%d", &graph.num_edges);
    printf("Enter edges as source destination weight:\n");
    for (int i = 0; i < graph.num_edges; i++) {
        scanf("%d %d %d", &graph.edges[i].source, &graph.edges[i].destination, &graph.edges[i].weight);
    }
    printf("Enter source node: ");
    scanf("%d", &source);

    // Run Bellman-Ford algorithm
    bellman_ford(&graph, source);

    return 0;
}