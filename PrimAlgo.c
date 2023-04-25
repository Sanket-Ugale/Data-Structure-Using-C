#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minKey(int *key, int *mstSet, int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void prim(int **graph, int n) {
    int *parent = (int *) malloc(n * sizeof(int));
    int *key = (int *) malloc(n * sizeof(int));
    int *mstSet = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int mst_weight = 0;
    for (int i = 1; i < n; i++) {
        mst_weight += graph[i][parent[i]];
    }
    printf("Minimum cost spanning tree weight = %d\n", mst_weight);
    free(parent);
    free(key);
    free(mstSet);
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
    prim(graph, n);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
