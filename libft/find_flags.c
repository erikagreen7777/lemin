/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:56:50 by egreen            #+#    #+#             */
/*   Updated: 2017/12/03 09:51:40 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	lgth(t_spec *ts, char *format)
{
	int c;

	c = 0;
	if (format[c] == 'h' && format[c + 1] == 'h' && (c = c + 2))
		ft_strcpy(ts->lgth, "hh\0");
	else if (format[c] == 'h' && (c = c + 1))
		ft_strcpy(ts->lgth, "h\0");
	else if (format[c] == 'l' && format[c + 1] == 's')
	{
		ts->type = 'S';
		return (c + 1);
	}
	else if (format[c] == 'l' && format[c + 1] == 'l' && (c = c + 2))
		ft_strcpy(ts->lgth, "ll\0");
	else if (format[c] == 'l' && (c = c + 1))
		ft_strcpy(ts->lgth, "l\0");
	else if (format[c] == 'z' && (c = c + 1))
		ft_strcpy(ts->lgth, "z\0");
	else if (format[c] == 'j' && (c = c + 1))
		ft_strcpy(ts->lgth, "j\0");
	else if (format[c] == '*' && (c += 1))
		ft_strcpy(ts->lgth, "*\0");
	return (c - 1);
}

static int	width(t_spec *ts, char *format)
{
	int x;

	x = 0;
	ts->width = ft_atoi(format);
	while (ft_isdigit(format[x]))
		x++;
	return (x - 1);
}

static int	prec(t_spec *ts, char *format)
{
	int x;

	x = 0;
	if (ft_isdigit(format[x]))
	{
		ts->prec = ft_atoi(format);
		while (ft_isdigit(format[x]))
			x++;
	}
	else
		ts->prec = 0;
	return (x);
}

static int	specifier(t_spec *ts, char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'c' || c == '%' || c == 'u'
		|| c == 'n' || c == 'o' || c == 'e' || c == 'e' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'G' || c == 'g' || c == 'S' || c == 'D' || c == 'C'
		|| c == 'O' || c == 'U')
	{
		ts->type = c;
		return (1);
	}
	return (0);
}

int			find_flags(t_spec *ts, char *format, int *x)
{
	while (format[++*x] && !(specifier(ts, format[*x])))
	{
		if (ft_isflag(format[*x]))
			*x += flags(ts, format + *x);
		else if (format[*x] == '.')
			*x += prec(ts, format + *x + 1);
		else if (ft_isdigit(format[*x]))
			*x += width(ts, format + *x);
		else if (ft_islgth(format[*x]))
			*x += lgth(ts, format + *x);
	}
	return (0);
}
