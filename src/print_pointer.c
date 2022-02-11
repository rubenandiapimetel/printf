/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:05:39 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/07 18:16:26 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_length_number(unsigned long number, int base)
{
	int	lenght;

	lenght = 1;
	number /= base;
	while (number > 0)
	{
		number /= base;
		lenght++;
	}
	return (lenght);
}

static char	*ft_itoa_base(unsigned long number, int base)
{
	char	*str;
	int		length;
	char	*base_string;

	base_string = "0123456789abcdef";
	if (number == 0)
		return (ft_strdup("0"));
	length = ft_length_number(number, base);
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	str[length] = '\0';
	while (number)
	{
		str[--length] = base_string[number % base];
		number /= base;
	}
	return (str);
}

t_printf	*ft_aux(t_printf *data, int spaces)
{
	if (data->width < spaces)
		data->length += spaces;
	else
		data->length += data->width;
	return (data);
}

t_printf	*ft_print_pointer(t_printf *data)
{
	unsigned long	num;
	char			*str;
	int				spaces;

	num = (unsigned long int)va_arg(data->args, unsigned long int);
	str = ft_itoa_base(num, 16);
	if (!str)
		return (NULL);
	if (num == 0 && data->precision == 0)
		*str = '\0';
	if (data->zero_flag == 1 && data->precision == 1 && data->minus_flag == 0)
	{
		data->precision = data->width - 2;
		data->width = 0;
	}
	spaces = ft_strlen(str) + 2;
	ft_aux(data, spaces);
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces, 0);
	ft_partwo(data, spaces, str);
	return (data);
}
