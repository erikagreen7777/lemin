/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:01:13 by egreen            #+#    #+#             */
/*   Updated: 2017/10/05 08:09:42 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*new;

	j = start;
	if (!s)
		return (NULL);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[j];
		i++;
		j++;
	}
	return (new);
}
