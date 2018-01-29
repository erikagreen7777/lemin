/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:27:03 by egreen            #+#    #+#             */
/*   Updated: 2017/10/06 09:31:18 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	hold;
	char	*haystack;
	char	*needle;

	i = 0;
	haystack = (char *)big;
	needle = (char *)little;
	if (needle[0] == '\0')
		return (haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		hold = i;
		while (hold < len && haystack[hold++] == needle[j++])
		{
			if (needle[j] == '\0')
				return (&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
