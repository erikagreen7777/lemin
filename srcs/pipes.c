/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 09:10:17 by egreen            #+#    #+#             */
/*   Updated: 2018/02/11 12:15:26 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int	ft_isalnumunderscore(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123) ||
			(c > 47 && c < 58) || c == '_')
		return (1);
	return (0);
}

static int	is_pipe(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			break ;
		i++;
	}
	if (!ft_isalnumunderscore(str[i - 1]) ||
			(!ft_isalnumunderscore(str[i + 1])))
		return (1);
	return (0);
}

int			find_pipes_helper(t_info *data)
{
	int		i;
	int		commentcount;

	i = data->pipestart;
	commentcount = 0;
	while (data->file[i])
	{
		if ((ft_strchr(data->file[i], '-') || data->file[i][0]
					== '#') && i > data->end)
		{
			if (data->file[i][0] == '#')
				commentcount++;
			data->pipecount++;
		}
		i++;
	}
	if (data->pipecount == 0)
		ft_error("\nERROR: no pipes found");
	data->pipecount -= commentcount;
	return (0);
}

void		assign_pipes(t_info *data)
{
	int		i;
	int		j;

	i = data->pipestart;
	j = 0;
	while (data->file[i])
	{
		if (!(ft_strchr(data->file[i], '-')) && (data->file[i][0] != '#'))
			ft_error("\nERROR: not a pipe");
		if (ft_strchr(data->file[i], '-'))
		{
			if ((is_pipe(data->file[i]) == 1))
				ft_error("\nERROR: not a pipe (1)");
			if (((i < data->start || i < data->end)) ||
					(i == data->start || i == data->end))
				ft_error("\nERROR: couldn't assign a pipe");
			else
				data->pipes[j] = ft_strdup(data->file[i]);
			j++;
		}
		i++;
	}
	data->pipes[j] = NULL;
}

void		parse_pipes(t_info *data, t_graph *graph)
{
	int		i;

	i = 0;
	while (data->pipes[i])
	{
		data->vertex = ft_strsplit(data->pipes[i], '-');
		add_edge_string(graph, data->vertex[0], data->vertex[1]);
		ft_strdel(&data->vertex[0]);
		ft_strdel(&data->vertex[1]);
		free(data->vertex);
		i++;
	}
}
