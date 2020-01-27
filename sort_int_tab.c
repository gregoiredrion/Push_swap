/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:12:09 by gdrion            #+#    #+#             */
/*   Updated: 2019/06/04 18:34:35 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int		partition(int *tab, int start, int end)
{
	int		pivot;
	size_t	i;
	size_t	left;

	pivot = tab[start];
	left = start;
	i = start + 1;
	while (i < end)
	{
		if (tab[i] < pivot)
			swap(tab + i, &(tab[++left]));
		i++;
	}
	swap(tab + start, tab + left);
	return (left);
}

void			quicksort(int *tab, int start, int end)
{
	int		pi;

	if (start < end)
	{
		pi = partition(tab, start, end);
		quicksort(tab, start, pi);
		quicksort(tab, pi + 1, end);
	}
	return ;
}
