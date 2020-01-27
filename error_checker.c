/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:26:47 by gdrion            #+#    #+#             */
/*   Updated: 2019/06/17 21:19:44 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_error(char **av, int ac)
{
	if (ac == 1)
		return ;
	if (ac == 2 && (!ft_strcmp(av[1], "-v") ||
	ft_error_pusw(av[1], ft_atoi(av[1]))))
		return ;
	if (ac == 3 && !ft_strcmp(av[1], "-v") &&
	ft_error_pusw(av[2], ft_atoi(av[2])))
		return ;
	write(2, "Error\n", 6);
}

int		sorted(t_pile *pile)
{
	t_pile *actual;
	t_pile *comp;

	actual = pile;
	if (!actual)
		return (0);
	while (actual->next)
	{
		comp = actual->next;
		while (comp)
		{
			if (actual->data >= comp->data)
				return (0);
			comp = comp->next;
		}
		actual = actual->next;
	}
	return (1);
}

int		free_error(t_hold *hold)
{
	write(2, "Error\n", 6);
	free_hold(hold);
	return (0);
}

t_hold	*check_errors(char **av, int ac, int pw)
{
	t_hold	*h;

	if ((pw && (ac < 3 || (ac < 4 && !(ft_strcmp(av[1], "-v"))))) ||
	(pw == 0 && ac < 2))
	{
		small_error(av, ac);
		return (NULL);
	}
	if (!(h = create_hold()))
		return (NULL);
	if (duplicates(av, h, ac, pw) < 1)
	{
		write(2, "Error\n", 6);
		free_hold(h);
		return (NULL);
	}
	if (!(stock_pile(h, av)))
	{
		free_hold(h);
		return (NULL);
	}
	if (pw)
		if (h->fd != 0)
			data_fd(h->a, h->fd);
	return (h);
}
