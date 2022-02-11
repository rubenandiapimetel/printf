/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:01:07 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/01 18:06:58 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*list;

	if (!lst)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	head = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = ft_lstnew(f(lst->content));
		if (!list->next)
		{
			del(list->next);
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (head);
}
