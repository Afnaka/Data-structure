#include <stdio.h>
 #include <stdlib.h>

 #define MAX_VERTICES 100

 // Structure for representing a graph
 typedef struct {
     int adj[MAX_VERTICES][MAX_VERTICES];
     int visited[MAX_VERTICES];
     int n; // Number of vertices
 } Graph;

 // Function to initialize the graph
 void initializeGraph(Graph* g, int n) {
     g->n = n;
     for (int i = 0; i < n; i++) {
         g->visited[i] = 0;
         for (int j = 0; j < n; j++) {
             g->adj[i][j] = 0;
         }
     }
 }

 // Function to add a directed edge to the graph
 void addEdge(Graph* g, int u, int v) {
     g->adj[u][v] = 1; // Only set edge from u to v
 }

 // Function to print the adjacency matrix
 void printGraph(Graph* g) {
     printf("Graph (Adjacency Matrix):\n");
     for (int i = 0; i < g->n; i++) {
         for (int j = 0; j < g->n; j++) {
             printf("%d ", g->adj[i][j]);
         }
         printf("\n");
     }
 }

 // DFS visit function
 void DFS_Visit(Graph* g, int vertex) {
     g->visited[vertex] = 1;
     printf("%d ", vertex);

     // Recur for all unvisited neighbors
     for (int i = 0; i < g->n; i++) {
         if (g->adj[vertex][i] == 1 && !g->visited[i]) {
             DFS_Visit(g, i);
         }
     }
 }

 // Function for DFS traversal
 void DFS(Graph* g) {
     // Reset visited array before starting DFS
     for (int i = 0; i < g->n; i++) {
         g->visited[i] = 0;
     }

     printf("Depth-First Search Traversal:\n");
     for (int i = 0; i < g->n; i++) {
         if (!g->visited[i]) {
             DFS_Visit(g, i);
         }
     }
     printf("\n");
 }

// // BFS function
 void BFS(Graph* g, int start) {
     int queue[MAX_VERTICES];
     for (int i = 0; i < g->n; i++) {
         g->visited[i] = 0; // Reset visited array
     }

     int front = 0, rear = 0;
     queue[rear++] = start; // Enqueue the starting vertex
     g->visited[start] = 1; // Mark it as visited

     printf("Breadth-First Search Traversal from vertex %d:\n", start);

     while (front < rear) {
         int vertex = queue[front++]; // Dequeue the front vertex
         printf("%d ", vertex);

         // Add all unvisited neighbors to the queue
         for (int i = 0; i < g->n; i++) {
             if (g->adj[vertex][i] == 1 && !g->visited[i]) {
                 queue[rear++] = i; // Enqueue the neighbor
                 g->visited[i] = 1; // Mark as visited
             }
         }
     }
     printf("\n");
 }

 // Topological Sort using DFS
 void topologicalSort(Graph* g) {
     int stack[MAX_VERTICES], top = -1;

     // Reset visited array before starting Topological Sort
     for (int i = 0; i < g->n; i++) {
         g->visited[i] = 0;
     }

     // DFS visit function for Topological Sort
     void topoDFS(Graph* g, int vertex) {
         g->visited[vertex] = 1;

         for (int i = 0; i < g->n; i++) {
             if (g->adj[vertex][i] == 1 && !g->visited[i]) {
                 topoDFS(g, i);
             }
         }
         stack[++top] = vertex; // Push the vertex onto the stack
     }

     // Perform DFS for all unvisited nodes
     for (int i = 0; i < g->n; i++) {
         if (!g->visited[i]) {
             topoDFS(g, i);
         }
     }

     // Print the sorted order
     printf("Topological Sort:\n");
     while (top >= 0) {
         printf("%d ", stack[top--]);
     }
     printf("\n");
 }

 // Main function to drive the program
 int main() {
     Graph g;
     int n, e, u, v, choice, start;

     // Step 1: Get the number of vertices and edges
     printf("Enter the number of vertices: ");
     scanf("%d", &n);
     initializeGraph(&g, n);

     printf("Enter the number of edges: ");
     scanf("%d", &e);

     // Step 2: Get the edges
     printf("Enter the edges (u -> v):\n");
     for (int i = 0; i < e; i++) {
         scanf("%d %d", &u, &v);
         addEdge(&g, u, v);
     }

     // Step 3: Ask the user which operation to perform
     while (1) {
         printf("\nChoose an operation:\n");
         printf("1. Perform DFS traversal\n");
         printf("2. Perform BFS traversal\n");
         printf("3. Perform Topological Sort\n");
         printf("4. Print Graph (Adjacency Matrix)\n");
         printf("5. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);

         switch (choice) {
             case 1:
                 DFS(&g);
                 break;
             case 2:
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &start);
                 BFS(&g, start);
                 break;
             case 3:
                 topologicalSort(&g);
                 break;
             case 4:
                 printGraph(&g);
                 break;
             case 5:
                 printf("Exiting...\n");
                 return 0;
             default:
                 printf("Invalid choice! Please try again.\n");
         }
     }

     return 0;
}
