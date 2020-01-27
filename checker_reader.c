/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:50:02 by gdrion            #+#    #+#             */
/*   Updated: 2019/05/17 16:38:44 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_ops(char *op, t_hold *hold)
{
	if (!ft_strcmp(op, "sa"))
		ss(hold, 'a');
	else if (!ft_strcmp(op, "sb"))
		ss(hold, 'b');
	else if (!ft_strcmp(op, "ss"))
		ss(hold, 'c');
	else if (!ft_strcmp(op, "pa"))
		pa(hold);
	else if (!ft_strcmp(op, "pb"))
		pb(hold);
	else if (!ft_strcmp(op, "ra"))
		rr(hold, 'a');
	else if (!ft_strcmp(op, "rb"))
		rr(hold, 'b');
	else if (!ft_strcmp(op, "rr"))
		rr(hold, 'c');
	else if (!ft_strcmp(op, "rra"))
		rrr(hold, 'a');
	else if (!ft_strcmp(op, "rrb"))
		rrr(hold, 'b');
	else if (!ft_strcmp(op, "rrr"))
		rrr(hold, 'c');
	else
		return (0);
	return (1);
}

int	checker_reader(t_hold *hold)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!(do_ops(line, hold)))
		{
			ft_strdel(&line);
			return (free_error(hold));
		}
		ft_strdel(&line);
	}
	if (line)
		ft_strdel(&line);
	return (1);
}
