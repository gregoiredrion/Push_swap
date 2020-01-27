/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testoper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:28:28 by gdrion            #+#    #+#             */
/*   Updated: 2019/05/17 15:08:44 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*copy_pile(t_pile *stack)
{
	t_pile *new;

	if (!stack)
		return (NULL);
	if (!(new = malloc(sizeof(t_pile))))
		return (NULL);
	new->data = stack->data;
	new->next = NULL;
	return (new);
}

static void		fill(t_pile *tmp, t_pile *new)
{
	while (tmp)
	{
		tmp = tmp->next;
		new->next = copy_pile(tmp);
		new = new->next;
	}
}

t_hold			*copy_info(t_hold *h)
{
	t_hold *ret;
	t_pile *tmp;
	t_pile *new;

	ret = create_hold();
	tmp = h->a;
	ret->fd = h->fd;
	if (!(ret->a = copy_pile(tmp)))
		return (NULL);
	new = ret->a;
	fill(tmp, new);
	tmp = h->b;
	ret->b = copy_pile(tmp);
	new = ret->b;
	fill(tmp, new);
	return (ret);
}
