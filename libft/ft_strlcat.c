/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:02:38 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/01 18:06:58 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	cont;

	len = 0;
	cont = 0;
	while (dst[cont] && cont < dstsize)
		cont++;
	len = cont;
	while (src[cont - len] && cont + 1 < dstsize)
	{
		dst[cont] = src[cont - len];
		cont++;
	}
	if (len < dstsize)
		dst[cont] = '\0';
	return (len + ft_strlen(src));
}
