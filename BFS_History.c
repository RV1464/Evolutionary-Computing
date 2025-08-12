#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int deadEnd[MAX];
int vertices;

// BFS with history (avoiding dead ends)
void bfs_with_history(int start, int goal) {
    int queue[MAX], front = 0, rear = 0;
    int parent[MAX];
    for (int i = 0; i < vertices; i++) {
        parent[i] = -1;
        visited[i] = 0;
        deadEnd[i] = 0;
    }

    // enqueue start
    queue[rear++] = start;
    visited[start] = 1;

    int found = 0;
    while (front < rear) {
        int current = queue[front++];

        if (current == goal) {
            found = 1;
            break;
        }

        int hasNeighbor = 0;
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i] && !deadEnd[i]) {
                queue[rear++] = i;
                visited[i] = 1;
                parent[i] = current;
                hasNeighbor = 1;
            }
        }
        if (!hasNeighbor) {
            deadEnd[current] = 1; // mark as dead end
        }
    }

    if (!found) {
        printf("No path found.\n");
    } else {
        // Reconstruct path from goal to start
        int path[MAX], path_len = 0;
        for (int v = goal; v != -1; v = parent[v]) {
            path[path_len++] = v;
        }
        // Print in forward order
        printf("BFS with history path: ");
        for (int i = path_len - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    int start, goal;
    printf("Enter start vertex: ");
    scanf("%d", &start);
    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    bfs_with_history(start, goal);

    return 0;
}
