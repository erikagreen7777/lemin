/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:06:20 by egreen            #+#    #+#             */
/*   Updated: 2017/12/03 09:53:05 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isflag(char test)
{
	if (test == '#' || test == '-' || test == '+' ||
			test == '0' || test == ' ')
		return (1);
	return (0);
}

int		ft_islgth(char c)
{
	if (c == 'h' || c == 'l' || c == 'z' || c == 'j' || c == '*')
		return (1);
	return (0);
}

int		flags(t_spec *ts, char *format)
{
	int	x;

	x = -1;
	while (ft_isflag(format[++x]))
	{
		if (format[x] == '#')
			ts->aform = true;
		else if (format[x] == ' ')
			ts->prepend_space = true;
		else if (format[x] == '0')
			ts->prepend_zero = true;
		else if (format[x] == '+')
			ts->show_sign = true;
		else if (format[x] == '-')
			ts->left_align = true;
	}
	return (x - 1);
}
