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
 
void printGraph(t_graph *graph, t_info *data)
{
    int i = 0;
    printf("graph->name: %s\n", graph->name[0]);
    while (i < data->roomcount && (data->solution[i] != NULL))
    {
        printf("data->solution[%d]: %s\n", i, data->solution[i]);
        i++;
    }
    printf("ants: %d\n", data->ants);
    int j = 1;
  
    while (j < data->roomcount && (data->solution[j] != NULL))
    {     
        i = 1;
        while (i < data->ants + 1)
        {
            printf("L%d-%s\n", i, data->solution[j]);
            i++;
        }
        j++;
    }



    // printf("ants: %d\n", data->ants);
    // graph->index = 0;
    // while (graph->index < graph->numVertices)
    // {
    //     // printf("graph->name: %s\t graph->index: %d\n", graph->name[graph->index], graph->index);
    //     t_node *temp = graph->adjLists[graph->index];
    //     // printf("data->solution[%d]: %s\n", graph->index, data->solution[graph->index]);
    //     // printf("data->solution[%d]: %s\n", graph->index, data->solution[graph->index]);
    //     printf("\n Adjacency list of vertex %s \n ", graph->name[graph->index]);
    //     while (temp)
    //     {

    //         printf("%s -> ", temp->name);
    //         temp = temp->next;
    //     }
    //     printf("\n");
    //     graph->index++;
    }

void DFS(t_graph *graph, t_info *data, int index/*start room*/)
{
    int targetindex;
    targetindex = find_target_index(graph, data->endstr);
    t_node *adjList = graph->adjLists[index];
    t_node *temp = adjList;
    graph->visited[index/*one means it's been visited*/] = 1;

    // printf("Visited %s index: %d\n", graph->name[index], index);
    ft_strnew(sizeof(data->solution) * data->roomcount);
    data->solution[data->curr] = ft_strdup(graph->name[index]);
    // printf("data->solution[%d]: %s\n", data->curr, data->solution[data->curr]);
    data->curr++;
    // printf("data->curr: %d\n", data->curr);

    while(temp != NULL) 
    {
        int connectedVertex = temp->index;
        if (connectedVertex == targetindex)
        {
            data->solution[data->curr] = ft_strdup(data->endstr);
            // printf("data->solution[target%d]: %s\n", data->curr, data->solution[data->curr]);
            // printf("target data->curr: %d\n", data->curr);
            // data->solution[data->curr] = NULL;
            // ft_printf("Found it! Target: %s\n", data->endstr);
            printGraph(graph, data);
            exit(0);
        }
        else if (graph->visited[connectedVertex] == 0)
        {
            // printf("recursive data->curr: %d\n", data->curr);
            // ft_strdel(&data->solution[data->curr]);
            DFS(graph, data, connectedVertex);
        }
        temp = temp->next;
    }
    if (temp == NULL)
        ft_error("no solution found ERROR");    
}
