/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:21:40 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/25 19:53:22 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*p;
	const char	*p2;

	p = s1;
	p2 = s2;
	while (n-- > 0)
	{
		if (*p != *p2)
			return ((unsigned char)*p - (unsigned char)*p2);
		p++;
		p2++;
	}
	return (0);
}
