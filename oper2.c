/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:59:38 by gdrion            #+#    #+#             */
/*   Updated: 2019/05/17 15:10:36 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*rra_rrb(t_pile *pile, t_hold *h)
{
	t_pile	*begin;
	t_pile	*tmp;

	if (!pile || !pile->next)
		return (pile);
	begin = pile;
	tmp = begin->next;
	while (tmp->next)
	{
		begin = tmp;
		tmp = tmp->next;
	}
	tmp->next = pile;
	begin->next = NULL;
	pile = tmp;
	return (pile);
}

void	rrr(t_hold *hold, char c)
{
	if (c == 'a' || c == 'c')
		hold->a = rra_rrb(hold->a, hold);
	if (c == 'b' || c == 'c')
		hold->b = rra_rrb(hold->b, hold);
}

t_pile	*ra_rb(t_pile *pile, t_hold *h)
{
	t_pile *begin;
	t_pile *save;

	if (!pile || !pile->next)
		return (pile);
	begin = pile;
	save = begin;
	while (begin->next)
		begin = begin->next;
	begin->next = save;
	pile = save->next;
	save->next = NULL;
	return (pile);
}

void	rr(t_hold *hold, char c)
{
	if (c == 'a' || c == 'c')
		hold->a = ra_rb(hold->a, hold);
	if (c == 'b' || c == 'c')
		hold->b = ra_rb(hold->b, hold);
}
