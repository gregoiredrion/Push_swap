/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:26:30 by gdrion            #+#    #+#             */
/*   Updated: 2019/06/05 22:11:30 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		standard_visu(t_hold *h, int max)
{
	if (h->fd != NULL)
		ops_data_fd(h->com, h->a, h->fd);
	if (max != -1)
		ft_putstr(h->com);
	if (h->fd != NULL)
	{
		fclose(h->fd);
		system("python3 ps_visu.py");
	}
	free_hold(h);
	return (0);
}

int		main(int ac, char **av)
{
	t_hold	*h;
	t_hold	*save;
	int		max;
	int		*tab;

	max = 0;
	if (!(h = check_errors(av, ac, 1)))
		return (-1);
	if (sorted(h->a))
		max = 10;
	if (!(save = copy_info(h)))
		return (-1);
	while (++max < 9 && !sort_small(h, 0, max, -1))
	{
		free_hold(h);
		if (!(h = copy_info(save)))
			return (-1);
	}
	free_hold(save);
	if (max == 9)
		while ((max = big_sort(h) == 0))
			;
	return (standard_visu(h, max));
}
