/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 06:45:10 by egreen            #+#    #+#             */
/*   Updated: 2017/10/02 10:52:25 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	if (ft_strlen(s1) - ft_strlen(s2) != 0)
		return (ft_strlen(s1) - ft_strlen(s2));
	else
	{
		while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
			i++;
		return (s1[i] - s2[i]);
	}
}
