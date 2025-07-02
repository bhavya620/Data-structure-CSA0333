#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices in graph

// Find vertex with minimum distance value from the set of vertices not yet processed
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Print the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Dijkstra’s algorithm function
void dijkstra(int graph[V][V], int src) {
    int dist[V];    // Output array. dist[i] will hold shortest distance from src to i
    int sptSet[V];  // sptSet[i] will be 1 if vertex i is included in shortest path tree

    // Initialize all distances as infinite and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;  // Distance from source to itself is 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Pick vertex with minimum distance
        sptSet[u] = 1;                     // Mark picked vertex as processed

        // Update dist value of adjacent vertices of picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    // Example graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0},
    };

    int source = 0;
    printf("Dijkstra's shortest paths from vertex %d:\n", source);
    dijkstra(graph, source);

    return 0;
}
