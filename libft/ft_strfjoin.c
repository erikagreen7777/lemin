/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:17:58 by egreen            #+#    #+#             */
/*   Updated: 2017/11/17 12:34:41 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strfjoin(char *s1, char *s2)
{
	size_t		lens;
	char		*str;
	size_t		len1;
	size_t		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	lens = (len1 + len2);
	str = (char *)malloc(sizeof(str) * (lens + 1));
	if (str == 0)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	str[lens + 1] = '\0';
	ft_strdel(&s1);
	return (str);
}
