/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 09:29:01 by egreen            #+#    #+#             */
/*   Updated: 2018/02/11 10:17:45 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static void	ants(t_info *data)
{
	data->ants = ft_atoi(data->file[0]);
	if (data->ants < 1)
		ft_error("\nERROR: no ants");
}

static void	build_file(t_info *data)
{
	int		i;

	i = 0;
	data->file = (char **)ft_memalloc(sizeof(char **) * 5000);
	while (get_next_line(0, &data->line) > 0)
	{
		data->file[i] = (data->line);
		i++;
	}
	if (data->line == NULL)
		ft_error("\nERROR: gnl");
	data->linecount = i;
	i = -1;
	while (data->file[++i])
		ft_printf("%s\n", data->file[i]);
}

static void	i_like_big_structs_and_i_cannot_lie(t_info *data)
{
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
	data->startcount = 0;
	data->print_graph = 0;
}

t_graph		*create_graph(t_info *data)
{
	int		i;
	t_graph	*graph;

	i = 0;
	graph = malloc(sizeof(t_graph));
	graph->num_vert = data->roomcount;
	graph->name = malloc(data->roomcount * sizeof(char *));
	graph->adjlists = (t_node **)ft_memalloc(data->roomcount *
			sizeof(t_node *));
	graph->visited = malloc(data->roomcount * sizeof(int));
	while (i < data->roomcount)
	{
		graph->adjlists[i] = NULL;
		graph->name[i] = data->rooms[i];
		graph->index = i;
		graph->visited[i] = 0;
		graph->index++;
		i++;
	}
	return (graph);
}

int			main(int argc, char **argv)
{
	t_info	*data;
	t_graph	*graph;
	int		startindex;

	if (argc == 1)
		;
	data = (t_info *)ft_memalloc(sizeof(t_info));
	i_like_big_structs_and_i_cannot_lie(data);
	data->name = argv[1];
	build_file(data);
	ants(data);
	validate(data);
	graph = create_graph(data);
	parse_pipes(data, graph);
	startindex = find_start_index(graph, data->startstr);
	data->solution = malloc(data->roomcount * sizeof(char *));
	data->curr = 0;
	dfs(graph, data, startindex);
	if (data->print_graph == 0)
		ft_error("\nno solution found ERROR");
	return (0);
}
