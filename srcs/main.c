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
    while (get_next_line(data->fd, &data->line) > 0)
    // while (get_next_line(0, &data->line) > 0)
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
    char *filename = "maps/simple";
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
    data->solution = (char **)ft_memalloc(sizeof(data->roomcount + 1));
    DFS(graph, data, startindex);
    printGraph(graph, data);
    return 0;
}


