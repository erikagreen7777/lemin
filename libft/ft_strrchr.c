/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:08:45 by egreen            #+#    #+#             */
/*   Updated: 2017/09/30 13:51:50 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	see;
	int		len;

	str = (char *)s;
	see = (char)c;
	len = ft_strlen(str);
	while ((len != 0) && str[len] != see)
		len--;
	if (str[len] == see)
		return (&str[len]);
	return (NULL);
}
