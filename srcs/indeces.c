/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indeces.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:38:47 by egreen            #+#    #+#             */
/*   Updated: 2018/02/11 11:52:43 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

char		*room_trim(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup(str);
	ft_strclr(str);
	while (temp[i])
	{
		if (temp[i] == ' ')
		{
			if (check_room(temp) == 1)
				ft_error("\nERROR: room trim");
			else
				break ;
		}
		i++;
	}
	ft_strncpy(str, temp, i);
	ft_strdel(&temp);
	return (str);
}

int			find_target_index(t_graph *graph, char *src)
{
	int		targetindex;

	targetindex = -1;
	graph->index = 0;
	while (graph->name[graph->index])
	{
		if (ft_strstr(graph->name[graph->index], src))
		{
			if (ft_strcmp(graph->name[graph->index], src) == 0)
			{
				targetindex = graph->index;
				return (targetindex);
			}
		}
		graph->index++;
	}
	return (0);
}

int			find_start_index(t_graph *graph, char *src)
{
	int		startindex;

	startindex = -1;
	graph->index = 0;
	while (graph->name[graph->index])
	{
		if (ft_strstr(graph->name[graph->index], src))
		{
			if (ft_strcmp(graph->name[graph->index], src) == 0)
			{
				startindex = graph->index;
				return (startindex);
			}
		}
		graph->index++;
	}
	return (0);
}

int			find_src_index(t_graph *graph, char *src)
{
	int		srcindex;

	srcindex = -1;
	graph->index = 0;
	while (graph->name[graph->index])
	{
		if (ft_strstr(graph->name[graph->index], src))
		{
			if (ft_strcmp(graph->name[graph->index], src) == 0)
			{
				srcindex = graph->index;
				return (srcindex);
			}
		}
		graph->index++;
	}
	return (0);
}

int			find_dest_index(t_graph *graph, char *dest)
{
	int		destindex;

	destindex = -1;
	graph->index = 0;
	while (graph->name[graph->index])
	{
		if (ft_strstr(graph->name[graph->index], dest))
		{
			if (ft_strcmp(graph->name[graph->index], dest) == 0)
			{
				destindex = graph->index;
				return (destindex);
			}
		}
		graph->index++;
	}
	return (0);
}
