#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // maximum number of vertices in the graph

int visited[MAX_VERTICES]; // visited array
int push_order[MAX_VERTICES]; // push order of vertices
int pop_order[MAX_VERTICES]; // pop order of vertices
int push_index = 0; // index of the next element to be pushed
int pop_index = 0; // index of the next element to be popped

struct Graph {
    int V; // number of vertices
    int E; // number of edges
    int **adj; // adjacency matrix
};

struct Graph* createGraph(int V) {
    struct Graph* G = (struct Graph*) malloc(sizeof(struct Graph));
    G->V = V;
    G->E = 0;
    G->adj = (int**) calloc(V, sizeof(int*));
    int i;
    for (i = 0; i < V; i++)
        G->adj[i] = (int*) calloc(V, sizeof(int));
    return G;
}

void addEdge(struct Graph* G, int u, int v) {
    G->adj[u][v] = 1;
    G->adj[v][u] = 1;
    G->E++;
}

void DFS(struct Graph* G, int v) {
    visited[v] = 1; // mark v as visited
    push_order[push_index++] = v; // push v onto the stack
    int i;
    for (i = 0; i < G->V; i++) {
        if (G->adj[v][i] && !visited[i]) { // if i is adjacent to v and not visited
            DFS(G, i); // recursively visit i
        }
    }
    pop_order[pop_index++] = v; // pop v from the stack
}

int main() {
    int V, E, i, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    struct Graph* G = createGraph(V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    printf("Enter the edges:\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(G, u, v);
    }
    printf("DFS traversal:\n");
    for (i = 0; i < V; i++) {
        visited[i] = 0; // mark all vertices as unvisited
    }
    for (i = 0; i < V; i++) {
        if (!visited[i]) { // if i is not visited
            DFS(G, i); // visit i and its connected component
        }
    }
    printf("Push order: ");
    for (i = 0; i < V; i++) {
        printf("%d ", push_order[i]);
    }
    printf("\nPop order: ");
    for (i = 0; i < V; i++) {
        printf("%d ", pop_order[i]);
    }
    printf("\n");
    return 0;
}
