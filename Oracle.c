#include <stdio.h>

#define MAX 10

void oracleSearch(int graph[MAX][MAX], int oracleDist[], int n, int start, int goal) {
    int visited[MAX] = {0};
    int current = start;

    printf("Path: %d", current);
    visited[current] = 1;

    while (current != goal) {
        int nextNode = -1;
        int bestDist = oracleDist[current];

        // Pick neighbor that reduces oracle distance
        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                if (oracleDist[i] < bestDist) {
                    bestDist = oracleDist[i];
                    nextNode = i;
                }
            }
        }

        if (nextNode == -1) {
            printf("\nNo step reduces distance. Stopping.\n");
            return;
        }

        current = nextNode;
        visited[current] = 1;
        printf(" -> %d", current);
    }

    printf("\nGoal reached optimally!\n");
}

int main() {
    int n, edges;
    int graph[MAX][MAX] = {0};
    int oracleDist[MAX];
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

    printf("Enter oracle distances for each vertex (distance to goal):\n");
    for (int i = 0; i < n; i++) {
        printf("oracleDist(%d): ", i);
        scanf("%d", &oracleDist[i]);
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    oracleSearch(graph, oracleDist, n, start, goal);

    return 0;
}
