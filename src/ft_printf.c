/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:05:07 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/02 19:28:42 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_initialize(t_printf *data)
{
	data->zero_flag = 0;
	data->hast_flag = 0;
	data->plus_flag = 0;
	data->minus_flag = 0;
	data->space_flag = 0;
	data->asterisk_flag = 0;
	data->width = 0;
	data->length = 0;
	data->precision_flag = 0;
	data->it = 0;
	data->copy = (char *)data->format;
	data->treat = (char *)data->format;
}

void	ft_clear(t_printf *data)
{
	data->width = 0;
	data->precision = -1;
	data->length_flag[0] = '\0';
	data->length_flag[1] = '\0';
}

int	procesate(t_printf *data)
{
	data->it++;
	check_flags(data);
	check_width(data);
	check_precision(data);
	check_length(data);
	handle_flags(data);
	return (data->length);
}

int	parse(t_printf *data)
{
	if (ft_strcmp(data->copy, "%") == 0)
		return (0);
	while (data->copy[data->it] != '\0')
	{
		if (data->copy[data->it] == '%')
		{
			ft_clear(data);
			procesate(data);
		}
		else
		{
			ft_putchar_fd(data->copy[data->it], 1);
			data->length++;
		}
		data->it++;
	}
	return (data->length);
}

int	ft_printf(const char *format, ...)
{
	t_printf	*data;

	data = malloc(sizeof(t_printf));
	if (!data)
		return (0);
	data->format = format;
	ft_initialize(data);
	if (format)
	{
		va_start(data->args, format);
		data->length = parse(data);
		va_end(data->args);
	}
	free(data);
	return (data->length);
}
