/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:05:47 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/05 16:44:19 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_get_length(long int number)
{
	int	length;

	if (number < 0)
		number *= -1;
	length = 1;
	number /= 10;
	while (number > 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

static long int	get_length(t_printf *data)
{
	long int	num;

	if (ft_strcmp(data->length_flag, "hh") == 0)
		num = (unsigned char)(va_arg(data->args, unsigned int));
	else if (ft_strcmp(data->length_flag, "l") == 0)
		num = (unsigned long)(va_arg(data->args, unsigned long int));
	else if (ft_strcmp(data->length_flag, "h") == 0)
		num = (unsigned short)(va_arg(data->args, unsigned int));
	else if (ft_strcmp(data->length_flag, "ll") == 0)
		num = (unsigned long long)(va_arg(data->args, unsigned long long int));
	else
		num = (unsigned int)va_arg(data->args, unsigned int);
	return (num);
}

t_printf	*ft_auxi(t_printf *data, int spaces)
{
	if (data->width < spaces)
		data->length += spaces;
	else
		data->length += data->width;
	return (data);
}

t_printf	*ft_print_unsigned(t_printf *data)
{
	long int	num;
	int			length;
	int			spaces;

	num = get_length(data);
	length = ft_get_length(num);
	if (num == 0 && data->precision == 0)
	{
		ft_display(data, ' ', data->width, 1);
		return (data);
	}
	if (data->zero_flag == 1 && data->precision == -1 && data->minus_flag == 0)
		data->precision = data->width;
	spaces = length;
	if (spaces <= data->precision)
		spaces = data->precision;
	ft_auxi(data, spaces);
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces, 0);
	ft_display(data, '0', data->precision - length, 0);
	ft_putnbrlong_fd(num, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - spaces, 0);
	return (data);
}
