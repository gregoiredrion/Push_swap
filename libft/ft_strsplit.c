/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:38:41 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/28 18:19:50 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int word;

	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c && *s)
		{
			while (*s && *s != c)
				s++;
			word++;
		}
	}
	return (c);
}

char		**ft_strsplit(const char *s, char c)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	start;
	char			**t;

	if (!s || !c)
		return (NULL);
	i = 0;
	j = 0;
	if (!(t = malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			t[j++] = ft_strsub(s, start, i - start);
		}
	}
	t[j] = 0;
	return (t);
}
