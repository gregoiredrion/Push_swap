/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:00:52 by gdrion            #+#    #+#             */
/*   Updated: 2019/06/17 21:21:21 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_error_pusw(char *str, intmax_t nb)
{
	int		i;

	i = 0;
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static int		check_range(long nb, char *s, int *tab)
{
	if (!ft_error_pusw(s, nb))
	{
		free(tab);
		return (0);
	}
	return (1);
}

static int		*create_tab(char **av, t_hold *h, int ac)
{
	int		*tab;
	int		i;
	int		j;
	long	save;

	j = 0;
	i = 1;
	if (!(ft_strcmp(av[i], "-v")))
	{
		i++;
		h->fd = fopen("infos.txt", "w");
	}
	if (!(tab = malloc(sizeof(int) * ac)))
		return (NULL);
	while (ac)
	{
		save = atol(av[i]);
		if (!check_range(save, av[i], tab))
			return (NULL);
		tab[j++] = save;
		i++;
		ac--;
	}
	return (tab);
}

int				duplicates(char **av, t_hold *h, int ac, int pw)
{
	int		*tab;
	int		save;

	if (!(ft_strcmp(av[1], "-v")))
		ac--;
	if (pw == 0 && !(ft_strcmp(av[1], "-v")))
		return (-1);
	if (!(tab = create_tab(av, h, --ac)))
		return (-1);
	quicksort(tab, 0, ac);
	ac--;
	save = tab[ac--];
	while (ac >= 0)
	{
		if (save <= tab[ac])
		{
			free(tab);
			return (0);
		}
		save = tab[ac--];
	}
	free(tab);
	return (1);
}
