/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:28:41 by egreen            #+#    #+#             */
/*   Updated: 2017/10/01 10:01:30 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	const char	*src2;
	char		*dest2;

	i = 0;
	src2 = src;
	dest2 = dest;
	while (i < n)
	{
		dest2[i] = src2[i];
		if (dest2[i] == (char)c)
			return (&dest2[i + 1]);
		i++;
	}
	return (0);
}
