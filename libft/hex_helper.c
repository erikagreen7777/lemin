/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:09:26 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:09:48 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	hex_helper(t_format *form, t_spec *ts)
{
	if ((ts->aform == true) && (ts->data.super_u > 0))
	{
		if (ts->type == 'X')
			ft_fputstr_fd("0X", *ts->fd);
		else
			ft_fputstr_fd("0x", *ts->fd);
	}
	hex_print(ts, '0', form->zrs);
	ft_fputstr_fd(form->print, *ts->fd);
	if (form->spaces > 0)
		hex_print(ts, ' ', form->spaces);
	*ts->ret = *ts->ret + form->lgth;
}

void	hex_helper2(t_format *form, t_spec *ts)
{
	if ((form->zrs > 0) && (ts->aform == false))
		hex_print(ts, '0', form->zrs);
	else if (form->zrs <= 0)
		hex_print(ts, ' ', form->spaces);
	if ((ts->aform == true) && (ts->data.super_u > 0))
	{
		if (ts->type == 'X')
			ft_fputstr_fd("0X", *ts->fd);
		else
			ft_fputstr_fd("0x", *ts->fd);
		hex_print(ts, '0', form->zrs);
	}
	ft_fputstr_fd(form->print, *ts->fd);
	*ts->ret = *ts->ret + form->lgth;
}
