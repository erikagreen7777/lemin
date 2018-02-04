/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_udecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:56:23 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:00:59 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	constructor(t_spec *ts, t_format *form)
{
	form->sign = 0;
	form->print = ft_ptf_itoabase(ts->data.super_u, 10, 0);
	form->lgth = ft_strlen(form->print);
	form->zrs = 0;
	form->spaces = 0;
	if (ts->prec > form->lgth)
		form->zrs += ts->prec - form->lgth;
	if (form->sign != 0)
		form->lgth++;
	if (ts->width > form->lgth + form->zrs)
		form->spaces += ts->width - (form->lgth + form->zrs);
}

static void	print_character(t_spec *ts, char c, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(c, *ts->fd);
		times--;
		*ts->ret = *ts->ret + 1;
	}
}

static void	print_width(t_spec *ts, t_format *form)
{
	if (ts->prepend_zero == true)
	{
		if (form->sign != 0)
			ft_putchar_fd(form->sign, *ts->fd);
		print_character(ts, '0', form->spaces);
	}
	else
		print_character(ts, ' ', form->spaces);
}

void		format_udecimal(t_print *ptr, t_spec *ts)
{
	t_format form;

	unsigned_casting(ptr, ts);
	constructor(ts, &form);
	if (ts->show_sign == true)
		ts->show_sign = false;
	if (ts->left_align == false)
	{
		print_width(ts, &form);
		if (form.sign != 0 && ts->prepend_zero == false)
			ft_putchar_fd(form.sign, *ts->fd);
		print_character(ts, '0', form.zrs);
		ft_fputstr_fd(form.print, *ts->fd);
	}
	else
	{
		if (form.sign != 0)
			ft_putchar_fd(form.sign, *ts->fd);
		print_character(ts, '0', form.zrs);
		ft_fputstr_fd(form.print, *ts->fd);
		print_character(ts, ' ', form.spaces);
	}
	*ts->ret = *ts->ret + form.lgth;
}
