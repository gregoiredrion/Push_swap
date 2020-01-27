/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:46:23 by gdrion            #+#    #+#             */
/*   Updated: 2019/05/21 02:14:45 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_fd(t_pile *a, FILE *fd)
{
	while (a)
	{
		fprintf(fd, "%d", a->data);
		a = a->next;
		if (a)
			fprintf(fd, " ");
	}
	fprintf(fd, "\n");
}

void	ops_data_fd(char *ops, t_pile *a, FILE *fd)
{
	data_fd(a, fd);
	fprintf(fd, "%s", ops);
}
