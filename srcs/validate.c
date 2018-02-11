/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:53:44 by egreen            #+#    #+#             */
/*   Updated: 2018/02/11 12:13:04 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		find_start(t_info *data)
{
	int		i;

	i = 0;
	while (data->file[i])
	{
		if (ft_strstr("##start", data->file[i]))
		{
			if (data->file[i + 1][0] == '#')
				ft_error("\nERROR: invalid start room");
			data->start = i;
			data->startcount++;
		}
		i++;
	}
	if (data->start == -1 || data->startcount > 1)
		ft_error("\nERROR: no start found");
	if (check_start_room(data))
		;
	else
		ft_error("\nERROR: end == start");
}

void		find_end(t_info *data)
{
	int		i;

	i = 0;
	while (data->file[i])
	{
		if (ft_strstr("##end", data->file[i]))
		{
			data->end = i;
			break ;
		}
		i++;
	}
	if (data->end == -1)
		ft_error("\nERROR: no end room");
	if (check_end_room(data))
		;
	if (ft_strcmp(data->startstr, data->endstr) == 0)
		ft_error("\nERROR: start == end");
}

static void	commentsafterpipes(t_info *data)
{
	int		i;
	int		comment;
	int		commentcount;
	int		pipe;

	i = data->linecount - 1;
	comment = 0;
	commentcount = 0;
	pipe = 0;
	while (data->file[i])
	{
		if (data->file[i][0] == '#')
		{
			comment = i;
			commentcount++;
		}
		else if (ft_strchr(data->file[i], '-'))
		{
			pipe = i;
			break ;
		}
		i--;
	}
	if (comment > pipe)
		data->linecount -= commentcount;
}

void		find_pipes(t_info *data)
{
	int		i;

	i = 0;
	while (data->file[i])
	{
		if ((ft_strchr(data->file[i], '-')) && (i < data->end))
			ft_error("\nERROR: pipes in rooms");
		if ((ft_strchr(data->file[i], '-') || data->file[i][0]
					== '#') && i > data->end)
		{
			if (data->file[i][0] != '#')
			{
				data->pipestart = i;
				break ;
			}
		}
		i++;
	}
	find_pipes_helper(data);
	commentsafterpipes(data);
	data->pipes = (char **)ft_memalloc(sizeof(data->pipes) *
			data->pipecount + 1);
	assign_pipes(data);
}

void		validate(t_info *data)
{
	find_start(data);
	find_end(data);
	if (data->start > data->end)
	{
		ft_swap(&data->end, &data->start);
		data->swap = 1;
	}
	find_pipes(data);
	assign_rooms(data);
}
