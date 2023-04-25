#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src;
    int dest;
    int weight;
} edge;

int cmp(const void *a, const void *b) {
    edge *ia = (edge *) a;
    edge *ib = (edge *) b;
    return ia->weight - ib->weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskal(int **graph, int n) {
    int *parent = (int *) malloc(n * sizeof(int));
    int *rank = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int num_edges = n * (n - 1) / 2;
    edge *edges = (edge *) malloc(num_edges * sizeof(edge));
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j]) {
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }
    qsort(edges, k, sizeof(edge), cmp);
    int mst_weight = 0;
    for (int i = 0; i < k; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int src_root = find(parent, src);
        int dest_root = find(parent, dest);
        if (src_root != dest_root) {
            mst_weight += edges[i].weight;
            unionSet(parent, rank, src_root, dest_root);
        }
    }
    printf("Minimum cost spanning tree weight = %d\n", mst_weight);
    free(parent);
    free(rank);
    free(edges);
}

int main() {
    int n = 5;
    int **graph = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *) calloc(n, sizeof(int));
    }
    graph[0][1] = 2;
    graph[0][3] = 6;
    graph[1][2] = 3;
    graph[1][3] = 8;
    graph[1][4] = 5;
    graph[2][4] = 7;
    graph[3][4] = 9;
    kruskal(graph, n);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
