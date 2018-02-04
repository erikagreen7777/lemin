/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:55:49 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 11:42:52 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		pch(t_spec *ts, char c, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(c, *ts->fd);
		*ts->ret = *ts->ret + 1;
		times--;
	}
}

static void		constructor(t_spec *ts, t_format *form)
{
	form->print = ft_ptf_itoabase(ts->data.super_u, 8, 0);
	form->lgth = ft_strlen(form->print);
	form->spaces = 0;
	form->zrs = 0;
	if (ts->aform == true && form->print[0] != '0')
		form->zrs++;
	if (ts->left_align == true)
	{
		if (ts->prec > form->lgth + form->zrs)
			form->zrs = ts->prec - form->lgth;
		form->spaces = ts->width - (form->zrs + form->lgth);
	}
	else
	{
		if (ts->prec > form->lgth + form->zrs)
			form->zrs = ts->prec - form->lgth;
		if (ts->prepend_zero == true)
			form->zrs += ts->width - (form->zrs + form->lgth);
		else
			form->spaces = ts->width - (form->zrs + form->lgth);
	}
}

static void		format_octal_helper(t_format *form, t_spec *ts)
{
	pch(ts, '0', form->zrs);
	ft_fputstr_fd(form->print, *ts->fd);
	pch(ts, ' ', form->spaces);
	*ts->ret = *ts->ret + form->lgth;
}

void			format_octal(t_print *ptr, t_spec *ts)
{
	t_format	form;

	unsigned_casting(ptr, ts);
	constructor(ts, &form);
	if (ts->left_align)
		format_octal_helper(&form, ts);
	else
	{
		pch(ts, ' ', form.spaces);
		((ts->prec == 0) && (ts->aform == false) && \
			(ts->width == 0)) ? form.print = " " : pch(ts, '0', form.zrs);
		if ((ts->prec == 0) && (ts->aform == false) && (ts->width == 0))
			form.lgth = 0;
		else
		{
			if ((ts->width > 0) && (ts->data.super_u == 0) && (ts->prec == 0))
				form.print = " ";
			ft_fputstr_fd(form.print, *ts->fd);
		}
		*ts->ret = *ts->ret + form.lgth;
	}
}
