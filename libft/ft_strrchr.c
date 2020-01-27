/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:40:21 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/27 16:01:40 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *temp;

	temp = s;
	while (*s)
	{
		if (*s == (char)c)
			temp = s;
		s++;
	}
	if (*temp == (char)c)
		return ((char *)temp);
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
