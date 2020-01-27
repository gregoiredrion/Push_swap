/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:14:30 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/17 14:29:54 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *p;

	p = s;
	while (n-- > 0)
	{
		if (*p == (unsigned char)c)
			return ((void*)s);
		p++;
		s++;
	}
	return (NULL);
}
