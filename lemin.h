#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "libft/printf.h"

# define BUFF_SIZE 256

typedef struct s_node
{
    int index;
    char *name;
    struct s_node *next;
}               t_node;

typedef struct s_graph
{
    int numVertices;
    int *visited;
    int index;
    char **name; 
    t_node **adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
}               t_graph;


typedef struct  s_info
{
    int     fd;
    int     curr;
    int	    start;
    int     swap;
    int     pipestart;
    char    *startingroom;
	char 	*startstr;
	int     end;
    char    *endingroom;
    char    *endstr;
    char    **pipes;
	int 	linecount;
    int     roomcount;
    int     pipecount;
    char    **rooms;
	int		ants;
    int     currant;
    char    **file;
	char	*name;
    char    *line;
    char    **vertex;
    char    **solution;
}			t_info;

t_node 	*createNode(int v);
t_graph *createGraph(t_info *data);
void 	addEdge(t_info *data, t_graph *graph, int src, int dest);
void    addEdgeString(t_graph *graph, char *src, char *dest);
void 	printGraph(t_graph *graph,t_info *data);
int 	DFS(t_graph *graph, t_info *data, int targetindex);
void    find_start(t_info *data);
void    validate(t_info *data);
int     check_start_room(t_info *data);
int     check_end_room(t_info *data);
char    *room_trim(char *str);
void    assign_rooms(t_info *data);
int    check_duplicates(t_info *data, int pipeorroom);
void    parse_pipes(t_info *data, t_graph *graph);
void    assign_pipes(t_info *data);
int     find_target_index(t_graph *graph, char *src);
int     find_start_index(t_graph *graph, char *src);
int     find_src_index(t_graph *graph, char *src);
int     find_dest_index(t_graph *graph, char *dest);
void    free_data(t_info *data/*, t_graph *graph*/);

#endif

//data->solution 88888
//t_node *newNode
//data->rooms 8888
//data->file 88888
//*graph
// graph->name 888
// graph->adjLists
// graph->visited
//*data 8888
