/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 14:01:43 by egreen            #+#    #+#             */
/*   Updated: 2018/02/11 14:10:52 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "libft/printf.h"

# define BUFF_SIZE 256

typedef struct		s_node
{
	int				index;
	char			*name;
	struct s_node	*next;
}					t_node;

typedef struct		s_graph
{
	int				num_vert;
	int				*visited;
	int				index;
	char			**name;
	t_node			**adjlists;
}					t_graph;

typedef struct		s_info
{
	int				fd;
	int				curr;
	int				start;
	int				swap;
	int				pipestart;
	char			*startingroom;
	char			*startstr;
	int				end;
	char			*endingroom;
	char			*endstr;
	char			**pipes;
	int				startcount;
	int				linecount;
	int				roomcount;
	int				pipecount;
	char			**rooms;
	int				ants;
	int				currant;
	char			**file;
	char			*name;
	char			*line;
	char			**vertex;
	char			**solution;
	int				print_graph;
}					t_info;

t_node				*create_node(int v);
t_graph				*create_graph(t_info *data);
void				add_edge(t_info *data, t_graph *graph, int src, int dest);
void				add_edge_string(t_graph *graph, char *src, char *dest);
void				print_graph(t_info *data);
int					dfs(t_graph *graph, t_info *data, int targetindex);
void				find_start(t_info *data);
void				validate(t_info *data);
int					check_start_room(t_info *data);
int					check_end_room(t_info *data);
char				*room_trim(char *str);
void				assign_rooms(t_info *data);
int					check_duplicates(t_info *data, int pipeorroom);
void				parse_pipes(t_info *data, t_graph *graph);
void				assign_pipes(t_info *data);
int					find_target_index(t_graph *graph, char *src);
int					find_start_index(t_graph *graph, char *src);
int					find_src_index(t_graph *graph, char *src);
int					find_dest_index(t_graph *graph, char *dest);
void				free_data(t_info *data);
int					check_room(char *str);
int					find_pipes_helper(t_info *data);

#endif
