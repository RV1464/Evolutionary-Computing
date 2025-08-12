#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int n, goal;
int found = 0;

void DFS_Limited(int node, int depth, int limit, int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    if (node == goal) {
        found = 1;
        return;
    }

    if (depth >= limit) return;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS_Limited(i, depth + 1, limit, visited);
            if (found) return;
        }
    }
}

void IterativeDeepeningDFS(int start) {
    for (int limit = 0; limit < n; limit++) {
        int visited[MAX] = {0};
        printf("\nDepth Limit %d: ", limit);
        DFS_Limited(start, 0, limit, visited);
        if (found) {
            printf("\nGoal %d found at depth %d!\n", goal, limit);
            return;
        }
    }
    printf("\nGoal not found.\n");
}

int main() {
    int edges, v1, v2, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1; // Undirected
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    IterativeDeepeningDFS(start);

    return 0;
}
