/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:02:28 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/01 18:06:58 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	it;
	char	*s2;
	size_t	size;

	it = 0;
	size = ft_strlen(s1);
	s2 = malloc(sizeof(char) * size + 1);
	if (!s2)
		return (0);
	while (it < size)
	{
		s2[it] = s1[it];
		it++;
	}
	s2[it] = '\0';
	return (s2);
}
