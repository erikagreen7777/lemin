/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:55:42 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:24:37 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		hex_print(t_spec *ts, char print, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(print, *ts->fd);
		*ts->ret = *ts->ret + 1;
		times--;
	}
}

static void	constructor(t_spec *ts, t_format *form)
{
	if (ts->type == 'x')
		form->print = ft_ptf_itoabase(ts->data.super_u, 16, 0);
	else
		form->print = ft_ptf_itoabase(ts->data.super_u, 16, 1);
	form->lgth = ft_strlen(form->print);
	form->zrs = 0;
	form->spaces = 0;
	if (ts->prec > form->lgth)
		form->zrs += ts->prec - form->lgth;
	if (ts->aform == true)
		form->lgth += 2;
	if (ts->width > form->lgth + form->zrs)
		form->spaces = ts->width - (form->lgth + form->zrs);
	if ((ts->prepend_zero == true) && (ts->left_align == false))
		form->zrs = (ts->width - form->lgth);
}

static void	format_hex_helper(t_print *ptr, t_spec *ts)
{
	if (ts->prec == 0)
	{
		ts->data.super_u = 0;
		*ts->ret = ptr->ret;
	}
	else
	{
		ft_putchar_fd('0', *ts->fd);
		*ts->ret = ptr->strlen;
	}
}

void		format_hex(t_print *ptr, t_spec *ts)
{
	t_format form;

	unsigned_casting(ptr, ts);
	constructor(ts, &form);
	ptr->strlen = ft_strlen(form.print);
	if ((ts->data.super_u == 0) && (ts->width == 0))
		format_hex_helper(ptr, ts);
	else if ((ts->data.super_u == 0) && (ts->width > 0))
	{
		if (form.spaces > 0)
			hex_print(ts, ' ', form.spaces + ptr->strlen);
		*ts->ret = *ts->ret + form.lgth - ptr->strlen;
	}
	else if (ts->left_align == true)
		hex_helper(&form, ts);
	else if (ts->left_align == false)
		hex_helper2(&form, ts);
}
