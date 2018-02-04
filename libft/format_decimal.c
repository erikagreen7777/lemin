/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:55:32 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:05:30 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	get_sign(t_spec *ts, t_format *form)
{
	if (ts->data.super < 0)
	{
		form->sign = '-';
		ts->data.super *= -1;
	}
	else if (ts->show_sign == true)
	{
		form->sign = '+';
		form->lgth++;
	}
}

static void	constructor(t_spec *ts, t_format *form)
{
	form->sign = 0;
	get_sign(ts, form);
	form->print = ft_ptf_itoabase((uintmax_t)ts->data.super, 10, 0);
	form->lgth = ft_strlen(form->print);
	if ((ts->prec > 0) && (ts->prepend_zero == true) && (ts->width > ts->prec))
	{
		ts->prepend_zero = false;
		ts->prepend_space = 1;
	}
	form->zrs = 0;
	if ((ts->prepend_space == true) && (ts->show_sign == false) && \
		(form->sign != '-') && (ts->prec <= 0) && (ts->width == 0))
		form->spaces = 1;
	else
		form->spaces = 0;
	if (ts->prec > form->lgth)
		form->zrs += ts->prec - form->lgth;
	if ((ts->prec > ts->width) && (ts->prepend_space == true))
		form->spaces = 1;
	if (form->sign != 0)
		form->lgth++;
	if (ts->width > form->lgth + form->zrs)
		form->spaces += ts->width - (form->lgth + form->zrs);
}

void		format_decimal(t_print *ptr, t_spec *ts)
{
	t_format form;

	casting(ptr, ts);
	constructor(ts, &form);
	if (ts->left_align == false)
		form_dec_helper(&form, ts);
	else
	{
		if (form.sign != 0)
			ft_putchar_fd(form.sign, *ts->fd);
		d_print_char(ts, '0', form.zrs);
		ft_fputstr_fd(form.print, *ts->fd);
		d_print_char(ts, ' ', form.spaces);
	}
	*ts->ret = *ts->ret + form.lgth;
}
