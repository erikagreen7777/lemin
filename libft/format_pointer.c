/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:56:07 by egreen            #+#    #+#             */
/*   Updated: 2017/11/27 12:56:09 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		format_pointer(t_print *ptr, t_spec *ts)
{
	char *print;

	ts->data.super_u = va_arg(ptr->arg, unsigned long int);
	print = ft_ptf_itoabase(ts->data.super_u, 16, 0);
	ft_fputstr_fd("0x", *ts->fd);
	*ts->ret = *ts->ret + 2;
	ft_fputstr_fd(print, *ts->fd);
	*ts->ret = *ts->ret + ft_strlen(print);
}
