/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:05:15 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/04 16:40:23 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_nbrlen(long int number, int base)
{
	int	length;

	length = 1;
	number /= base;
	while (number > 0)
	{
		number /= base;
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

static char	*ft_itoa_base(long int number, int base, char c)
{
	char	*str;
	int		length;
	char	*base_string_minus;
	char	*base_string_mayus;
	char	*base_selected;

	base_string_minus = "0123456789abcdef";
	base_string_mayus = "0123456789ABCDEF";
	if (number == 0)
		return (ft_strdup("0"));
	length = ft_nbrlen(number, base);
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	str[length] = '\0';
	base_selected = base_string_mayus;
	if (c == 'x')
		base_selected = base_string_minus;
	while (number)
	{
		str[--length] = base_selected[number % base];
		number /= base;
	}
	return (str);
}

static	t_printf	*print(t_printf *data, char *str)
{
	int	width;
	int	spaces;

	width = ft_strlen(str);
	spaces = width;
	if (data->precision > 0 && data->precision >= width)
		spaces = data->precision;
	if (data->width < spaces)
		data->length += spaces;
	else
		data->length += data->width;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces, 0);
	ft_display(data, '0', data->precision - width, 0);
	ft_putstr_fd(str, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - spaces, 0);
	return (data);
}

t_printf	*ft_print_hexadecimal(t_printf *data, char c)
{
	char		*str;
	long int	num;

	num = get_length(data);
	if (data->zero_flag == 1 && data->precision == -1 && data->minus_flag == 0)
		data->precision = data->width;
	if (num == 0 && data->precision == 0)
	{
		ft_display(data, ' ', data->width, 1);
		return (data);
	}
	str = ft_itoa_base(num, 16, c);
	if (!str)
		return (NULL);
	print(data, str);
	free(str);
	return (data);
}
