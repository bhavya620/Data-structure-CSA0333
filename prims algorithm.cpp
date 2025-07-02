#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int minKey(int key[], int mstSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V) {
    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX]; // Stores MST
    int key[MAX];    // Used to pick minimum weight edge
    int mstSet[MAX]; // To track vertices in MST

    // Initialize all keys to INF
    for (int i = 0; i < V; i++)
        key[i] = INF, mstSet[i] = 0;

    key[0] = 0;       // Start from vertex 0
    parent[0] = -1;   // First node is root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V); // Pick minimum key vertex
        mstSet[u] = 1;                  // Include in MST

        for (int v = 0; v < V; v++) {
            // Update key only if graph[u][v] is smaller and v is not in MST
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

// Driver code
int main() {
    int V;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (use 0 if no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, V);

    return 0;
}
