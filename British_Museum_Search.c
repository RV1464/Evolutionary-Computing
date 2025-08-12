#include <stdio.h>

#define MAX 10

int found = 0;

void britishMuseumSearch(int graph[MAX][MAX], int n, int current, int goal, int path[], int pathLen) {
    path[pathLen] = current;
    pathLen++;

    // If goal found, print and stop
    if (current == goal) {
        printf("Solution Path Found: ");
        for (int i = 0; i < pathLen; i++) {
            printf("%d", path[i]);
            if (i < pathLen - 1) printf(" -> ");
        }
        printf("\n");
        found = 1;
        return;
    }

    // Explore all neighbors
    for (int i = 0; i < n; i++) {
        if (graph[current][i] != 0) {
            // Check if already in path (to prevent infinite loops)
            int alreadyInPath = 0;
            for (int k = 0; k < pathLen; k++) {
                if (path[k] == i) {
                    alreadyInPath = 1;
                    break;
                }
            }
            if (!alreadyInPath) {
                britishMuseumSearch(graph, n, i, goal, path, pathLen);
                if (found) return; // stop after first solution
            }
        }
    }
}

int main() {
    int n, edges;
    int graph[MAX][MAX] = {0};
    int start, goal;
    int path[MAX];

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

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    britishMuseumSearch(graph, n, start, goal, path, 0);

    if (!found) {
        printf("No path found.\n");
    }

    return 0;
}
