/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlong_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:47:03 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/03 15:47:03 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrlong_fd(long int number, int fd)
{
	if (number == -9223372036854775807 - 1)
		write(1, "-9223372036854775808", 20);
	else
	{
		if (number < 0)
		{
			ft_putchar_fd('-', fd);
			number *= -1;
		}
		if (number > 9)
			ft_putnbrlong_fd(number / 10, fd);
		ft_putchar_fd((number % 10) + '0', fd);
	}
}
