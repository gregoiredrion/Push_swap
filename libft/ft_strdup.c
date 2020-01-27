/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:30:49 by gdrion            #+#    #+#             */
/*   Updated: 2018/07/03 12:40:33 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	int		length;
	char	*dest;

	length = ft_strlen((char *)str);
	if (!(dest = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (length >= 0)
	{
		dest[length] = str[length];
		length--;
	}
	return (dest);
}
