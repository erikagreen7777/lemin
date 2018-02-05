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

static int find_target_index(t_graph *graph, char *src)
{
    int targetindex = -1;
    graph->index = 0;
    while (graph->name[graph->index])
    {
        if (ft_strstr(graph->name[graph->index], src)){
            targetindex = graph->index;
            // printf("srcindex: %d\tsrc: %s\n", srcindex, src);
            return (targetindex);
        }
        graph->index++;
    }
    return (0);
}

static int find_start_index(t_graph *graph, char *src)
{
    int startindex = -1;
    graph->index = 0;
    while (graph->name[graph->index])
    {
        if (ft_strstr(graph->name[graph->index], src)){
            startindex = graph->index;
            // printf("srcindex: %d\tsrc: %s\n", srcindex, src);
            return (startindex);
        }
        graph->index++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_info *data;
    t_graph *graph;
    int startindex;

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
    startindex = find_start_index(graph, data->startstr);
    DFS(graph, data, startindex);
    printGraph(graph);
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
    // graph->index = 0;
    // while (graph->index < data->roomcount)
    // {
    //     printf("graph->index: %d\tgraph->name[i]: %s\tstart: %s\tend: %s\n", graph->index, graph->name[graph->index], 
    //         data->startstr, data->endstr);
    //     graph->index++;
    // }
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

static int find_src_index(t_graph *graph, char *src)
{
    int srcindex = -1;
    graph->index = 0;
    while (graph->name[graph->index])
    {
        if (ft_strstr(graph->name[graph->index], src)){
            srcindex = graph->index;
            // printf("srcindex: %d\tsrc: %s\n", srcindex, src);
            return (srcindex);
        }
        graph->index++;
    }
    return (0);
}

static int find_dest_index(t_graph *graph, char *dest)
{
    int destindex = -1;
    graph->index = 0;
    while (graph->name[graph->index])
    {
        if (ft_strstr(graph->name[graph->index], dest)){
            destindex = graph->index;
            // printf("destindex: %d\tdest:%s\n", destindex, dest);
            return (destindex);
        }
        graph->index++;
    }
    return (0);
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

    targetindex = find_target_index(graph, data->endstr);
    t_node *adjList = graph->adjLists[index];
    t_node *temp = adjList;
        
    graph->visited[index/*one means it's been visited*/] = 1;
    printf("Visited %s \n", graph->name[index]);

    while(temp != NULL) 
    {
        int connectedVertex = temp->index;
        if (connectedVertex == targetindex)
        {
            ft_printf("Found it! Target: %s\n", data->endstr);
            exit(0);
        }
        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, data, connectedVertex);
        }
        temp = temp->next;
    }       
}
