/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_del_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:00:05 by gdrion            #+#    #+#             */
/*   Updated: 2019/06/04 18:15:58 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		do_and_add(char *op, t_hold *h)
{
	char	*new;
	int		len;

	len = ft_strlen(h->com) + ft_strlen(op) + 1;
	if (!(new = ft_strnew(len)))
		return (0);
	h->index = len;
	if (h->com)
		ft_strcpy(new, h->com);
	ft_strcat(new, op);
	ft_strcat(new, "\n");
	ft_strdel(&(h->com));
	h->com = new;
	if (!(do_ops(op, h)))
		return (0);
	return (1);
}

void	del_command(t_hold *h)
{
	int		j;
	char	*t;
	int		len;

	j = 2;
	len = ft_strlen(h->com);
	if (!h->com)
		return ;
	t = h->com + h->index - 1;
	while (j > 0 && *t)
	{
		if (*t == '\n')
			j--;
		len--;
		if (j == 0)
			return ;
		*t = '\0';
		if (!len)
			return ;
		t--;
		h->index--;
	}
}
