/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randia-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:42:05 by randia-p          #+#    #+#             */
/*   Updated: 2021/04/03 16:42:05 by randia-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char	*s1, const char	*s2)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_strncmp(s1, s2, (ft_strlen(s1))));
	return (ft_strncmp(s1, s2, (ft_strlen(s2))));
}
