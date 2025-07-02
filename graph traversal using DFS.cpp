#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph: array of adjacency list heads
Node* adjList[MAX];
int visited[MAX];

// Create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add an edge (undirected)
void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Since undirected graph, add back edge
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Depth-First Search function
void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
            dfs(adjVertex);
        temp = temp->next;
    }
}

// Driver code
int main() {
    int vertices, edges, src, dest, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency list
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter %d edges (src dest):\n", edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfs(startVertex);
    printf("\n");

    return 0;
}
