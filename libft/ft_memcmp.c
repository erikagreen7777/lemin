/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 07:27:52 by egreen            #+#    #+#             */
/*   Updated: 2017/10/01 12:25:30 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1c;
	unsigned char	*str2c;

	i = 0;
	str1c = (unsigned char *)str1;
	str2c = (unsigned char *)str2;
	while (i < n)
	{
		if (str1c[i] != str2c[i])
			return (str1c[i] - str2c[i]);
		i++;
	}
	return (0);
}
