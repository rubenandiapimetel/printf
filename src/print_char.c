/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:05:11 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/05 17:29:27 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*ft_print_char(t_printf *data)
{
	char	c;

	c = (char)va_arg(data->args, int);
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - 1, 1);
	write(1, &c, 1);
	data->length++;
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - 1, 1);
	return (data);
}
