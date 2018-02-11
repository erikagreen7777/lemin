/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 10:25:38 by egreen            #+#    #+#             */
/*   Updated: 2018/02/11 10:50:29 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int				check_start_room(t_info *data)
{
	while (data->file[data->start])
	{
		if (data->file[data->start][0] == '#')
			data->start++;
		if ((data->file[data->start][0] != '#') &&
				(data->file[data->start][0] != 'L'))
		{
			data->startstr = room_trim(data->file[data->start]);
			return (1);
		}
	}
	return (0);
}

int				check_end_room(t_info *data)
{
	while (data->file[data->end])
	{
		if (data->file[data->end][0] == '#')
			data->end++;
		if ((data->file[data->end][0] != '#') &&
				(data->file[data->end][0] != 'L'))
		{
			data->endstr = room_trim(data->file[data->end]);
			return (1);
		}
	}
	return (0);
}

int				check_room(char *str)
{
	int			i;
	int			spacecount;

	i = 0;
	spacecount = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			spacecount++;
			if ((!ft_isdigit(str[i + 1])) && (str[i + 1] != '-'
						&& !ft_isdigit(str[i + 2])))
				return (1);
		}
		i++;
	}
	if (spacecount != 3)
		ft_error("\nERROR: spacecount");
	return (0);
}

static void		check_room_duplicates(t_info *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data->roomcount)
	{
		j = i + 1;
		while (j < data->roomcount)
		{
			if (ft_strcmp(data->rooms[i], data->rooms[j]) == 0)
				ft_error("\nERROR: duplicate rooms");
			else
				j++;
		}
		i++;
	}
}

void			assign_rooms(t_info *data)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	data->rooms = (char **)ft_memalloc(sizeof(char *) * data->linecount);
	while (data->file[i])
	{
		if (data->file[i][0] == 'L')
			ft_error("\nERROR: couldn't assign rooms");
		if ((!ft_strchr(data->file[i], '-') && (data->file[i][0] != '#')))
		{
			data->rooms[j] = ft_strdup(data->file[i]);
			room_trim(data->rooms[j]);
			data->roomcount++;
			j++;
		}
		i++;
	}
	if (data->roomcount == 0)
		ft_error("\nERROR: room assign");
	check_room_duplicates(data);
}
