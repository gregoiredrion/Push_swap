/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:20:23 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/26 15:31:23 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f) (char))
{
	char	*p;
	int		i;
	int		len;

	i = 0;
	if (f && s)
	{
		len = ft_strlen((char *)s);
		if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s[i])
		{
			p[i] = f(s[i]);
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
