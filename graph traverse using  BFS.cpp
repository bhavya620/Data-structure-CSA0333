#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue for BFS
int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Array of adjacency list heads
Node* adjList[MAX];

// Function to create a node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to the adjacency list (undirected)
void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Since undirected, add edge from dest to src too
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Enqueue function
void enqueue(int value) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

// Breadth First Search
void bfs(int startVertex, int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS traversal starting from vertex %d: ", startVertex);
    
    while (front <= rear) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        Node* temp = adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                enqueue(adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Driver code
int main() {
    int vertices, edges, src, dest, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency list
    for (int i = 0; i < vertices; i++)
        adjList[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter %d edges (src dest):\n", edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(startVertex, vertices);

    return 0;
}
