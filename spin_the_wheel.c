/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin_the_wheel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:51:53 by gdrion            #+#    #+#             */
/*   Updated: 2019/05/31 17:21:19 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				pile_len(t_pile *pile)
{
	int len;

	len = 0;
	while (pile)
	{
		pile = pile->next;
		len++;
	}
	return (len);
}

static int		right_side_up(t_pile *pile, int nb, int max)
{
	int count;

	count = 0;
	while (pile && nb < pile->data)
	{
		if (pile->data == max && count)
			return (count);
		pile = pile->next;
		count++;
	}
	return (count);
}

static int		upside_down(t_pile *pile, int nb, int max)
{
	int count;

	count = 0;
	while (pile && nb > pile->data)
	{
		if (pile->data == max)
			return (count);
		pile = pile->next;
		count++;
	}
	if (pile && pile->data == max)
		count += right_side_up(pile->next, nb, max) + 1;
	return (count);
}

int				spin_the_wheel(t_pile *pile, int nb, int max)
{
	int count;

	if (!pile || !pile->next)
		return (0);
	else if (nb > pile->data)
		count = upside_down(pile, nb, max);
	else
		count = right_side_up(pile, nb, max);
	return (count);
}
