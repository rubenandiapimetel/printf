/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:05:00 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/02 19:26:00 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*check_flags(t_printf *data)
{
	while (data->format[data->it] == '0'
		|| data->format[data->it] == '+'
		|| data->format[data->it] == '-'
		|| data->format[data->it] == '*'
		|| data->format[data->it] == ' ')
	{
		if (data->format[data->it] == '0' && data->it++)
			data->zero_flag = 1;
		else if (data->format[data->it] == '+' && data->it++)
			data->plus_flag = 1;
		else if (data->format[data->it] == '-' && data->it++)
			data->minus_flag = 1;
		else if (data->format[data->it] == '*' && data->it++)
			data->asterisk_flag = 1;
		else if (data->format[data->it] == '#' && data->it++)
			data->hast_flag = 1;
		else if (data->format[data->it] == '+' && data->it++)
			data->plus_flag = 1;
		else if (data->format[data->it] == ' ' && data->it++)
			data->space_flag = 1;
	}
	return (data);
}

t_printf	*check_width(t_printf *data)
{
	if (data->asterisk_flag == 1)
	{
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->minus_flag = 1;
			data->width *= -1;
		}
		return (data);
	}
	while (ft_isdigit(data->format[data->it]))
	{
		data->width *= 10;
		data->width += (data->treat[data->it] - 48);
		if (data->it == (int)ft_strlen(data->format) - 1)
			break ;
		data->it++;
	}
	return (data);
}

t_printf	*check_precision(t_printf *data)
{
	if (data->format[data->it] == '.')
	{
		data->it++;
		data->precision = 0;
		if (data->format[data->it] == '*')
		{
			data->precision = va_arg(data->args, int);
			data->it++;
			if (data->precision < 0)
				data->precision = -1;
			return (data);
		}
		while (ft_isdigit(data->format[data->it]))
		{
			data->precision *= 10;
			data->precision += (data->format[data->it] - 48);
			data->it++;
		}
	}
	return (data);
}

t_printf	*check_length(t_printf *data)
{
	int	i;

	i = 0;
	while (data->format[data->it] == 'l'
		|| data->format[data->it] == 'h')
	{
		if (data->format[data->it] == 'l' && data->it++)
		{
			data->length_flag[i++] = 'l';
			data->length_flag[i] = '\0';
		}
		else if (data->format[data->it] == 'h' && data->it++)
		{
			data->length_flag[i++] = 'h';
			data->length_flag[i] = '\0';
		}
	}
	return (data);
}

void	handle_flags(t_printf *data)
{
	if (data->format[data->it] == 'c')
		ft_print_char(data);
	else if (data->format[data->it] == 's')
		ft_print_string(data);
	else if (data->format[data->it] == 'd' || data->format[data->it] == 'i')
		ft_print_integer(data);
	else if (data->format[data->it] == 'u')
		ft_print_unsigned(data);
	else if (data->format[data->it] == 'p')
		ft_print_pointer(data);
	else if (data->format[data->it] == 'x')
		ft_print_hexadecimal(data, 'x');
	else if (data->format[data->it] == 'X')
		ft_print_hexadecimal(data, 'X');
	else if (data->format[data->it] == '%')
		ft_print_percent(data);
}
