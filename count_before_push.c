/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_before_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:41:01 by gdrion            #+#    #+#             */
/*   Updated: 2019/05/31 17:22:06 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		new_is_better(int sav_p, int sav_c, int pos, int count)
{
	int op1;
	int op2;
	int same_sign;

	same_sign = ((pos ^ count) >= 0);
	if (same_sign)
		op1 = (ft_abs(pos) < ft_abs(count)) ? ft_abs(count) : ft_abs(pos);
	else
		op1 = ft_abs(pos) + ft_abs(count);
	same_sign = ((sav_p ^ sav_c) >= 0);
	if (same_sign)
		op2 = (ft_abs(sav_p) < ft_abs(sav_c)) ? ft_abs(sav_c) : ft_abs(sav_p);
	else
		op2 = ft_abs(sav_p) + ft_abs(sav_c);
	return ((op1 < op2) ? 1 : 0);
}

static int		right_count(t_hold *h, int nb, int len_b)
{
	int count;

	count = spin_the_wheel(h->b, nb, h->max);
	return (count > len_b / 2 ? count - len_b : count);
}

static int		choose_rrr_rr(t_hold *h, int pos, int count)
{
	int		loop;
	char	*op1;
	char	*op2;

	if (pos < 0)
	{
		op1 = "rrr";
		op2 = (ft_abs(count) < ft_abs(pos)) ? "rra" : "rrb";
	}
	else
	{
		op1 = "rr";
		op2 = (ft_abs(count) < ft_abs(pos)) ? "ra" : "rb";
	}
	loop = (ft_abs(count) >= ft_abs(pos)) ? ft_abs(pos) : ft_abs(count);
	if (!(op_by_count(h, op1, loop)))
		return (0);
	loop = ft_abs(ft_abs(count) - ft_abs(pos));
	if (!(op_by_count(h, op2, loop)))
		return (0);
	return (1);
}

static int		do_ops_a_b(t_hold *h, int pos, int count)
{
	int same_sign;

	same_sign = ((pos ^ count) >= 0);
	if (!same_sign)
	{
		if (pos < 0)
		{
			if (!(op_by_count(h, "rra", ft_abs(pos))) ||
				!(op_by_count(h, "rb", ft_abs(count))))
				return (0);
		}
		else
		{
			if (!(op_by_count(h, "ra", pos)) ||
				!(op_by_count(h, "rrb", ft_abs(count))))
				return (0);
		}
	}
	else
		choose_rrr_rr(h, pos, count);
	if (h->a->data > h->max)
		h->max = h->a->data;
	if (!(do_and_add("pb", h)))
		return (0);
	return (1);
}

int				get_best_pos(t_hold *h, t_pile *a, int len_b, int len_a)
{
	int	pos;
	int	count;
	int	save_p;
	int	save_c;
	int	new_pos;

	save_p = 0;
	pos = 0;
	if ((save_c = right_count(h, a->data, len_b)) == 0)
		return ((do_ops_a_b(h, save_p, save_c) == 0) ? -1 : 1);
	a = a->next;
	while (a)
	{
		pos++;
		new_pos = (pos > len_a / 2) ? pos - len_a : pos;
		count = right_count(h, a->data, len_b);
		if (new_is_better(save_p, save_c, new_pos, count))
		{
			save_p = new_pos;
			save_c = count;
		}
		a = a->next;
	}
	return ((do_ops_a_b(h, save_p, save_c) == 0) ? 0 : 1);
}
