/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:46:53 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/27 16:07:42 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *dest;
	const char *src;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		dest = haystack;
		src = needle;
		while (*src != '\0' && *src == *dest)
		{
			dest++;
			src++;
			if (*src == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
