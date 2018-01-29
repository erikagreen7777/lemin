/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:52:49 by egreen            #+#    #+#             */
/*   Updated: 2017/10/06 09:10:12 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_indexfinder(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s)
	{
		if (*s != c)
		{
			++count;
			s = ft_strchr(s, c);
		}
		else
			++s;
	}
	return (count);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	curr;
	size_t	wrdct;
	char	**words;
	char	*next;

	wrdct = ft_indexfinder(s, c);
	words = (char **)ft_memalloc(sizeof(char*) * (wrdct + 1));
	if (!words)
		return (NULL);
	curr = 0;
	while (curr < wrdct)
	{
		while (*s == c)
			++s;
		next = ft_strchr(s, c);
		if (next)
			words[curr] = ft_strsub(s, 0, next - s);
		else
			words[curr] = ft_strdup(s);
		s = next;
		++curr;
	}
	return (words);
}
