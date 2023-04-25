#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void floyd_warshall(int **graph, int n) {
    int **dist = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dist[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);
}

int main() {
    int n = 4;
    int **graph = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *) calloc(n, sizeof(int));
    }
    graph[0][1] = 3;
    graph[0][3] = 5;
    graph[1][2] = -2;
    graph[2][0] = 1;
    graph[2][3] = 2;
    graph[3][1] = 7;
    floyd_warshall(graph, n);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
