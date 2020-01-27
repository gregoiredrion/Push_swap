/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:15:38 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/28 18:18:02 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		a;
	char		*t;

	if (!s)
		return (NULL);
	a = 0;
	i = 0;
	j = ft_strlen((char *)s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n')
		j--;
	if (i == ft_strlen((char *)s))
		return (ft_strdup(""));
	if (!(t = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	t[j - i] = '\0';
	while (i < j)
		t[a++] = s[i++];
	return (t);
}
