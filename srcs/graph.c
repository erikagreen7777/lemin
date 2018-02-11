/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:25:25 by egreen            #+#    #+#             */
/*   Updated: 2018/02/10 16:53:10 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_node		*create_node(int v)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->index = v;
	new_node->name = NULL;
	new_node->next = NULL;
	return (new_node);
}

void		add_edge_string(t_graph *graph, char *src, char *dest)
{
	int		srcindex;
	int		destindex;
	t_node	*new_node;

	srcindex = find_src_index(graph, src);
	destindex = find_dest_index(graph, dest);
	new_node = create_node(destindex);
	new_node->name = dest;
	new_node->next = graph->adjlists[srcindex];
	graph->adjlists[srcindex] = new_node;
	new_node = create_node(srcindex);
	new_node->next = graph->adjlists[destindex];
	new_node->name = src;
	graph->adjlists[destindex] = new_node;
}

void		print_graph(t_info *data)
{
	int		i;
	int		j;

	data->print_graph = 1;
	j = 1;
	i = 0;
	ft_putchar('\n');
	while (j < data->roomcount && data->solution[j] != NULL)
	{
		i = 1;
		while (i < data->ants + 1)
		{
			ft_printf("L%d-%s\n", i, data->solution[j]);
			i++;
		}
		j++;
	}
}

int			dfs(t_graph *graph, t_info *data, int index)
{
	int		targetindex;
	int		convertex;
	t_node	*adjlist;
	t_node	*temp;

	targetindex = find_target_index(graph, data->endstr);
	adjlist = graph->adjlists[index];
	temp = adjlist;
	graph->visited[index] = 1;
	data->solution[data->curr] = graph->name[index];
	data->curr++;
	while (temp != NULL)
	{
		convertex = temp->index;
		if (convertex == targetindex)
		{
			data->solution[data->curr] = data->endstr;
			print_graph(data);
			exit(0);
		}
		else if (graph->visited[convertex] == 0)
			dfs(graph, data, convertex);
		temp = temp->next;
	}
	return (1);
}
