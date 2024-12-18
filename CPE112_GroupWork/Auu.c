//66070501038 Phanthach Jiamjaruschot
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent an edge in the graph
struct Edge {
  int v; // Destination vertex
  int weight; // Weight of the edge
  struct Edge* next;
};

// Structure to represent a graph
struct Graph {
  int V; // Number of vertices
  struct Edge* adj[MAX_VERTICES]; // Adjacency list
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;

  // Create adjacency list for all vertices
  for (int i = 0; i < V; ++i) {
    graph->adj[i] = NULL;
  }

  return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v, int weight) {
  // Create a new edge node
  struct Edge* new_edge = (struct Edge*)malloc(sizeof(struct Edge));
  new_edge->v = v;
  new_edge->weight = weight;

  // Add the edge to the adjacency list of u
  new_edge->next = graph->adj[u];
  graph->adj[u] = new_edge;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (int u = 0; u < graph->V; ++u) {
    printf("\n%d ", u);
    struct Edge* temp = graph->adj[u];
    while (temp) {
      printf("-> %d (%d)", temp->v, temp->weight);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int Edgenum,source, destination, weight;

  scanf("%d", &Edgenum);

  // Create a graph
  for (int i = 0; i < Edgenum; i++) {
    struct Graph* graph = createGraph(Edgenum);
    scanf("%d %d %d", &source, &destination, &weight);
    addEdge(graph, source, destination, weight);
  }
  
  printGraph(graph);

  return 0;
}
