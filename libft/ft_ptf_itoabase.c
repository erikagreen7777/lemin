/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_itoabase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:56:42 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:19:30 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_ptf_itoabase(uintmax_t val, int base, int opt)
{
	static char	buf[32] = "0";
	char		*set;
	int			i;
	int			h;

	set = HEXVALUE;
	i = 30;
	h = 0;
	if (opt != 0)
		h = 16;
	if (val == 0)
		return (ft_strcpy(buf, "0\0"));
	while (val > 0 && i > 0)
	{
		buf[i] = set[(val % base) + h];
		val = val / base;
		--i;
	}
	return (buf + i + 1);
}
