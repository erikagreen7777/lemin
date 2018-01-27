// A C Program to demonstrate adjacency list representation of graphs
 
#include <stdio.h>
#include <stdlib.h>
 
// adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};
 
// adjacency list
struct AdjList {
    struct AdjListNode *head; // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph {
    int V;
    struct AdjList* array;
};
 
// create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(
            sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// creates a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    printf("src: %d\tdest: %d\tbefore (graph->array[src].head) newNode->next: %p\n", src, dest, newNode->next);
    newNode->next = graph->array[src].head;
    printf("src: %d\tdest: %d\tafter (graph->array[src].head) newNode->next: %p\n", src, dest, newNode->next);
    graph->array[src].head = newNode;
 
    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    printf("src: %d\tdest: %d\tbefore (graph->array[dest].head) newNode->next: %p\n", src, dest, newNode->next);
    newNode->next = graph->array[dest].head;
    printf("src: %d\tdest: %d\tafter (graph->array[dest].head) newNode->next: %p\n", src, dest, newNode->next); // this one is the only one that prints anything until later?
    graph->array[dest].head = newNode;
}
 
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 
// Driver program to test above functions
int main() {
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    printf("1");
    addEdge(graph, 0, 4);
    printf("2");
    addEdge(graph, 1, 2);
    printf("3");
    addEdge(graph, 1, 3);
    printf("4");
    addEdge(graph, 1, 4);
    printf("5");
    addEdge(graph, 2, 3);
    printf("6");
    addEdge(graph, 3, 4);
    printf("7");
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}
// Output:

// $ gcc AdjacencyList.c
// $ ./a.out
 
// Adjacency list of vertex 0
//  head -> 4-> 1
 
//  Adjacency list of vertex 1
//  head -> 4-> 3-> 2-> 0
 
//  Adjacency list of vertex 2
//  head -> 3-> 1
 
//  Adjacency list of vertex 3
//  head -> 4-> 2-> 1
 
//  Adjacency list of vertex 4
//  head -> 3-> 1-> 0


// *********************************************************************************************************
