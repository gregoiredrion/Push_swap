/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:35:13 by gdrion            #+#    #+#             */
/*   Updated: 2019/06/04 16:02:25 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_pile(t_pile *begin)
{
	t_pile *tmp;

	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
}

void		free_hold(t_hold *hold)
{
	free_pile(hold->a);
	free_pile(hold->b);
	hold->a = NULL;
	hold->b = NULL;
	if (hold->com)
		ft_strdel(&(hold->com));
	hold->com = NULL;
	free(hold);
}

t_hold		*create_hold(void)
{
	t_hold *h;

	if (!(h = malloc(sizeof(t_hold))))
		return (NULL);
	h->a = NULL;
	h->b = NULL;
	if (!(h->com = ft_strnew(1)))
		return (NULL);
	h->index = 0;
	h->fd = NULL;
	return (h);
}

static int	add_to_pile(t_hold *hold, char *content)
{
	t_pile		*a;
	intmax_t	tmp;
	t_pile		*save;

	if (!content)
		return (0);
	if (!(a = malloc(sizeof(t_pile))))
		return (0);
	a->next = NULL;
	tmp = ft_atoi(content);
	a->data = tmp;
	if (hold->a == NULL)
	{
		hold->a = a;
		return (1);
	}
	save = hold->a;
	while (save->next)
		save = save->next;
	save->next = a;
	return (1);
}

int			stock_pile(t_hold *hold, char **av)
{
	int		i;

	i = 1;
	if (hold->fd != 0)
		i++;
	if (!(add_to_pile(hold, av[i++])))
		return (0);
	while (av[i])
		if (!(add_to_pile(hold, av[i++])))
			return (0);
	return (1);
}
