/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:55:05 by gdrion            #+#    #+#             */
/*   Updated: 2018/10/25 17:53:59 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int					ft_count_digit(int n)
{
	int				c;

	c = 1;
	while (n /= 10)
		c++;
	return (c);
}

char				*ft_itoa(int n)
{
	int				digits;
	unsigned int	temp;
	char			*t;

	digits = ft_count_digit(n);
	temp = n;
	if (n < 0)
	{
		temp = -n;
		digits++;
	}
	if (!(t = (char *)malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	t[digits] = '\0';
	if (n < 0)
		t[0] = '-';
	t[--digits] = temp % 10 + 48;
	while (temp /= 10)
		t[--digits] = temp % 10 + 48;
	return (t);
}
