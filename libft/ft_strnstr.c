/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:55:07 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/29 12:58:43 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	const char	*phay;
	const char	*pneedle;
	size_t		temp;

	if (!*needle)
		return ((char *)hay);
	while (len && *hay)
	{
		phay = hay;
		pneedle = needle;
		temp = len;
		while (*phay == *pneedle && temp--)
		{
			if (!*pneedle)
				return ((char *)hay);
			phay++;
			pneedle++;
		}
		if (!*pneedle)
			return ((char *)hay);
		hay++;
		len--;
	}
	return (NULL);
}
