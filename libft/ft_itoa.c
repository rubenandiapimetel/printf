/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:55:10 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/02 19:14:38 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len += 1;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		it;

	size = ft_nbrlen(n);
	it = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		it++;
	}
	while (it < size--)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
