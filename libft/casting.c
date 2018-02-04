/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:55:33 by egreen            #+#    #+#             */
/*   Updated: 2017/12/03 09:50:11 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	unsigned_casting(t_print *ptr, t_spec *ts)
{
	if (ts->lgth[0] == '\0')
		ts->data.super_u = va_arg(ptr->arg, unsigned int);
	else if (ts->lgth[0] == 'h' && ts->lgth[1] == 'h')
		ts->data.super_u = (unsigned char)va_arg(ptr->arg, unsigned int);
	else if (ts->lgth[0] == 'h')
		ts->data.super_u = (unsigned short)va_arg(ptr->arg, unsigned int);
	else if (ts->lgth[0] == 'l' && ts->lgth[1] == 'l')
		ts->data.super_u = va_arg(ptr->arg, unsigned long long int);
	else if (ts->lgth[0] == 'l')
		ts->data.super_u = va_arg(ptr->arg, unsigned long int);
	else if (ts->lgth[0] == 'j')
		ts->data.super_u = va_arg(ptr->arg, uintmax_t);
	else if (ts->lgth[0] == 'z')
		ts->data.super_u = va_arg(ptr->arg, size_t);
}

void	casting(t_print *ptr, t_spec *ts)
{
	if (ts->type == 'U' || ts->type == 'D')
		ts->data.super = va_arg(ptr->arg, long int);
	else if (ts->lgth[0] == '*')
		ts->width = va_arg(ptr->arg, int);
	else if (ts->lgth[0] == '\0')
		ts->data.super = va_arg(ptr->arg, int);
	else if (ts->lgth[0] == 'h' && ts->lgth[1] == 'h')
		ts->data.super = (char)va_arg(ptr->arg, int);
	else if (ts->lgth[0] == 'h')
		ts->data.super = (short int)va_arg(ptr->arg, int);
	else if (ts->lgth[0] == 'l' && ts->lgth[1] == 'l')
		ts->data.super = va_arg(ptr->arg, long long int);
	else if (ts->lgth[0] == 'l')
		ts->data.super = va_arg(ptr->arg, long int);
	else if (ts->lgth[0] == 'j')
		ts->data.super = va_arg(ptr->arg, intmax_t);
	else if (ts->lgth[0] == 'z')
		ts->data.super = va_arg(ptr->arg, size_t);
}
