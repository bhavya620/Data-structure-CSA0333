#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct {
    int V, E;
    Edge edges[MAX];
} Graph;

// Disjoint set (Union-Find) structure
int parent[MAX];

// Find set of an element i (uses path compression)
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

// Union of two sets x and y
void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    parent[xroot] = yroot;
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

// Kruskal's algorithm to find MST
void kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[MAX]; // Store the MST
    int e = 0;         // Index for result[]
    int i = 0;         // Index for sorted edges

    // Step 1: Sort all edges in increasing order
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Step 2: Create disjoint sets for each vertex
    for (int v = 0; v < V; ++v)
        parent[v] = v;

    // Step 3: Pick the smallest edge and check if it forms a cycle
    while (e < V - 1 && i < graph->E) {
        Edge nextEdge = graph->edges[i++];

        int x = find(nextEdge.src);
        int y = find(nextEdge.dest);

        // If including this edge doesn't form a cycle, include it
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(x, y);
        }
    }

    // Print the resulting MST
    printf("Edges in the Minimum Spanning Tree:\n");
    int totalWeight = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

// Driver code
int main() {
    Graph graph;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &graph.V, &graph.E);

    for (int i = 0; i < graph.E; ++i) {
        printf("Enter edge %d (src dest weight): ", i + 1);
        scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }

    kruskalMST(&graph);

    return 0;
}
