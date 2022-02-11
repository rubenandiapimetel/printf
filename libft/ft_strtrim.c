/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:03:12 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/02 19:19:26 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *s)
{
	int	len;
	int	it;

	it = 0;
	len = ft_strlen(s);
	while (it < len)
	{
		if (s[it] == c)
			return (1);
		it++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	k;
	size_t	len;
	size_t	i;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	k = 0;
	len = ft_strlen(s1);
	while (ft_inset(s1[i], set))
		i++;
	while (len > 0 && ft_inset(s1[len - 1], set))
		len--;
	if (len < i)
		len = i;
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[k++] = s1[i++];
	}
	str[k] = '\0';
	return (str);
}
