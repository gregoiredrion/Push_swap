/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:54:00 by gdrion            #+#    #+#             */
/*   Updated: 2019/04/08 16:12:31 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*sa_sb(t_pile *beginlist, t_hold *h)
{
	t_pile *swap;

	if (!beginlist || !(beginlist->next))
		return (beginlist);
	swap = beginlist->next;
	beginlist->next = swap->next;
	swap->next = beginlist;
	return (swap);
}

void	ss(t_hold *hold, char c)
{
	if (c == 'a' || c == 'c')
		hold->a = sa_sb(hold->a, hold);
	if (c == 'b' || c == 'c')
		hold->b = sa_sb(hold->b, hold);
}

void	pb(t_hold *hold)
{
	t_pile *new_b;

	if (!hold->a)
		return ;
	new_b = hold->a;
	hold->a = hold->a->next;
	new_b->next = hold->b;
	hold->b = new_b;
}

void	pa(t_hold *hold)
{
	t_pile *new_a;

	if (!hold->b)
		return ;
	new_a = hold->b;
	hold->b = hold->b->next;
	new_a->next = hold->a;
	hold->a = new_a;
}
