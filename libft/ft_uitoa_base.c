/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:59:27 by gdrion            #+#    #+#             */
/*   Updated: 2018/12/05 17:42:09 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_uitoa_base2(uintmax_t nb, int base, int i)
{
	char		*converted;

	if (!(converted = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	converted[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (nb % base <= 9)
			converted[i] = nb % base + 48;
		else
			converted[i] = 'a' - 10 + (nb % base);
		nb = (nb - (nb % base)) / base;
		i--;
	}
	return (converted);
}

char			*ft_uitoa_base(uintmax_t nb, int base)
{
	uintmax_t	save;
	int			i;

	i = 0;
	save = nb;
	if (save == 0)
		i++;
	while (save > 0)
	{
		save = (save - (save % base)) / base;
		i++;
	}
	return (ft_uitoa_base2(nb, base, i));
}
