/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:55:37 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/01 17:56:55 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*it;
	t_list	*tmp;

	tmp = NULL;
	it = *lst;
	while (it)
	{
		tmp = it->next;
		del(it->content);
		free(it);
		it = tmp;
	}
	*lst = NULL;
}
