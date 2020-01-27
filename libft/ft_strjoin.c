/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:43:25 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/27 18:19:33 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	len1 = len1 + len2;
	if (!(t = (char *)malloc(sizeof(char) * (len1 + 1))))
		return (NULL);
	t[len1] = '\0';
	t = ft_strcpy(t, s1);
	t = ft_strcat((char *)t, s2);
	return (t);
}
