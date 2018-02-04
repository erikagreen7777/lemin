/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:56:15 by egreen            #+#    #+#             */
/*   Updated: 2017/12/03 09:52:23 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_width(t_spec *ts)
{
	int print;

	if (ts->prec >= 0 && ts->prec < ts->len)
		print = ts->width - ts->prec;
	else
		print = ts->width - ts->len;
	while (print > 0)
	{
		ft_putchar_fd(' ', *ts->fd);
		print--;
		*ts->ret = *ts->ret + 1;
	}
}

static void	print_prec(t_spec *ts)
{
	int print;

	if (ts->prec != -1 && ts->prec < ts->len)
		print = ts->prec;
	else
		print = ts->len;
	if (ts->data.str == 0)
	{
		write(*ts->fd, "(null)", 6);
		*ts->ret += 6;
	}
	else
	{
		write(*ts->fd, ts->data.str, print);
		*ts->ret = *ts->ret + print;
	}
}

void		format_string(t_print *ptr, t_spec *ts)
{
	if (ts->lgth[0] == '*')
		ts->width = va_arg(ptr->arg, int);
	ts->data.str = va_arg(ptr->arg, char*);
	if (ts->data.str == NULL)
		ts->len = 0;
	else
		ts->len = ft_strlen(ts->data.str);
	if (ts->left_align == true)
	{
		print_prec(ts);
		print_width(ts);
	}
	else
	{
		print_width(ts);
		print_prec(ts);
	}
}
