#include <stdio.h>

#define MAX 10
#define INF 9999

typedef struct {
    int path[MAX];
    int length;
    int cost;
} Node;

// Function to copy a path
void copyPath(int dest[], int src[], int len) {
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
}

void branchAndBound(int graph[MAX][MAX], int n, int start, int goal) {
    Node pq[MAX * MAX]; // simple priority queue
    int pqSize = 0;

    // Initialize with start node
    pq[0].path[0] = start;
    pq[0].length = 1;
    pq[0].cost = 0;
    pqSize = 1;

    while (pqSize > 0) {
        // Find the node with the least cost
        int bestIndex = 0;
        for (int i = 1; i < pqSize; i++) {
            if (pq[i].cost < pq[bestIndex].cost) {
                bestIndex = i;
            }
        }

        Node current = pq[bestIndex];
        // Remove it from queue
        pqSize--;
        for (int i = bestIndex; i < pqSize; i++) {
            pq[i] = pq[i + 1];
        }

        int lastNode = current.path[current.length - 1];

        // If goal reached, print path
        if (lastNode == goal) {
            printf("Optimal Path: ");
            for (int i = 0; i < current.length; i++) {
                printf("%d", current.path[i]);
                if (i < current.length - 1) printf(" -> ");
            }
            printf("\nTotal Cost: %d\n", current.cost);
            return;
        }

        // Expand neighbors
        for (int v = 0; v < n; v++) {
            if (graph[lastNode][v] != 0) { // edge exists
                // Check if v already in path (avoid cycles)
                int inPath = 0;
                for (int k = 0; k < current.length; k++) {
                    if (current.path[k] == v) {
                        inPath = 1;
                        break;
                    }
                }
                if (!inPath) {
                    Node child;
                    copyPath(child.path, current.path, current.length);
                    child.path[current.length] = v;
                    child.length = current.length + 1;
                    child.cost = current.cost + graph[lastNode][v];
                    pq[pqSize++] = child;
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    int n, edges;
    int graph[MAX][MAX] = {0};
    int start, goal;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges with weights (u v w):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    branchAndBound(graph, n, start, goal);

    return 0;
}
