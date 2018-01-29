/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:25:29 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:26:47 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_width(t_spec *ts, t_format *form)
{
	if (ts->prepend_zero == true)
	{
		if (form->sign != 0)
			ft_putchar_fd(form->sign, *ts->fd);
		d_print_char(ts, '0', form->spaces);
	}
	else
		d_print_char(ts, ' ', form->spaces);
}

void		d_print_char(t_spec *ts, char c, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(c, *ts->fd);
		times--;
		*ts->ret = *ts->ret + 1;
	}
}

void		form_dec_helper(t_format *form, t_spec *ts)
{
	print_width(ts, form);
	if (form->sign != 0 && ts->prepend_zero == false)
		ft_putchar_fd(form->sign, *ts->fd);
	if ((ts->prec == 0) && (ts->aform == false) && \
		(ts->width == 0) && (ts->data.super == 0))
	{
		form->print = " ";
		form->lgth = 0;
	}
	else
	{
		if ((ts->width > 0) && (ts->data.super == 0) && (ts->prec == 0))
			form->print = " ";
		else
			d_print_char(ts, '0', form->zrs);
		ft_fputstr_fd(form->print, *ts->fd);
	}
}
