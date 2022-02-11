/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:02:34 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/01 18:06:58 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		it;
	int		it2;

	if (!s1 || !s2)
		return (NULL);
	it = 0;
	it2 = 0;
	s3 = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[it] != '\0')
	{
		s3[it] = s1[it];
		it++;
	}
	while (s2[it2] != '\0')
	{
		s3[it] = s2[it2];
		it++;
		it2++;
	}
	s3[it] = '\0';
	return (s3);
}
