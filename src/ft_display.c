/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:05:03 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/07 18:09:43 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_display(t_printf *data, char c, int width, int update)
{
	if (width > 0)
	{
		if (update)
			data->length += width;
		while (width-- > 0)
			write(1, &c, 1);
	}
}

t_printf	*ft_partwo(t_printf *data, int spaces, char *str)
{
	ft_putstr_fd("0x", 1);
	ft_display(data, '0', (data->precision - spaces) + 2, 1);
	ft_putstr_fd(str, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - spaces, 0);
	free(str);
	return (data);
}
