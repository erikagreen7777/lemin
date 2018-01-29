/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 07:09:27 by egreen            #+#    #+#             */
/*   Updated: 2017/10/01 12:13:40 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char*)str;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (str2[i] == c2)
			return (&str2[i]);
		i++;
	}
	return (NULL);
}
