#include <stdio.h>

#define MAX 10

void hillClimb(int graph[MAX][MAX], int h[], int n, int start, int goal) {
    int visited[MAX] = {0};
    int current = start;

    printf("Path: %d", current);
    visited[current] = 1;

    while (current != goal) {
        int bestNeighbor = -1;
        int bestH = 9999;

        // Find the neighbor with the best heuristic (lowest value)
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                if (h[i] < bestH) {
                    bestH = h[i];
                    bestNeighbor = i;
                }
            }
        }

        // Stop if no better neighbor or plateau
        if (bestNeighbor == -1 || h[bestNeighbor] >= h[current]) {
            printf("\nNo better neighbor found. Stopping.\n");
            return;
        }

        current = bestNeighbor;
        visited[current] = 1;
        printf(" -> %d", current);
    }

    printf("\nGoal reached!\n");
}

int main() {
    int n, edges;
    int graph[MAX][MAX] = {0};
    int h[MAX];
    int start, goal;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    printf("Enter heuristic values for each vertex:\n");
    for (int i = 0; i < n; i++) {
        printf("h(%d): ", i);
        scanf("%d", &h[i]);
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    hillClimb(graph, h, n, start, goal);

    return 0;
}

