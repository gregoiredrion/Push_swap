/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:05:58 by gdrion            #+#    #+#             */
/*   Updated: 2019/06/04 20:46:18 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check(t_hold *h, int i, int old_op)
{
	const char	*rop[] = {"sa", "sb", "ss", "pb", "pa", "rra", "rrb", "rrr",
	"ra", "rb", "rr"};
	const char	*op[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
	"rrb", "rrr"};

	if (old_op >= 0 && !ft_strcmp(rop[old_op], op[i]))
		return (0);
	if (i == 0 && (!h->a || !h->a->next))
		return (0);
	if (i == 1 && (!h->b || !h->b->next))
		return (0);
	if (i == 3 && (!h->b))
		return (0);
	if (i == 4 && !h->a)
		return (0);
	if ((i == 5 || i == 8) && (!h->a || !h->a->next))
		return (0);
	if ((i == 6 || i == 9) && (!h->b || !h->b->next))
		return (0);
	return (1);
}

static int	worth(t_hold *h, int count, int max)
{
	t_pile		*tmp;
	int			elements_b;

	tmp = h->b;
	elements_b = 0;
	while (tmp)
	{
		elements_b++;
		tmp = tmp->next;
	}
	if (max - count <= elements_b)
		return (0);
	return (1);
}

int			sort_small(t_hold *h, int count, int max, int old_op)
{
	const char	*op[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
	"rrb", "rrr"};
	const char	*rop[] = {"sa", "sb", "ss", "pb", "pa", "rra", "rrb", "rrr",
	"ra", "rb", "rr"};
	int			i;

	i = -1;
	if (count == max)
		return (0);
	while (++i < 11)
	{
		if (!check(h, i, old_op))
			continue ;
		if (!worth(h, count, max))
			return (0);
		do_and_add((char *)op[i], h);
		if ((sorted(h->a) && !(h->b)) || sort_small(h, ++count, max, i))
			return (1);
		del_command(h);
		do_ops((char *)rop[i], h);
		count--;
	}
	return (0);
}
