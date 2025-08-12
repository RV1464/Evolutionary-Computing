#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int parent[MAX];
int n;

void BFS_Path(int start, int goal) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];

        if (current == goal) {
            int path[MAX], pathLen = 0;
            for (int v = goal; v != -1; v = parent[v]) {
                path[pathLen++] = v;
            }

            printf("Shortest path from %d to %d: ", start, goal);
            for (int i = pathLen - 1; i >= 0; i--) {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        }

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
                parent[i] = current; 
            }
        }
    }

    printf("No path found from %d to %d.\n", start, goal);
}

int main() {
    int edges, v1, v2, start, goal;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

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

    BFS_Path(start, goal);

    return 0;
}
