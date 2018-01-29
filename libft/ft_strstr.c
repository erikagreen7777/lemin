/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:35:34 by egreen            #+#    #+#             */
/*   Updated: 2017/10/01 17:45:25 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	if (!s2[i])
		return ((char*)s1);
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			n = i;
			j = 0;
			while (s2[j] && s1[n] == s2[j])
			{
				n++;
				j++;
			}
			if (!s2[j])
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
