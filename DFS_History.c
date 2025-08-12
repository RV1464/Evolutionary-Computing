#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; 
int visited[MAX];    
int deadEnd[MAX];   
int vertices;

int dfs_with_history(int current, int goal) {
    if (current == goal) {
        printf("%d ", current);
        return 1;
    }

    visited[current] = 1; 

    for (int i = 0; i < vertices; i++) {
        if (graph[current][i] == 1 && !visited[i] && !deadEnd[i]) {
            if (dfs_with_history(i, goal)) {
                printf("%d ", current); 
                return 1;
            }
        }
    }

    deadEnd[current] = 1;
    visited[current] = 0; 
    return 0;
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }

    int start, goal;
    printf("Enter start vertex: ");
    scanf("%d", &start);
    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    printf("DFS with history (avoiding dead-ends):\n");
    if (!dfs_with_history(start, goal)) {
        printf("No path found.\n");
    } else {
        printf("\n");
    }

    return 0;
}
