/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:36:26 by gdrion            #+#    #+#             */
/*   Updated: 2019/06/14 18:17:27 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_hold	*hold;
	int		i;

	i = 1;
	if (!(hold = check_errors(av, ac, 0)))
		return (-1);
	if (!(checker_reader(hold)))
		return (-1);
	if (!sorted(hold->a) || hold->b)
	{
		ft_putstr("KO\n");
		free_hold(hold);
		return (-1);
	}
	else
		ft_putstr("OK\n");
	free_hold(hold);
	return (0);
}
