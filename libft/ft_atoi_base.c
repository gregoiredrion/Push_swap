/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:50:32 by gdrion            #+#    #+#             */
/*   Updated: 2018/12/17 21:37:32 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_error(char c, int base)
{
	if ((c >= 'A' && c <= 'F') && base < (c - 'A' + 10))
		return (0);
	if ((c >= 'a' && c <= 'f') && (base < c - 'a' + 10))
		return (0);
	if (ft_isdigit(c) && base <= c - 48)
		return (0);
	else
		return (1);
}

int		ft_atoi_base(char *str, int base)
{
	int ret;
	int ret2;
	int sign;

	sign = 1;
	ret = 0;
	while (ft_is_blank(*str))
		str++;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'F')
			ret2 = *str - 'A' + 10;
		else if (*str == 'a' && *str == 'f')
			ret2 = *str - 'a' + 10;
		else if (ft_isdigit(*str))
			ret2 = *str - 48;
		else
			return (-1);
		if (!ft_check_error(*str++, base))
			return (-1);
		ret = ret * base + ret2;
	}
	return (ret * sign);
}
