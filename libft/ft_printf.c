/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:56:34 by egreen            #+#    #+#             */
/*   Updated: 2017/11/27 12:56:35 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *format, ...)
{
	t_print all;

	all.ret = 0;
	all.fd = 1;
	all.format = (char*)format;
	va_start(all.arg, format);
	parse(&all);
	va_end(all.arg);
	return (all.ret);
}
