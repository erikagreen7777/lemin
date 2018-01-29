/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:56:56 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:22:01 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	constructor(t_print *ptr, t_spec *ts)
{
	ts->left_align = false;
	ts->show_sign = false;
	ts->prepend_space = false;
	ts->prepend_zero = false;
	ts->aform = false;
	ts->width = 0;
	ts->prec = -1;
	ts->lgth[0] = '\0';
	ts->lgth[1] = '\0';
	ts->lgth[2] = '\0';
	ts->type = 0;
	ts->len = 0;
	ptr->wstr = false;
	ts->arg = &ptr->arg;
	ts->fd = &ptr->fd;
	ts->ret = &ptr->ret;
}

static void	type_finder(t_print *ptr, int *xptr)
{
	t_spec	ts;

	constructor(ptr, &ts);
	find_flags(&ts, ptr->format, xptr);
	if (ts.type == 's')
		format_string(ptr, &ts);
	else if (ts.type == 'S' || (ts.type == 'l'\
				&& ptr->format[++*xptr] == 's'))
		format_wstring(ptr, &ts);
	else if (ts.type == 'd' || ts.type == 'U' ||\
			ts.type == 'i' || ts.type == 'D')
		format_decimal(ptr, &ts);
	else if (ts.type == 'c' || ts.type == 'C')
		format_char(ptr, &ts);
	else if (ts.type == '%')
		format_percent(&ts);
	else if (ts.type == 'p')
		format_pointer(ptr, &ts);
	else if (ts.type == 'o')
		format_octal(ptr, &ts);
	else if (ts.type == 'x' || ts.type == 'X')
		format_hex(ptr, &ts);
	else if (ts.type == 'u')
		format_udecimal(ptr, &ts);
}

static void	print_buffer(t_print *ptr, int start, int x)
{
	write(ptr->fd, ptr->format + start, x - start);
	ptr->ret += x - start;
}

void		parse(t_print *ptr)
{
	int		x;
	int		start;

	x = 0;
	start = 0;
	ptr->wstr = false;
	while (ptr->format[x] != '\0')
	{
		if (ptr->format[x] == '%')
		{
			print_buffer(ptr, start, x);
			type_finder(ptr, &x);
			start = x + 1;
		}
		x++;
	}
	if (ptr->wstr == false)
		print_buffer(ptr, start, x);
}
