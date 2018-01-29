/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_wstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:12:46 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:16:17 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		format_wstring(t_print *ptr, t_spec *ts)
{
	size_t	i;

	i = 0;
	ts->data.bigs = va_arg(ptr->arg, wchar_t *);
	if (ts->data.bigs == NULL)
		ts->len = 0;
	else
	{
		while (ts->data.bigs[i])
			i++;
		ts->len = i;
		i = 0;
	}
	while (ts->data.bigs[i])
	{
		ft_putchar(ts->data.bigs[i]);
		i++;
	}
	ptr->wstr = true;
}
