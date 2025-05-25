#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF 99999

int findMinKey(int key[], int mstSet[], int n) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX]; // To store constructed MST
    int key[MAX]; // Key values to pick minimum weight edge
    int mstSet[MAX] = {0}; // Included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0; // Start from first vertex

    for (int count = 0; count < n - 1; count++) {
        int u = findMinKey(key, mstSet, n);
        mstSet[u] = 1;

        // Update key and parent of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    int total = 0;
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", total);
}

int main() {
    int graph[MAX][MAX], n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, n);

    return 0;
}
