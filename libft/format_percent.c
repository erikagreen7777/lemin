/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:55:58 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:22:56 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_width(t_spec *ts)
{
	int print;

	print = ts->width - ts->len;
	while (print > 0)
	{
		ft_putchar_fd(' ', *ts->fd);
		print--;
		*ts->ret = *ts->ret + 1;
	}
}

static void	print_percent(t_spec *ts)
{
	ft_putchar_fd('%', *ts->fd);
	*ts->ret = *ts->ret + 1;
}

void		format_percent(t_spec *ts)
{
	ts->len = 1;
	if (ts->left_align == true)
	{
		print_percent(ts);
		print_width(ts);
	}
	else
	{
		print_width(ts);
		print_percent(ts);
	}
}
