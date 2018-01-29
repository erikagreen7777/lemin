/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:55:22 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 11:58:16 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_width(t_spec *ts)
{
	int		print;

	print = ts->width - ts->len;
	while (print > 0)
	{
		ft_putchar_fd(' ', *ts->fd);
		print--;
		*ts->ret = *ts->ret + 1;
	}
}

static void	print_char(char output, int *ret, int fd)
{
	ft_putchar_fd(output, fd);
	*ret = *ret + 1;
}

void		format_char(t_print *ptr, t_spec *ts)
{
	ts->data.chr = (char)va_arg(ptr->arg, int);
	ts->len = 1;
	if (ts->left_align == true)
	{
		print_char(ts->data.chr, ts->ret, *ts->fd);
		print_width(ts);
	}
	else
	{
		print_width(ts);
		print_char(ts->data.chr, ts->ret, *ts->fd);
	}
}
