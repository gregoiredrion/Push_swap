/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:18:22 by gdrion            #+#    #+#             */
/*   Updated: 2019/05/31 17:29:11 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				op_by_count(t_hold *h, char *op, int count)
{
	while (count--)
		if (!(do_and_add(op, h)))
			return (0);
	return (1);
}

static int		find_max(t_pile *pile, int max)
{
	int count;

	count = 0;
	while (pile && pile->data != max)
	{
		count++;
		pile = pile->next;
	}
	return (count);
}

int				fill_a(t_hold *h, int len_b)
{
	int spot;

	spot = find_max(h->b, h->max);
	if (spot <= len_b / 2)
	{
		if (!(op_by_count(h, "rb", spot)))
			return (-1);
	}
	else if (!(op_by_count(h, "rrb", len_b - spot)))
		return (-1);
	while (h->b)
		if (!(do_and_add("pa", h)))
			return (-1);
	return (1);
}

int				big_sort(t_hold *h)
{
	int	len_b;
	int	len_a;
	int	save;

	len_b = pile_len(h->b);
	len_a = pile_len(h->a);
	if (!len_a)
		return (fill_a(h, len_b));
	save = h->a->data;
	if (!len_b)
		h->max = h->a->data;
	if (len_b <= 1)
	{
		if (do_and_add("pb", h) == -1)
			return (-1);
		if (save > h->max)
			h->max = save;
	}
	else if (!(get_best_pos(h, h->a, len_b, len_a)))
		return (-1);
	return (0);
}
