#include <stdio.h>

#define MAX 10

int visited[MAX];
int graph[MAX][MAX];
int n;
int goal;
int found = 0;
int path[MAX], pathIndex = 0;

void DFS_Path(int vertex) {
    visited[vertex] = 1;
    path[pathIndex++] = vertex;  

    if (vertex == goal) {
        printf("Path from start to goal: ");
        for (int i = 0; i < pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        found = 1;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i] && !found) {
            DFS_Path(i);
        }
    }

    pathIndex--; 
}

int main() {
    int edges, v1, v2;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    DFS_Path(start);

    if (!found) {
        printf("No path found from %d to %d.\n", start, goal);
    }

    return 0;
}
