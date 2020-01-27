/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:58:54 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/27 18:11:05 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *t;

	if (!s)
		return (NULL);
	if (!(t = ft_strnew(len)))
		return (NULL);
	t = ft_strncpy(t, s + start, len);
	return (t);
}
