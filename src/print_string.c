/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:05:43 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/05 16:42:38 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_calculate(t_printf *data, char *s)
{
	char	*cpy;

	if (data->precision > -1 && s)
	{
		cpy = ft_strdup("");
		ft_strlcpy(cpy, s, data->precision + 1);
		return (cpy);
	}
	else if (data->precision == -1 && s)
		return (ft_strdup(s));
	else if (data->precision == -1 && !s)
		return (ft_strdup("(null)"));
	else if (data->precision > -1 && !s)
	{
		cpy = ft_strdup("(null)");
		s = cpy;
		ft_strlcpy(cpy, s, data->precision + 1);
		return (cpy);
	}
	return (s);
}

t_printf	*ft_print_string(t_printf *data)
{
	char	*s;
	int		len;

	s = va_arg(data->args, char *);
	s = ft_calculate(data, s);
	len = ft_strlen(s);
	data->length += len;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - len, 1);
	ft_putstr_fd(s, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - len, 1);
	free(s);
	return (data);
}
