/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:12:34 by egreen            #+#    #+#             */
/*   Updated: 2017/10/02 09:14:07 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		srclen;
	size_t		dstlen;
	char		*temp;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen < size)
	{
		temp = dst + dstlen;
		ft_memset(temp, 0, size - dstlen);
		ft_memcpy(temp, src, size - dstlen - 1);
		return (dstlen + srclen);
	}
	return (size + srclen);
}
