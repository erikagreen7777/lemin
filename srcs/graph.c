#include "../lemin.h"

t_node *createNode(int v)
{
    t_node *newNode = malloc(sizeof(t_node));
    newNode->index = v;
    newNode->name = NULL;
    newNode->next = NULL;
    return (newNode);
}


void addEdgeString(t_graph *graph, char *src, char *dest)
{
    int srcindex;
    int destindex;
    srcindex = find_src_index(graph, src);
    destindex = find_dest_index(graph, dest); 

    // Add edge from src to dest
    t_node *newNode = createNode(destindex);
    newNode->name = dest;
    newNode->next = graph->adjLists[srcindex];
    graph->adjLists[srcindex] = newNode; 
    
    // Add edge from dest to src
    newNode = createNode(srcindex);
    newNode->next = graph->adjLists[destindex];
    newNode->name = src;
    graph->adjLists[destindex] = newNode; 
}
 
void printGraph(t_graph *graph)
{
    for (graph->index = 0; graph->index < graph->numVertices; graph->index++)
    {  
        // printf("graph->name: %s\t graph->index: %d\n", graph->name[graph->index], graph->index);
        t_node *temp = graph->adjLists[graph->index];
        printf("\n Adjacency list of vertex %s \n ", graph->name[graph->index]);
        while (temp)
        {

            printf("%s -> ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(t_graph *graph, t_info *data, int index/*start room*/)
{
    int targetindex;
    int antcount = 1;

    targetindex = find_target_index(graph, data->endstr);
    t_node *adjList = graph->adjLists[index];
    t_node *temp = adjList;

    graph->visited[index/*one means it's been visited*/] = 1;
    // printf("Visited %s \n", graph->name[index]);

    while(temp != NULL)
    {
        int connectedVertex = temp->index;
        while (antcount < data->ants + 1)
        {
            ft_printf("L%d-%s ", antcount, graph->name[index]);
            antcount++;
        }
        ft_putchar('\n');
        if (connectedVertex == targetindex)
        {
            antcount = 1;
            while (antcount < data->ants + 1){
                ft_printf("L%d-%s ", antcount, data->endstr);
                antcount++;
            }
            ft_putchar('\n');
            // ft_printf("Found it! Target: %s\n", data->endstr);
            exit(0);
        }
        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, data, connectedVertex);
        }
        temp = temp->next;
    }
    if (temp == NULL)
        ft_error("no solution found ERROR");
}

// void DFS(t_graph *graph, t_info *data, int index/*start room*/)
// {
//     int targetindex;

//     targetindex = find_target_index(graph, data->endstr);
//     t_node *adjList = graph->adjLists[index];
//     t_node *temp = adjList;
        
//     graph->visited[index/*one means it's been visited*/] = 1;
//     printf("Visited %s \n", graph->name[index]);

//     while(temp != NULL) 
//     {
//         int connectedVertex = temp->index;
//         if (connectedVertex == targetindex)
//         {
//             ft_printf("Found it! Target: %s\n", data->endstr);
//             exit(0);
//         }
//         if (graph->visited[connectedVertex] == 0)
//         {
//             DFS(graph, data, connectedVertex);
//         }
//         temp = temp->next;
//     }
//     if (temp == NULL)
//         ft_error("no solution found ERROR");    
// }
