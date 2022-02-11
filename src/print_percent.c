/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:05:23 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/01 18:06:58 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*ft_print_percent(t_printf *data)
{
	if (data->zero_flag == 1 && data->precision == -1 && data->minus_flag == 0)
	{
		data->precision = data->width;
		data->width = 0;
	}
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - 1, 1);
	if (data->zero_flag == 1)
		ft_display(data, '0', data->precision - 1, 1);
	write(1, "%", 1);
	data->length++;
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - 1, 1);
	return (data);
}
