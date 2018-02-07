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

    t_node *newNode = createNode(destindex);
    newNode->name = dest;
    newNode->next = graph->adjLists[srcindex];
    graph->adjLists[srcindex] = newNode; 
    
    newNode = createNode(srcindex);
    newNode->next = graph->adjLists[destindex];
    newNode->name = src;
    graph->adjLists[destindex] = newNode; 
}
 
void printGraph(t_graph *graph, t_info *data)
{
    int i = 0;
   ft_printf("graph->name: %s\n", graph->name[0]);
    // while (i < data->roomcount && (data->solution[i] != NULL))
    // {
    //     ft_printf("data->solution[%d]: %s\n", i, data->solution[i]);
    //     i++;ß
    // }
    int j = 1;
    while (j < data->roomcount && (data->solution[j] != NULL))
    {     
        i = 1;
        while (i < data->ants + 1)
        {
            ft_printf("L%d-%s\n", i, data->solution[j]);
            i++;
        }
        j++;
    }
    // data->solution[j] = NULL;
    // while (1)
    // {
        
    // }
}

void DFS(t_graph *graph, t_info *data, int index)
{
    int targetindex;
    targetindex = find_target_index(graph, data->endstr);
    t_node *adjList = graph->adjLists[index];
    t_node *temp = adjList;
    graph->visited[index] = 1;

    // data->solution[data->curr] = ft_strnew(sizeof(char *)/* * data->roomcount*/);
    int i = 0;
    while (data->solution[i])
    {
        data->solution[data->curr] = ft_strnew(sizeof(char *)/* * data->roomcount*/);
        i++;
    }
    data->solution[data->curr] = ft_strdup(graph->name[index]);
    data->curr++;
    while(temp != NULL) 
    {
        int connectedVertex = temp->index;
        if (connectedVertex == targetindex)
        {
            // data->solution[data->curr] = ft_strnew(sizeof(char *)/* * data->roomcount*/);
            data->solution[data->curr] = ft_strdup(data->endstr);
            printGraph(graph, data);
            exit(0);
        }
        else if (graph->visited[connectedVertex] == 0)
            DFS(graph, data, connectedVertex);
        temp = temp->next;
    }
    if (temp == NULL)
        ft_error("no solution found ERROR");    
}

