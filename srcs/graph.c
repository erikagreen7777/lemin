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
    int i = 1;
    int j = 1;
   

    printf("graph->index: %d\ndata->ants: %d\n", graph->index, data->ants);
    printf("data->roomcount; %d\n", data->roomcount);
    while (i < data->ants + 1)
    {
        j = 1;
        while (j < data->roomcount)
        {
            printf("L%d-%s\n", i, data->solution[j]);
            j++;
        }
        i++;
    }

    // while (j < k)
    // {
    //     while (i < data->ants + 1)
    //     {
    //         printf("L%d-%s\n", i, data->solution[i]);
    //         i++;
    //     }
    //     j++;
    // }
    // exit(0);
    // for (graph->index = 0; graph->index < graph->numVertices; graph->index++)
    // {  
    //     // printf("graph->name: %s\t graph->index: %d\n", graph->name[graph->index], graph->index);
    //     t_node *temp = graph->adjLists[graph->index];
    //     // printf("data->solution[%d]: %s\n", graph->index, data->solution[graph->index]);
    //     printf("\n Adjacency list of vertex %s \n ", graph->name[graph->index]);
    //     while (temp)
    //     {

    //         printf("%s -> ", temp->name);
    //         temp = temp->next;
    //     }
    //     printf("\n");
    // }
}

// void DFS(t_graph *graph, t_info *data, int index/*start room*/)
// {
//     int targetindex;

//     targetindex = find_target_index(graph, data->endstr);
//     t_node *adjList = graph->adjLists[index];
//     t_node *temp = adjList;

//     graph->visited[index/*one means it's been visited*/] = 1;
//     // printf("Visited %s \n", graph->name[index]);

//     while(temp != NULL)
//     {
//         int connectedVertex = temp->index;
//         while (data->currant < data->ants + 1)
//         {
//                 ft_printf("L%d-%s\n", data->currant, graph->name[index]);

//             if (connectedVertex == targetindex)
//             {
//                 ft_printf("L%d-%s ", data->currant, data->endstr);
//                 ft_putchar('\n');
//                 // ft_printf("Found it! Target: %s\n", data->endstr);
//                 if (data->currant == data->ants + 1)
//                     exit(0);
//             }
//             if (graph->visited[connectedVertex] == 0)
//             {
//                 DFS(graph, data, connectedVertex);
//             }
//             data->currant++;
//         }
//         temp = temp->next;
//     }
//     if (temp == NULL)
//         ft_error("no solution found ERROR");
// }

void DFS(t_graph *graph, t_info *data, int index/*start room*/)
{
    int targetindex;
    int i = index;
    targetindex = find_target_index(graph, data->endstr);
    t_node *adjList = graph->adjLists[index];
    t_node *temp = adjList;
        
    graph->visited[index/*one means it's been visited*/] = 1;
    printf("Visited %s \n", graph->name[index]);
    data->solution[i] = ft_strdup(graph->name[i]);
    // printf("data->solution[i]: %s\n", data->solution[i]);
    i++;
    while(temp != NULL) 
    {
        int connectedVertex = temp->index;
        if (connectedVertex == targetindex)
        {
            data->solution[i] = ft_strdup(data->endstr);
            // printf("data->solution[j]: %s\n", data->solution[i]);
            ft_printf("Found it! Target: %s\n", data->endstr);
            break;
                // exit(0);
        }
        else if (graph->visited[connectedVertex] == 0)
        {
            i++;
            DFS(graph, data, connectedVertex);
        }
        temp = temp->next;
    }

    if (temp == NULL)
        ft_error("no solution found ERROR");    
}
