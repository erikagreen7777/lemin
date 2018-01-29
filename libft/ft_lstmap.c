/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:30:35 by egreen            #+#    #+#             */
/*   Updated: 2017/10/05 16:53:34 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*trav;

	if (!lst)
		return (NULL);
	trav = f(lst);
	ret = trav;
	while (lst->next)
	{
		lst = lst->next;
		trav->next = f(lst);
		if (!trav->next)
		{
			free(trav->next);
			return (NULL);
		}
		trav = trav->next;
	}
	return (ret);
}
