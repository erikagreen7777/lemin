/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:30:01 by egreen            #+#    #+#             */
/*   Updated: 2017/10/06 09:30:04 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	if (c == '\r' || c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int		sign;
	int		number;
	char	*cstr;

	number = 0;
	cstr = (char *)str;
	while (ft_whitespace(*cstr))
		cstr++;
	sign = (*cstr == '-') ? -1 : 1;
	cstr = (*cstr == '+' || *cstr == '-') ? cstr + 1 : cstr;
	while (*cstr >= '0' && *cstr <= '9')
	{
		number = number * 10 + *cstr - 48;
		cstr++;
	}
	number *= sign;
	return (number);
}
