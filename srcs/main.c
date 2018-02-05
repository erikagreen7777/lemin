#include "../lemin.h"

static void ants(t_info *data)
{
    int i;
    i = 0;
    data->ants = ft_atoi(data->file[0]);
    if (data->ants < 1)
        ft_error("ants ERROR");
//    else
//        printf("data->ants: %d\n", data->ants);

}
static void build_file(t_info *data)
{
    int i;
    i = 0;
    data->file = (char **)ft_memalloc(sizeof(char **) * 5000);
    // while (get_next_line(data->fd, &data->line) > 0)
    while (get_next_line(0, &data->line) > 0)
    {
        data->file[i] = (data->line);
        i++;
    }
    if (data->line == NULL)
        ft_error("line ERROR");
    data->linecount = i;
    i = -1;
    while (data->file[++i])
        printf("data->file[%d]: %s\n", i, data->file[i]);
    // printf("linecount: %d\n", data->linecount);
}

static void i_like_big_structs_and_i_cannot_lie(t_info *data)
{
    char *filename = "maps/input2";
    data->fd = open(filename, O_RDONLY);
    data->start = -1;
    data->end = -1;
    data->ants = 0;
    data->name = NULL;
    data->line = NULL;
    data->file = NULL;
    data->startingroom = NULL;
    data->endingroom = NULL;
    data->startstr = NULL;
    data->endstr = NULL;
    data->linecount = -1;
    data->rooms = NULL;
    data->curr = 0;
    data->roomcount = 0;
    data->pipecount = 0;
    data->pipestart = 0;
    data->swap = 0;
    data->vertex = NULL;
}

int main(int argc, char **argv)
{
    t_info *data;
    t_graph *graph;

    if (argc == 1)
        ;
    data = (t_info *)ft_memalloc(sizeof(t_info));
    
    i_like_big_structs_and_i_cannot_lie(data);
    data->name = argv[1];
    build_file(data);
    ants(data);
    validate(data);
    graph = createGraph(data);
    parse_pipes(data, graph);
    // printGraph(graph);

    // DFS(graph, 2);
    
    return 0;
}

t_graph *createGraph(t_info *data)
{
    int i;
    i = 0;
    t_graph *graph = malloc(sizeof(t_graph));
    graph->numVertices = data->roomcount;
 
    graph->name = malloc(data->roomcount * sizeof(char *));
    graph->adjLists = malloc(data->roomcount * sizeof(t_node *));
    
    graph->visited = malloc(data->roomcount * sizeof(int));
 
    while (i < data->roomcount)
    {
        graph->adjLists[i] = NULL;
        graph->name[i] = data->rooms[i];
        graph->index = i;
        // printf("graph->index: %d\tgraph->name: %s\n", graph->index, graph->name[i]);
        graph->visited[i] = 0;
        graph->index++;
        i++;
    }
    graph->index = 0;
    while (graph->index < data->roomcount)
    {
        printf("graph->index: %d\tgraph->name[i]: %s\tstart: %s\tend: %s\n", graph->index, graph->name[graph->index], 
            data->startstr, data->endstr);
        graph->index++;
    }
    return (graph);
}


t_node *createNode(int v)
{
    t_node *newNode = malloc(sizeof(t_node));
    newNode->index = v;
    newNode->name = NULL;
    newNode->next = NULL;
    return (newNode);
}

void addEdgeString(t_graph *graph, char *src, char *dest, int srcindex, int destindex)
{
    //find a way to sync up the indeces of the graph to the indeces of the linked list
    // Add edge from dest to src

    /*ft_strstr the graph to find the right name and then assign it the graph->index?*/
    graph->index = 0;
    while (graph->name[graph->index])
    {
        if (ft_strstr(graph->name[graph->index], src)){
            srcindex = graph->index;
            break;
        }
        graph->index++;
    }
    // printf("srcindex: %d\tsrc: %s\n", srcindex, src);
    printf("dest:%s\tdestindex: %d\n", dest, destindex);
    // t_node *newNode = createNode(srcindex/*do we need this index? I think it needs to match the graph*/);
    // newNode->next = graph->adjLists[destindex]/*the list that has the name of our dest*/;
    // newNode->name = src;
    // graph->adjLists[destindex] = newNode; 
    // printf("destindex: %d\n", destindex/*do we need this index? I think it needs to match the graph*/);

    // // Add edge from src to dest
    // newNode = createNode(destindex/*do we need this index? I think it needs to match the graph*/);
    // newNode->name = dest;
    // newNode->next = graph->adjLists[srcindex]/*the list that has the name of our src*/;
    // graph->adjLists[srcindex] = newNode; 
    // printf("srcindex: %d\n", srcindex/*do we need this index? I think it needs to match the graph*/);
}
 

// void printGraph(t_graph *graph)
// {
//     // int v;
//     // for (v = 0; v < graph->numVertices; v++)
//     // {
//     for (graph->index = 0; graph->index < graph->numVertices; graph->index++)
//     {  
//         printf("graph->name: %s\t graph->index: %d\n", graph->name[graph->index], graph->index);
//         t_node *temp = graph->adjLists[graph->index];
//         printf("\n Adjacency list of vertex %s \n ",graph->name[graph->index]);
//         while (temp)
//         {

//             printf("%s -> ", temp->name);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }
