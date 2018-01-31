#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "libft/printf.h"

# define BUFF_SIZE 256

struct node
{
    int vertex;
    struct node* next;
};

struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
};

typedef struct  s_info
{
    int	    start;
    char    *startingroom;
	char 	*startstr;
	int     end;
    char    *endingroom;
    char    *endstr;
	int		ants;
    char    **file;
	char	*name;
    char    *line;
}			t_info;

struct node* createNode(int v);
struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);
void printGraph(struct Graph*);
void DFS(struct Graph*, int);
void    find_start(t_info *data);
void    validate(t_info *data);

#endif
