/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:51:07 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/07 18:02:09 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_printf
{
	const char	*format;
	char		*copy;
	char		*treat;
	int			it;
	va_list		args;
	int			zero_flag;
	int			hast_flag;
	int			minus_flag;
	int			plus_flag;
	int			space_flag;
	int			asterisk_flag;
	int			precision_flag;
	int			width;
	char		length_flag[2];
	int			length;
	int			precision;
}				t_printf;

t_printf		*ft_partwo(t_printf *data, int spaces, char *str);
int				ft_auneg(long int *num, int *is_negative);
t_printf		*check_flags(t_printf *data);
t_printf		*check_width(t_printf *data);
t_printf		*check_length(t_printf *data);
t_printf		*check_precision(t_printf *data);
void			handle_flags(t_printf *data);
t_printf		*ft_print_integer(t_printf *data);
t_printf		*ft_print_string(t_printf *data);
t_printf		*ft_print_char(t_printf *data);
t_printf		*ft_print_unsigned(t_printf *data);
t_printf		*ft_print_pointer(t_printf *data);
t_printf		*ft_print_hexadecimal(t_printf *data, char c);
t_printf		*ft_print_percent(t_printf *data);
void			ft_display(t_printf *data, char c, int width, int update);

#endif
