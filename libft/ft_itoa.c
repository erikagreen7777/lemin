/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:30:52 by egreen            #+#    #+#             */
/*   Updated: 2017/10/06 09:09:06 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int			len;
	long		n_cpy;

	len = 0;
	n_cpy = (long)n;
	if (n_cpy <= 0)
	{
		len++;
		n_cpy = -n_cpy;
	}
	while (n_cpy != 0)
	{
		len++;
		n_cpy /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	long	n_cpy;
	char	*str;

	len = ft_digits(n);
	n_cpy = (long)n;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n_cpy < 0)
	{
		str[0] = '-';
		n_cpy = -n_cpy;
	}
	str[len--] = (n_cpy % 10) + '0';
	while (n_cpy >= 10)
	{
		n_cpy /= 10;
		str[len--] = (n_cpy % 10) + '0';
	}
	return (str);
}
