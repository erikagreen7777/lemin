#include "../lemin.h"

static void validate(t_info *data)
{
    char *line;
    line = data->name;
    while (get_next_line(0, &line) > 0)
    {
        //DO PIPING IN VALIDATION THING HERE (IF ARGC == 2), ETC
        printf("string: %s\n", line);
    }
}

static void init_struct(t_info *data)
{
    data->start = NULL;
    data->end = NULL;
    data->ants = 0;
    data->name = NULL;
}

int main(int argc, char **argv)
{
    t_info *data;

    data = (t_info *)ft_memalloc(sizeof(t_info));
    init_struct(data);
    data->name = argv[1];
    ft_printf("argc: %d\tdata->name: %s\n", argc, data->name);
    validate(data);
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    
    printGraph(graph);

    DFS(graph, 2);
    
    return 0;
}

void DFS(struct Graph* graph, int vertex) {
        struct node* adjList = graph->adjLists[vertex];
        struct node* temp = adjList;
        
        // int target = 1;
        graph->visited[vertex] = 1;
        printf("Visited %d \n", vertex);
    
        while(temp!=NULL) {
            int connectedVertex = temp->vertex;
        
            // if (connectedVertex == target)
            // {
            //     ft_printf("Found it! Target: %d\n", connectedVertex);
            //     exit(0);
            // }
            if (graph->visited[connectedVertex] == 0) {
                DFS(graph, connectedVertex);
            }
            temp = temp->next;
        }       
}
 
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    
    graph->visited = malloc(vertices * sizeof(int));
 
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
 
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
