#include <stdio.h>

#define MAX 10
#define BEAM_WIDTH 2

typedef struct {
    int node;
    int heuristic;
} Node;

void beamSearchHistory(int graph[MAX][MAX], int h[], int start, int goal, int n) {
    Node beam[BEAM_WIDTH];
    int parent[MAX];
    int visited[MAX] = {0};
    int history[MAX], historyLen = 0;

    // Initialize
    for (int i = 0; i < n; i++) parent[i] = -1;

    beam[0].node = start;
    beam[0].heuristic = h[start];
    int beamSize = 1;
    visited[start] = 1;
    history[historyLen++] = start;

    while (beamSize > 0) {
        Node nextBeam[BEAM_WIDTH * MAX];
        int nextSize = 0;

        // Expand all nodes in current beam
        for (int i = 0; i < beamSize; i++) {
            int u = beam[i].node;
            if (u == goal) {
                // Print history
                printf("Visited Order (History): ");
                for (int k = 0; k < historyLen; k++) {
                    printf("%d ", history[k]);
                }
                printf("\n");

                // Reconstruct path
                int path[MAX], pathLen = 0;
                for (int v = goal; v != -1; v = parent[v]) {
                    path[pathLen++] = v;
                }
                printf("Final Path: ");
                for (int j = pathLen - 1; j >= 0; j--) {
                    printf("%d", path[j]);
                    if (j > 0) printf(" -> ");
                }
                printf("\nGoal reached!\n");
                return;
            }

            for (int v = 0; v < n; v++) {
                if (graph[u][v] && !visited[v]) {
                    nextBeam[nextSize].node = v;
                    nextBeam[nextSize].heuristic = h[v];
                    parent[v] = u;
                    visited[v] = 1;
                    history[historyLen++] = v; // log visit
                    nextSize++;
                }
            }
        }

        // Sort nextBeam by heuristic (best first)
        for (int i = 0; i < nextSize - 1; i++) {
            for (int j = i + 1; j < nextSize; j++) {
                if (nextBeam[j].heuristic < nextBeam[i].heuristic) {
                    Node temp = nextBeam[i];
                    nextBeam[i] = nextBeam[j];
                    nextBeam[j] = temp;
                }
            }
        }

        // Keep only BEAM_WIDTH best nodes
        beamSize = (nextSize < BEAM_WIDTH) ? nextSize : BEAM_WIDTH;
        for (int i = 0; i < beamSize; i++) {
            beam[i] = nextBeam[i];
        }
    }

    // If search ends without finding goal
    printf("Visited Order (History): ");
    for (int k = 0; k < historyLen; k++) {
        printf("%d ", history[k]);
    }
    printf("\nGoal not found.\n");
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

    beamSearchHistory(graph, h, start, goal, n);

    return 0;
}
